#include "../common/FileReader.h"
#include "../common/FilePrinter.h"

#include <algorithm>
#include <vector>
#include <mpi.h>
#include <iostream>
#include <chrono>

void mergeSort(std::vector<int> &subL, int rank, int size) {
    // Cada proceso ordena su parte.
    std::sort(subL.begin(), subL.end());

    std::vector<int> sorted;
    MPI_Status status;
    int step = 1;
    std::cout << rank << std::endl;
    // Proceso de mezcla.
    while (step < size)
    {
        // Cada pareja de procesos
        if (rank % (2 * step) == 0)
        {                           // El izquierdo recibe el vector y mezcla
            if (rank + step < size) // Los procesos sin pareja esperan.
            {
                std::vector<int> localNeighb(subL.size());
                std::vector<int> sorted(subL.size() * 2);

                std::cout << "prerecv" << std::endl;
                MPI_Recv(&localNeighb[0], localNeighb.size(), MPI_INT, rank + step, 0, MPI_COMM_WORLD, &status);
                std::merge(
                    subL.begin(), subL.end(),
                    localNeighb.begin(), localNeighb.end(),
                    sorted.begin());

                subL = sorted;
                sorted.clear();
            }
        }
        else
        {
            // El derecho envia su vector ordenado y termina
            int nbr = rank - step;
            std::cout << "presend" << std::endl;
            MPI_Send(&subL[0], subL.size(), MPI_INT, nbr, 0, MPI_COMM_WORLD);
            break; // Sale del bucle
        }
        step = step * 2; // El paso se duplica ya que el numero de procesos se reduce a la mitad.
    }
}

int main(int argc, char *argv[])
{
    int rank, size;
    int chunk_size;
    int end_file;
    //bool end_file;
    std::vector<int> global; // Vector a ordenar

    MPI_Init(&argc, &argv);               // iniciamos el entorno MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // obtenemos el identificador del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size); // obtenemos el numero de procesos

    if (size % 2 != 0)
    { // El numero de procesos deberia debe ser par para aplicar este algoritmo
        std::cout << "El numero de procesos debe ser par" << std::endl;
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE); // abandonamos la ejecucion.
    }

    if (rank == 0) {
        std::string path = "../../data/input.data";
        FileReader input(path);
        FilePrinter output;
        FilePrinter ordered("ordered.data");

        input.get_vector(global);
        end_file = global.empty();
        //for (int i = 1; i < size; ++i) {
        //    MPI_Send(&end_file, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        //}
        MPI_Bcast(&end_file, 1, MPI_INT, 0, MPI_COMM_WORLD);

        while (!end_file) {
            chunk_size = global.size() / size;
            for (int i = 1; i < size; ++i) {
                MPI_Send(&chunk_size, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            }
            //MPI_Bcast(&chunk_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
            std::vector<int> subL(chunk_size);

            //subL = new vector<int>(chunk_size);
            MPI_Scatter(&global[0], chunk_size, MPI_INT, &subL[0], chunk_size, MPI_INT, 0, MPI_COMM_WORLD);

            auto start = std::chrono::system_clock::now();

            std::vector<int> sortedVector(subL);
            mergeSort(subL, rank, size);
            auto end = std::chrono::system_clock::now();
            std::chrono::duration<float, std::milli> duration = end - start;

            std::cout << "pregather" << std::endl;
            //MPI_Gather(&sortedVector[0], chunk_size, MPI_INT, &global[0], chunk_size, MPI_INT, 0, MPI_COMM_WORLD);

            // write in file
            output.save(sortedVector.size(), 1, duration.count());
            ordered.save_list(subL);
            global.clear();
            input.get_vector(global);

            end_file = global.empty();

            for (int i = 1; i < size; ++i) {
                MPI_Send(&end_file, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            }
            //MPI_Bcast(&end_file, 1, MPI_INT, 0, MPI_COMM_WORLD);
        }
        output.end_write();
    }
    else {
        //MPI_Recv(&end_file, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Bcast(&end_file, 1, MPI_INT, 0, MPI_COMM_WORLD);

        while (!end_file) {
            MPI_Recv(&chunk_size, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            //MPI_Bcast(&chunk_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
            std::vector<int> subL(chunk_size);

            MPI_Scatter(&global[0], chunk_size, MPI_INT, &subL[0], chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
            mergeSort(subL, rank, size);

            std::cout << "pregather" << std::endl;
            //MPI_Gather(&subL[0], chunk_size, MPI_INT, NULL, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
            MPI_Recv(&end_file, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            //MPI_Bcast(&end_file, 1, MPI_INT, 0, MPI_COMM_WORLD);
        }
    }
    MPI_Finalize();
}
