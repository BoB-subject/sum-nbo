#include<stdio.h>
#include<stdint.h>
#include <netinet/in.h>
uint32_t readFile(FILE *fs){
	uint32_t *result;
	fread(result,1,4,fs);
	return ntohl(*result);
}





int main(int argc, char *argv[]){
	FILE *fs1 = fopen(argv[1],"rb");
	uint32_t result[argc-1];
	
	for(int i=1; i<argc;i++){
		FILE *fs1 = fopen(argv[i],"rb");
		if(fs1==NULL){
			printf("File Read Error");
			break;
		}
		else{
			result[i]=readFile(fs1);
		}
	}

	printf("%d (%08x) + %d (%08x) + %d (%08x) = %d (%08x)",result[1],result[1],result[2],result[2],result[3],result[3],result[1]+result[2]+result[3],result[1]+result[2]+result[3]);
	return 0;
}

