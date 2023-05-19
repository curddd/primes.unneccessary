#Include <stdio.h>
#include <strings.h>
FILE *pd;

enum hex_vals ={
	0,1,2,3,4,
	5,6,7,8,9,
	a,b,c,d,e,f
};

int hex_b = 16;


/*

12351 : 5 = 1145 r 1
05
--
073
 70
 --
  35
  35
  --
   01


*/

size_t *line_len;
size_t ppl;
int
get_fd_line_width(){
	fseek(pd, 0, SEEK_SET);
	char *line;
	
	getdelim(&line_len,&len,'\',fd);
}


size_t pd_pad = 8;

int
prime_grabber(char *prime, int num, int mul){
	size_t to_seek = line_len*num+mul*pd_pad;	
	fseek(pd, to_seek, SEEK_SET);
	fgets(prime, hex_width, pd);
}


void
factor(to_fac){
	


}


int
h_c_v(char c){
	return strpos


void
fast_div(char* to_d, char* d_by, int* res, char* rem){
	
	if(strlen(to_d)<strlen(d_by)){
		res = 0;
		rem = to_d;
		return;
	}
	
	int to_cmp_l = strlen(d_by);
	if(hex_vals[to_d] < hex_vals[d_by]){
		to_cmp_l++;
	}



	
			

int
main(char** argv, int argc){

	if(argc!=2){
		printf("Please put in the number to factor\n");
		return 0;
	}

	unsigned long int to_fac = argv[1];

	printf("seems like you want to factor %x\n",to_fac);
	
	pd= fopen('prime_runner');

	factor(to_fac);
}	

	
		
