#include<stdio.h> 
#include<mpi.h> 
#include<stdlib.h> 

// to compile: mpic++ -o mpi mpi.cpp -lm -std=c99 -Wall && mpiexec -n 4 ./mpi && rm mpi
// crux of the code is the MPI_Send and MPI_Recv functions
/*
number of processes: 2  
// first root process prints the comm_size = np 
...LAPTOP-91GF7QR: Hello world from process 0 
Process:0 is sending '10' to process:1 
// root process sends a message to process 1
LAPTOP-91GF7QR: Hello world from process 1 
Process:1 is has received '10' from process:0
// and next process 1 receives the message
*/
// WHY IS TAG USED AND WHY IS IT SET TO 1? the tag is used to identify the message, it is set to 1 to identify the message

int main(int argc, char* argv[])
{
	int myid, numprocs, namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc, &argv);        // starts MPI
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);  // get current process id
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);      // get number of processeser
	MPI_Get_processor_name(processor_name, &namelen);

	if (myid == 0) 
		printf("number of processes: %d\n...", numprocs);
	printf("%s: Hello world from process %d \n", processor_name, myid);


	if (myid== 0) {
		int sendBuff = 10, tag = 1, dest = 1;
		printf("Process:%d is sending \'%d\' to process:%d \n", myid, sendBuff, dest);

		MPI_Send(&sendBuff, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);

	}
	else if (myid == 1) {
		int recvBuff; int source = 0, tag = 1;
		MPI_Status status;
		MPI_Recv(&recvBuff, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
		printf("Process:%d is has received \'%d\' from process:%d\n", myid, recvBuff, source);

	}
	else {
	}



	MPI_Finalize();

	return 0;
}