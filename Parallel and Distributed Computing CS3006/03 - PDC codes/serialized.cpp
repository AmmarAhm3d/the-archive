#include <mpi.h>
#include <omp.h>
#include <stdio.h>

// to compile and run, then delete the executable mpic++ serialized.cpp -fopenmp -o serialized && mpirun -np 4 ./serialized && rm serialized

// this program has a similar structure to hybrid_multiple_support_sendRecv.c, but the difference is that the MPI_Init_thread function is called with MPI_THREAD_SERIALIZED
// the code does not work with any number of threads other than 2, otherwise the program will hang
// oh and the putput is same as the c version of program
// now i will zip the folder and submit it
// cd .. && zip -r PDC_prep.zip 'PDC prep'
int main(int argc, char* argv[])
{
	int errs = 0;
	int provided, flag, claimed;

	int i, j, k, tid, element;
	int sendbuff[4];
	int recvbuff[4] = { 0 };
	MPI_Init_thread(&argc, &argv, MPI_THREAD_SERIALIZED, &provided);
	MPI_Status status;

	printf("requested was:%d   and received is :%d\n",MPI_THREAD_MULTIPLE, provided);


	int P;
	MPI_Comm_size(MPI_COMM_WORLD, &P);

	// Get the rank of the process
	int process_id;
	MPI_Comm_rank(MPI_COMM_WORLD, &process_id);


	omp_set_dynamic(0);
	omp_set_num_threads(2);
	if (process_id == 0) {

#pragma omp single
		for (i = 0; i < P; i++) {

			sendbuff[i] = (i + 1) * 2; //2 4  				
		}

#pragma omp parallel private(tid,element)
		{
			tid = omp_get_thread_num();
			element = sendbuff[tid];
			if (tid == 0) {
				MPI_Send(&element, 1, MPI_INT, 1, tid, MPI_COMM_WORLD);
			}
#pragma omp barrier
			if (tid == 1) {
				MPI_Send(&element, 1, MPI_INT, 1, tid, MPI_COMM_WORLD);
			}
		}

	}
	else {

#pragma omp parallel private(tid)
		{
			tid = omp_get_thread_num();
			printf("receiveing thread#%d\n ",tid);
			if (tid == 0) {
				MPI_Recv(&recvbuff[tid], 1, MPI_INT, 0, tid, MPI_COMM_WORLD, &status);	 //tad=tid--> receive msg from 0 with tag equal to my threadId

			}
#pragma omp barrier
			if (tid == 1) {
				MPI_Recv(&recvbuff[tid], 1, MPI_INT, 0, tid, MPI_COMM_WORLD, &status);	 //tad=tid--> receive msg from 0 with tag equal to my threadId
			}

		}

	}



	if (process_id == P - 1) {
		printf("recvbuff=");
		for (i = 0; i < P; i++) {
			printf("%d\t", recvbuff[i]);
		}
		printf("\n");

	}


	MPI_Finalize();
	return errs;
}