#include<stdio.h>
#include<stdint.h>
#include <netinet/in.h>
uint32_t readFile(FILE *fs){
	uint32_t result;
	uint32_t *a;
	fread(a,1,4,fs);
	//result=a;
	//printf("%08x\n",ntohl(result));
	printf("%s\n",a);
	result=*a;
	return ntohl(result);
}





int main(int argc, char *argv[]){
	FILE *fs1 = fopen(argv[1],"rb");
	FILE *fs2 = fopen(argv[2],"rb");
	FILE *fs3 = fopen(argv[3],"rb");

	uint32_t result1;
	uint32_t result2;
	uint32_t result3;
	result1=readFile(fs1);
	result2=readFile(fs2);
	result3=readFile(fs3);
	printf("%d (%08x) + %d (%08x) + %d (%08x) = %d (%08x)",result1,result1,result2,result2,result3,result3,result1+result2+result3,result1+result2+result3);
	return 0;
}

