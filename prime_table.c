#include <stdio.h>


int
main(int argv, char** argc){

	unsigned int count = 0xfff;
	unsigned int i,j,k;
	for(i=2;i<count;i++){
		for(j=2;j<i;j++){
			if(i%j == 0){
				goto noprime;
			}
			for(k=1;k<count;k++){
				printf("%03X ",k*i);
			}
			printf("\n");
		};
		noprime:
		continue;
	};
	return 1;
}
