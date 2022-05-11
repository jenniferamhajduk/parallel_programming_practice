#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    // Initialize the MPI environment
    int root = 0;
    int rank, size;
    int reduction = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int myNum = rand() % rank;
    printf("\nMy rank is: %d and my nymber is: %d\n", rank, myNum);

    MPI_Barrier(MPI_COMM_WORLD);
    //Print inital reduction
    if (rank == root)
    {
        printf("T\nhe initial reduction is: %d\n", reduction);
    }
    
    //Initialize the reduction variable
    MPI_Reduce(&myNum, &reduction, 1, MPI_INT, MPI_SUM, root, MPI_COMM_WORLD);

    //Print out the result
    if (rank == 0)
    {
        printf("The final reduction of all of the process' ranks is: %d\n", reduction);
    }

    MPI_Finalize();
}