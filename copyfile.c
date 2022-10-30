#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	FILE *source,*copy;
	char c;
	
	//check error
	if(argc != 3){
		printf("Input error: Too few arguments\n");
		return -1;
	}
	
	source = fopen(argv[1],"r");
	if(source == NULL){
		perror("source is null");
		fclose(source);
		exit(1);
	}
	
	copy = fopen(argv[2],"w+");
	if(copy == NULL){
		perror("copy is null");
		fclose(copy);
		exit(1);
	}
	
	while((c = fgetc(source)) != EOF)
		fputc(c,copy);
	fclose(source);
	fclose(copy);
	return 0;
}
