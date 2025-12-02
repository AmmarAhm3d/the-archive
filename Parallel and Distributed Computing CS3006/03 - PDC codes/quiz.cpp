#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MAX_SIZE 10

// to compile: mpic++ -o quiz quiz.cpp -lm -std=c99 -Wall && mpiexec -n 6 ./quiz && rm quiz
// this program was run with 6 processes meaning that size = 6
// MPI_Reduce is used to calculate the product of all numbers from 1 to size, this is done by multiplying the local_data of each process
// local data is made up of
// rank = 0, local_data = 1
// rank = 1, local_data = 2
// rank = 2, local_data = 3
// rank = 3, local_data = 4
// rank = 4, local_data = 5
// rank = 5, local_data = 6
// the global product is hence 720 (1*2*3*4*5*6)
// MPI_Scan is used to calculate the partial product of all numbers from 1 to size, this is done by multiplying the local_data of each process
// the partial products are then gathered using MPI_GATHER into the all_partial_prods array
// the output is then printed at each process, this means that
// process 0: 1 (1)
// process 1: 2 (1*2)
// process 2: 6 (1*2*3)
// process 3: 24 (1*2*3*4)
// process 4: 120 (1*2*3*4*5)
// process 5: 720 (1*2*3*4*5*6)

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_data = rank + 1;
    int global_prod, partial_prod;

    MPI_Reduce(&local_data, &global_prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);

    MPI_Scan(&local_data, &partial_prod, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);

    int all_partial_prods[MAX_SIZE];
    int recvcounts[MAX_SIZE];
    int displs[MAX_SIZE];
    MPI_Gather(&partial_prod, 1, MPI_INT, all_partial_prods, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Output Question: What is the total product of numbers from 1 to %d across all processes?\n", size);
        printf("Global product (MPI_Reduce): %d\n", global_prod);
        printf("Partial products (MPI_Scan):\n");
        for (int i = 0; i < size; i++) {
            printf("Process %d: %d\n", i, all_partial_prods[i]);
        }
    }
    MPI_Finalize();
    return 0;
}
