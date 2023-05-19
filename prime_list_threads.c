#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

unsigned int thread_offsets[24];
unsigned int batch_s;
int running_threads = 0;




static void
prime_test(int *thread_num){
printf("new thready %d\n", *thread_num);
	unsigned i,j;
	i = thread_offsets[*thread_num];
	for(;i<batch_s;i++){
		for(j=2;j<i;j++){
			if(i%j == 0){
printf("%d %d\n",i, j);
				goto NOPE;
			}
		}
		printf("%08X\n",i);
NOPE:
	continue;
	}
	running_threads--;
}

int
main(int argc, char** argv){

	if(argc < 4){
		printf("Use: ./primer START BATCH_SIZE THREADS\n");
	}

	unsigned int last_prime = atoi(argv[1]);
	int batch_s = atoi(argv[2]);
	int threads = atoi(argv[3]);

	unsigned int count = 0xffffffff;

printf("fingers crossed %d %d %d\n", last_prime, batch_s, threads);
	memset(thread_offsets,last_prime,threads);



	pthread_t ttt[threads];

	unsigned int i,j,k;
	while(1){
		if(running_threads == threads){
			sleep(5);
			continue;
		}	
		unsigned int mybatch = last_prime;	
		unsigned i = 0;
		for(i=0; i<threads; i++){
			if(thread_offsets[i] < mybatch){
				mybatch = thread_offsets[i] + batch_s;
			}
		}


		running_threads++;
		pthread_create(&(ttt[running_threads]),NULL,(void*)&prime_test,&i);

	}	
	return 1;
}
