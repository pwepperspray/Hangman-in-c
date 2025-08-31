#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run(FILE *file){
	
	int count = 0, r = rand() % 213;
	char word[15];
	while(fgets(word,14,file) != 0){
		count++;
		if(count == r){
			break;
		}
	}
	printf("count : %d, Word : %s \n", count, word);

}

int main(){
	FILE *file;
	
	file = fopen("wordbank","r");
	if(file == NULL){
		puts("Cannot open file");
		exit(2);
	}

	run(file);
	run(file);
	run(file);

	return 0;
}
