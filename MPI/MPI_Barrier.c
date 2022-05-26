#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("I am rank: %d and I am currently waiting on the barrier \n", rank);
    MPI_Barrier(MPI_COMM_WORLD);
    printf("I am rank: %d and I have passed the barrier!\n", rank);
    MPI_Finalize();

    return EXIT_SUCCESS;
}