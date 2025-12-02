/*

#include<stdio.h> 
#include<mpi.h> 
#include<stdlib.h> 
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
}*/