//////////FileReadWriteAt.c
//
//
#include <stdio.h>
#include "mpi.h"

#define LEN 20

int main(int argc, char **argv) {
	int rank, size;
	int bstart, sharelen;
	MPI_Offset fstart;
	int  i, a[LEN], b[LEN];
	int rd, num;
	
	MPI_File fh0;
	
	MPI_Status status;
	FILE *fw;
	char fwn[512];
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	if(LEN % size != 0) {
		printf("LEN=%d, should be divided by size=%d\n", LEN, size);
		MPI_Finalize();
		exit(0);
	}	

	for ( i=0;i<LEN;i++) {
		a[i] = rank ; 
		b[i] = -111;
	}
	sharelen = LEN / size;
	bstart = rank * sharelen;
	fstart = bstart * sizeof(int);
	printf("Proc:%d sharedlen=%d, bstart=%d, fstart=%ld\n", rank, sharelen, bstart, fstart);

	//add explicit write code here
	//

	//add explicit read code here
	//

	sprintf(fwn, "W:\\temp\\inteltraining\\examples\\projects\\Debug\\fw.%d", rank);
	fw = fopen(fwn, "w");
	for(i = 0; i < LEN; i++) {
		fprintf(fw, "b[%d] = %d\n", i, b[i]);
	}
	fclose(fw);

	MPI_Finalize();
	return 0;
}