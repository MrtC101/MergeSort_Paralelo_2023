#include "../common/FileReader.h"
#include "../common/FilePrinter.h"

#include <algorithm>
#include <vector>
#include <mpi.h>
#include <iostream>
#include <chrono>

using namespace std;

vector<int> mergeSort(vector<int> *subL, int rank, int size) {
    // Cada proceso ordena su parte.
    std::sort(subL->begin(), subL->end());

    vector<int> *sorted;
    MPI_Status status;
    int step = 1;

    // Proceso de mezcla.
    while (step < size)
    {
        // Cada pareja de procesos
        if (rank % (2 * step) == 0)
        {                           // El izquierdo recibe el vector y mezcla
            if (rank + step < size) // Los procesos sin pareja esperan.
            {
                vector<int> localNeighb(subL->size());
                sorted = new vector<int>(subL->size() * 2);

                MPI_Recv(&localNeighb[0], localNeighb.size(), MPI_INT, rank + step, 0, MPI_COMM_WORLD, &status);
                std::merge(
                    subL->begin(), subL->end(),
                    localNeighb.begin(), localNeighb.end(),
                    sorted->begin());

                delete subL;
                subL = sorted;
                sorted = NULL;
            }
        }
        else
        {
            // El derecho envia su vector ordenado y termina
            int nbr = rank - step;
            MPI_Send(&((*subL)[0]), subL->size(), MPI_INT, nbr, 0, MPI_COMM_WORLD);
            break; // Sale del bucle
        }
        step = step * 2; // El paso se duplica ya que el numero de procesos se reduce a la mitad.
    }
    vector<int> result;
    result = *subL;
    return result;
        
}

int main(int argc, char *argv[])
{
    int rank, size;
    vector<int> Global; // Vector a ordenar
    vector<int> *Local; // parte del vector

    MPI_Init(&argc, &argv);               // iniciamos el entorno MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // obtenemos el identificador del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size); // obtenemos el numero de procesos

    if (size % 2 != 0)
    { // El numero de procesos deberia debe ser par para aplicar este algoritmo
                cout
            << "El numero de procesos debe ser par" << endl;
        MPI_Abort(MPI_COMM_WORLD, 1); // abandonamos la ejecucion.
    }
    FileReader input;
    FilePrinter output;
    if (rank == 0)
    { // el proceso 0 genera un vector desordenado.
        std::string path = "../../data/input.data";
        
        input.setPath(path);
        input.get_vector(Global);
    }
    vector<int> *subL; // Parte del vector
    int n;
    while (!(Global.empty()))
    {
        n = Global.size();
        subL = new vector<int>(n / size);
        MPI_Scatter(&Global[0], Global.size() / size, MPI_INT, &subL[0], Global.size() / size, MPI_INT, 0, MPI_COMM_WORLD);
        if (rank==0) {
            auto start = std::chrono::system_clock::now();
            vector<int> sortedVector = mergeSort(subL, rank, size);
            auto end = std::chrono::system_clock::now();
            std::chrono::duration<float, std::milli> duration = end - start;

            // write in file
            output.save(sortedVector.size(), 1, duration.count());
            Global.clear();
            input.get_vector(Global);
        }
        else {
            mergeSort(subL, rank, size);
        }
             
    }
    output.end_write();

    MPI_Finalize();
}