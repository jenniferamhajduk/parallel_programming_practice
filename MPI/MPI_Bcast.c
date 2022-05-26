#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int rank, buffer;
    int broadcast_root = 0;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == broadcast_root)
    {
        buffer = rand() % rank;
        printf("I am rank: %d, and I am the broadcast root. My buffer value is: %d\n", rank, buffer);
    }

    MPI_Bcast(&buffer, 1, MPI_INT, broadcast_root, MPI_COMM_WORLD);

    if (rank != broadcast_root)
    {
        printf("I am rank: %d and I received the value: %d from the broadcast root: %d\n", rank, buffer, broadcast_root);
    }
    MPI_Finalize();
    
    return EXIT_SUCCESS;
}