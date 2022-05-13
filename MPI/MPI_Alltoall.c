#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>


int main(int argc, char **argv)
{
    int rank, size, value;
    int my_values[size];
    int buffer[size];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (size < 2 || size > 4)
    {
        printf("Please enter a number of proccessors 2-4 processors");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);

    }

    for (int i = 0; i < size; i++)
    {
        my_values[i] = rand() % rank;
        printf("rank: %d index of my_values: %d value at index: %d\n", rank, i, my_values[i]);
    }
    MPI_Barrier(MPI_COMM_WORLD);


    MPI_Alltoall(&my_values, 1, MPI_INT, buffer, 1, MPI_INT, MPI_COMM_WORLD);
    
    for (int i = 0; i < size; i++)
    {
        printf("Rank: %d Index: %d Value: %d \n", rank, i, my_values[i]);
    }
    MPI_Finalize();

    return EXIT_SUCCESS;

}