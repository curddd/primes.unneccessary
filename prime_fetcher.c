#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

FILE *pd;

FILE *in;
FILE *out;



int
main(int argc, char** argv){

	pd = fopen("32bit_primes","r");
	in = fopen("/tmp/prime_request","r");
	out = fopen("/tmp/prime_response","w");

	char request[16] = {0};
	char response[16] = {0};
	int line_req;
	while(fread(request, 16, 1, in)){
		line_req = atoi(request);
		fsetpos(pd,0);
		while(line_req>0){
			fgets(response, 16, pd);
			line_req--;
		}
	
		fwrite(response, 16, 1, out);
	}
	return 0;

}


