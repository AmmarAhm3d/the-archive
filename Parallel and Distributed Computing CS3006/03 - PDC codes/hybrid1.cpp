#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>

// to comp and run, then delete the executable
// mpic++ hybrid1.cpp -fopenmp -o hybrid1 && mpirun -np 4 ./hybrid1 && rm hybrid1
// crux of the program is to show how multiple threads can be used in a hybrid MPI+OpenMP program
// each process prints the thread id, number of threads, and processor name
// if the program is run with 2 processes, get_num_procs() will return 2, and 2 threads will be created
// AND WHY 2 AGAIN WITH 4 PROCESSES? 
// Within each MPI process, you're creating 2 OpenMP threads (`omp_set_num_threads(omp_get_num_procs());`). Each thread has a unique ID, which is either 0 or 1 (`thread_id = omp_get_thread_num();`).
/*
From Process#0 thread_id 0 out of 2 mapped on  processor:LAPTOP-91GF7QR  Hello Hybrid
From Process#0 thread_id 1 out of 2 mapped on  processor:LAPTOP-91GF7QR  Hello Hybrid
From Process#1 thread_id 0 out of 2 mapped on  processor:LAPTOP-91GF7QR  Hello Hybrid
From Process#1 thread_id 1 out of 2 mapped on  processor:LAPTOP-91GF7QR  Hello Hybrid
*/

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    int P, name_len;
    MPI_Comm_size(MPI_COMM_WORLD, &P);
    int process_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Get_processor_name(processor_name, &name_len);
    omp_set_dynamic(0);
    omp_set_num_threads(omp_get_num_procs());
    int thread_id;
#pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num();
        printf("From Process#%d thread_id %d out of %d mapped on  processor:%s  Hello Hybrid\n", process_id, thread_id, omp_get_num_threads(), processor_name);
    }

    MPI_Finalize();

}
