#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int count = 0;
	FILE *file;
	char word[15]; //word length is taken arbitrarily
	
	file = fopen("wordbank","r");
	if(file == NULL){
		puts("Cannot open file");
		exit(2);
	}

	while(fgets(word,14,file) != 0){
		printf("%s", word);
	}
	return 0;
}
