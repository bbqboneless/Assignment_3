#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	FILE* fp;
	char c;
	int chars = 0,lines = 1,words = 1;
	
	if(argc != 2){
		printf("Input error\n");
		return -1;
	}
	
	fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("Can't open the file\n");
		fclose(fp);
		return -1;
	}
	
	while((c = fgetc(fp)) != EOF){
		if(c != ' ' && c != '\n'){
			//printf("%d -> %c\n",chars,c);
			chars++;
		}
		if(c == '\n'){
			lines++;
		}
		if(c == ' ' || c == '\n'){
			words++;
		}
	}
	printf("Number of total characters: %d\n",chars);
	printf("Number of lines: %d\n",lines);
	printf("Number of total words: %d\n",words);
	fclose(fp);
	return 0;
}
