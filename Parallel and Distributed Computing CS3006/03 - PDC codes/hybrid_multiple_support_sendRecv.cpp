//implementing simple onetoall broadcast for n=4 and using multiple threads

#include <mpi.h>
#include <omp.h>
#include <stdio.h>

// to compile and run, then delete the executable
// mpic++ hybrid_multiple_support_sendRecv.cpp -fopenmp -o hybrid_multiple_support_sendRecv && mpirun -np 4 ./hybrid_multiple_support_sendRecv && rm hybrid_multiple_support_sendRecv
// yep explanation is same as in the .c version

int main(int argc, char* argv[])
{
	int errs = 0;
	int provided, flag, claimed;

	int i, j, k, tid, element;
	int sendbuff[4];


	int recvbuff[4] = { 0 };
	MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
	MPI_Status status;

	//printf("requested was:%d   and received is :%d\n",MPI_THREAD_MULTIPLE, provided);


	int P;
	MPI_Comm_size(MPI_COMM_WORLD, &P);

	// Get the rank of the process
	int process_id;
	MPI_Comm_rank(MPI_COMM_WORLD, &process_id);


	omp_set_dynamic(0);
	omp_set_num_threads(4);
	if (process_id == 0) {

#pragma omp single
		for (i = 0; i < 4; i++) {

			sendbuff[i] = (i + 1) * 2; //2 4 6 8  				
		} //implicit barrier here

#pragma omp parallel private(tid)
		{
			tid = omp_get_thread_num();
			//	printf("send thread#%d\n ",tid);

#pragma omp for private(i,j,element)
			for (i = 0; i < 4; i++) { //each thread will send a single value of the buffer to other processes
				element = sendbuff[tid];
				for (j = 1; j < P; j++) {
					printf("process_id:%d-->thread#%d is sending %d to process %d\n ", process_id, tid, element, j);
					MPI_Send(&element, 1, MPI_INT, j, tid, MPI_COMM_WORLD); //label=tid

				}
			}
		}

	}
	else {

#pragma omp parallel private(tid)
		{
			tid = omp_get_thread_num();
			//printf("receiveing thread#%d\n ",tid);

#pragma omp for private(i,j)
			for (i = 0; i < 4; i++) { //foreach value of input buffer
				MPI_Recv(&recvbuff[tid], 1, MPI_INT, 0, tid, MPI_COMM_WORLD, &status);	 //tad=tid--> receive msg from 0 with tag equal to my threadId
				printf("process-id:%d Received %d from thread#%d of source\n", process_id, recvbuff[i], tid);
			}
		}


	}


	if (process_id == P - 1) {
		printf("recvbuff=");
		for (i = 0; i < 4; i++) {
			printf("%d\t", recvbuff[i]);
		}
		printf("\n");

	}


	MPI_Finalize();
	return errs;
}
