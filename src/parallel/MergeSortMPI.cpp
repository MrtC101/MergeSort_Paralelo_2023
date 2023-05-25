#include "../common/FileReader.h"
#include "../common/FilePrinter.h"

#include <algorithm>
#include <vector>
#include "mpi.h"
#include <iostream>
using namespace std;

class MergeSort  {
public:
    static vector<int> sort(int argc, char *argv[], vector<int> L)
    {
        int rank, size, n;
        vector<int> *subL; // Parte del vector

        MPI_Init(&argc, &argv);               // Iniciamos el entorno MPI
        MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtenemos el identificador del proceso
        MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtenemos el numero de procesos

        if (size % 2 != 0)
        { // El numero de procesos debe ser par para aplicar este algoritmo
            cout << "El numero de procesos debe ser par" << endl;
            MPI_Abort(MPI_COMM_WORLD, 1); // Abandonamos la ejecucion.
        }

        if (argc < 2)
        {
            if (rank == 0) {
                cout << "No recibio parametro con el tamaño de vector, por defecto sera 1000" << endl;
            }
            n = 1000;
        }
        else
        {
            n = atoi(argv[1]);
        }

        if (rank == 0)
        { // El proceso 0 genera un vector desordenado.
            for (int i = 0; i < n; ++i)
            {
                L.push_back(rand() % 1000);
            }
        }
        subL = new vector<int>(n / size); // Reservamos espacio para el vector local a cada proceso.

        // Repartimos el vector entre todos los procesos.
        MPI_Scatter(&L[0], n / size, MPI_INT, &((*subL)[0]), n / size, MPI_INT, 0, MPI_COMM_WORLD);

        // Cada proceso ordena su parte.
        std::sort(subL->begin(), subL->end());

        vector<int> *sorted;
        MPI_Status status;
        int step = 1;

        // Ahora comienza el proceso de mezcla.
        while (step < size)
        {
            // Cada pareja de procesos
            if (rank % (2 * step) == 0)
            {                           // El izquierdo recibe el vector y mezcla
                if (rank + step < size) // Los procesos sin pareja esperan.
                {
                    vector<int> localVecino(subL->size());
                    sorted = new vector<int>(subL->size() * 2);

                    MPI_Recv(&localVecino[0], localVecino.size(), MPI_INT, rank + step, 0, MPI_COMM_WORLD, &status);
                    std::merge(
                        subL->begin(), subL->end(),
                        localVecino.begin(), localVecino.end(),
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

        if (rank == 0)
        {
            result = *subL;
        }

        MPI_Finalize();

        return result;
    }
};

int main(int argc, char *argv[])
{
    std::string path = "../../data/input.data";
    FileReader input(path);
    FilePrinter output;

    std::vector<int> L;

    vector<int> sortedVector = MergeSort::sort(argc, argv, L);

    if (sortedVector.empty())
    {
        cout << "No se encontró un vector ordenado" << endl;
    }
    else
    {
        cout << "Vector ordenado: [";
        for (unsigned int i = 0; i < sortedVector.size(); ++i)
        {
            cout << sortedVector[i] << " , ";
        }
        cout << "]" << endl;
    }

    return 0;
}