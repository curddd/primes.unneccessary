#include <stdio.h>
#include <stdlib.h>

#define PRIME_FILE "32bit_primes"
#define PRIMES_RANGE 0xfffffff

unsigned int primes_ram[PRIMES_RANGE];
unsigned int pc;

FILE *known_primes;

void
load_primes_into_ram(){
	
	known_primes = fopen(PRIME_FILE, "r");
	
	int prime;
	char *line = NULL;
	size_t linesize = 0;
	ssize_t linelen;
	pc = 0;
	while((linelen = getline(&line, &linesize, known_primes)) != -1){
		prime = strtol(line, NULL, 16);
		primes_ram[pc] = prime;
		pc++;
	}

	fclose(known_primes);
}

void
check_against_ram(int to_check){

	for(int i=0;i<pc;i++){
		if(to_check % primes_ram[i] == 0 || to_check/primes_ram[i] == 0){
			return;
		}
	}
	primes_ram[pc] = to_check;
	pc++;
	printf("%08X\n",to_check);	
	
}

int
main(int argv, char** argc){

	load_primes_into_ram();

	for(int i = 3; i<PRIMES_RANGE; i+=2){
		check_against_ram(i);
	};
	return 1;
}



