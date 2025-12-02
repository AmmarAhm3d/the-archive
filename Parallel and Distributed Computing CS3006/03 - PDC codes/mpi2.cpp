#include<stdio.h> 
#include<mpi.h> 
#include<stdlib.h> 

// to compile: mpic++ -o mpi mpi2.cpp -lm -std=c99 -Wall && mpiexec -n 4 ./mpi && rm mpi

// what is going on with ? and : in the line below?
// the line below is a ternary operator, it is a shorthand for an if else statement
// so if my_rank is 0, then buffer_send is 12345, else buffer_send is 67890
// peer is the other process, so if my_rank is 0, then peer is 1, else peer is 0
// about the arguements passed to mpi_sendrecv, the first 3 are the same as mpi_send
// the next 3 are the same as mpi_recv
/*
MPI process 0 sends value 12345 to MPI process 1.       > MPI_Send is called by process 0 with value 12345
MPI process 1 sends value 67890 to MPI process 0.       > MPI_Send is called by process 1 with value 67890
MPI process 0 received value 67890 from MPI process 1.  > MPI_Recv is called by process 0 and receives 67890
MPI process 1 received value 12345 from MPI process 0.  > MPI_Recv is called by process 1 and receives 12345
*/

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    // Make sure exactly 2 MPI processes are used
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size != 2)
    {
        printf("%d MPI processes used, please use 2.\n", size);
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    // Prepare parameters
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int buffer_send = (my_rank == 0) ? 12345 : 67890;
    int buffer_recv;
    int tag_send = 0;
    int tag_recv = tag_send;
    int peer = (my_rank == 0) ? 1 : 0;

    // Issue the send + receive at the same time
    printf("MPI process %d sends value %d to MPI process %d.\n", my_rank, buffer_send, peer);
    MPI_Sendrecv(&buffer_send, 1, MPI_INT, peer, tag_send,
        &buffer_recv, 1, MPI_INT, peer, tag_recv, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("MPI process %d received value %d from MPI process %d.\n", my_rank, buffer_recv, peer);

    MPI_Finalize();

    return EXIT_SUCCESS;
}