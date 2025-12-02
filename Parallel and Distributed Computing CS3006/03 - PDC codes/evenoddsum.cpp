#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// to comp and run, then delete the executable
// mpic++ evenoddsum.cpp -o evenoddsum && mpirun -np 4 ./evenoddsum && rm evenoddsum

// crux of the program is to show how to use MPI_Bcast and MPI_Reduce functions
// MPI_Bcast is used to broadcast a value from the root processor to all other processors
// MPI_Reduce is used to reduce the values from all processors to a single value on the root processor
/*process 1: Before MPI_Bcast, value is 0 > first processor prints the value before MPI_Bcast
process 1: After MPI_Bcast, value is 10   > next processor prints the value after MPI_Bcast, whiich is received from the root processor
Local sum for process 1 - 15.000000, avg = 3.000000
                                          > each processor calculates the sum of the values in the array
                                          > avg is calculated by = 15/5 = 3 (size is default 1)
process 0: After MPI_Bcast, value is 10   > root process finishes its broadcast
Local sum for process 0 - 0.000000, avg = 0.000000
                                          > since this is the root processor, it does not calculate the sum of the values in the array
Total sum = 0.000000, avg = 0.000000
*/
int main(int argc, char* argv[]){

    int rank, value = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); //what rank is the current processor
    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    
    if (rank == 0) { // root processor sets the value to 10
        value = 10;
    }
    else {
        printf("process %d: Before MPI_Bcast, value is %d\n", rank, value);
    }

    // each processor calls MPI_Bcast, data is broadcast from root processor and ends up in everyone value variable
    // root process uses MPI_Bcast to broadcast the value, each other process uses MPI_Bcast to receive the broadcast value
    MPI_Bcast(&value, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("process %d: After MPI_Bcast, value is %d\n", rank, value);
    
    //////////////////////
    /// ALL to one REDUCE

    
    
    // Sum the numbers locally
    float local_sum = 0;
    const int num_elem = 5;
    float rand_nums[num_elem] = {rank*1.0, rank*2.0, rank*3.0, rank*4.0, rank*5.0};

    for (int i = 0; i < num_elem; i++) {
        local_sum += rand_nums[i];
    }

    // Print the random numbers on each process
    printf("Local sum for process %d - %f, avg = %f\n",
        rank, local_sum, local_sum / num_elem);

    // Reduce all of the local sums into the global sum
    float global_sum;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_FLOAT, MPI_PROD, 0,
        MPI_COMM_WORLD);

    // Print the result
    if (rank == 0) {
        printf("Total sum = %f, avg = %f\n", global_sum,
            global_sum / (size * num_elem));
    }

    
    MPI_Finalize();

    return 0;
}