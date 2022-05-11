#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


int main(int argc, char **argv)
{
    int size, rank, myValue, buffer[size];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (size < 2 || size > 4)
    {
        printf("The size must be between two and four processes, inclusive");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    myValue = rand() % rank;
    printf("Processor: %d \t myValue: %d\n", rank, myValue);

    MPI_Allgather(&myValue, 1, MPI_INT, buffer, 1, MPI_INT, MPI_COMM_WORLD);

    for (int i = 0; i < size; i++)
    {
        printf("Rank: %d Buffer: %d\n", rank, buffer[i]);
    }

    MPI_Finalize();
    return EXIT_SUCCESS;
}