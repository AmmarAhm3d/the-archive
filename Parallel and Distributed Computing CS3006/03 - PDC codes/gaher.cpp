#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// to comp and run, then delete the executable
// mpic++ gaher.cpp -o gaher && mpirun -np 3 ./gaher && rm gaher

// crux of the program is to show how to use MPI_Gatherv function
// MPI_Gatherv is used to gather values from all processors to a single processor, root processor
// it takes in a sendbuf from each process here, and gathers them in a buffer on the root processor
// recv count is the number of elements to be received from each process, rank 0 receives 1 element, rank 1 receives 1 element, rank 2 receives 2 elements
// displacements is the offset in the recvbuf where the data from each process is to be stored, rank 0 stores at 0, rank 1 stores at 3, rank 2 stores at 5
// WHY IS THE BUFFER size 7? because rank 0 sends 1 element, rank 1 sends 1 element, rank 2 sends 2 elements, so 4 elements are sent in total
// AND WHY ARE NULLS PUT IN 1 and 2 RANKS IN MPI_Gatherv? because they are not sending any data, so they can put NULLs in the function
/*
Process 0, my value = 100.      > root processor prints its value
Process 1, my value = 101.      > next processor prints its value
Process 2, my values = 102 103. > last processor prints its values
Values gathered in the buffer on process 0: 100 0 0 101 0 102 103
                                              0 1 2   3 4   5   6
- `100` is the value sent by process 0, placed at position 0 in the buffer.
- `0 0` are the default values at positions 1 and 2 in the buffer, which were not filled by any process.
- `101` is the value sent by process 1, placed at position 3 in the buffer.
- `0` is the default value at position 4 in the buffer, which was not filled by any process.
- `102 103` are the values sent by process 2, placed starting at position 5 in the buffer.

The `calloc` function is used to initialize the buffer with zeros, which is why the unfilled positions contain zeros.
*/

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size != 3)
    {
        printf("This application is meant to be run with 3 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
    }

    // Get my rank
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // Determine root's process rank
    int root_rank = 0;

    switch (my_rank)
    {
    case 0:
    {
        int my_value = 100;

        int counts[3] = { 1, 1, 2 };

        int displacements[3] = { 0, 3, 5 };

        int* buffer = (int*)calloc(7, sizeof(int));
        printf("Process %d, my value = %d.\n", my_rank, my_value);
        MPI_Gatherv(&my_value, 1, MPI_INT, buffer, counts, displacements, MPI_INT, root_rank, MPI_COMM_WORLD);
        printf("Values gathered in the buffer on process %d:", my_rank);
        for (int i = 0; i < 7; i++)
        {
            printf(" %d", buffer[i]);
        }
        printf("\n");
        free(buffer);
        break;
    }
    case 1:
    {
        int my_value = 101;

        printf("Process %d, my value = %d.\n", my_rank, my_value);
        MPI_Gatherv(&my_value, 1, MPI_INT, NULL, NULL, NULL, MPI_INT, root_rank, MPI_COMM_WORLD);
        break;
    }
    case 2:
    {
        int my_values[2] = { 102, 103 };

        printf("Process %d, my values = %d %d.\n", my_rank, my_values[0], my_values[1]);
        MPI_Gatherv(my_values, 2, MPI_INT, NULL, NULL, NULL, MPI_INT, root_rank, MPI_COMM_WORLD);
        break;
    }
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}