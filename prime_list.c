#include <stdio.h>


int
main(int argv, char** argc){

	unsigned int count = 0xffffffff;
	unsigned int i,j,k;
	for(i=2;i<count;i++){
		for(j=2;j<i;j++){
			if(i%j == 0){
				goto NOPE;
			}
		}
		printf("%08X\n",i);	
NOPE:
	continue;
	};
	return 1;
}
