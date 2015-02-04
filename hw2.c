#include <time.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BILLION 1000000000L

int main(int argc, char const *argv[])
{
	struct timespec start, end;
	uint64_t diff;

	clock_gettime(CLOCK_MONOTONIC, &start);
	printf("lets see how long it takes to do a simple printf fucntion\n");
	clock_gettime(CLOCK_MONOTONIC, &end);

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

	printf("elapsed time = %11u nanoseconds\n", (long long unsigned int) diff);
	
	return 0;
}