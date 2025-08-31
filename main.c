#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHANCES 7

void word_selector(char* word);
void hangman(int state);
void playing_console();

int main(){
	srand(time(NULL));
	char word[15]; //the size 15 has been selected arbitrarily	
	for(int i = 0; i < 8; i++){
		display(i);
		printf("\n");
	}	    
	return 0;
}

void word_selector(char* word){
	int count = 0, randomNumber = rand() % 213;
	FILE *file;

	file = fopen("wordbank","r");
	if(file == NULL){
		printf("Cannot open file \n");
		exit(2);
	}
	while(fgets(word,14,file) != 0){
		count++;
		if(count == randomNumber){
			break;
		}
	}
	fclose(file);
}

/* "  +---+"
"  |   |",
"  O   |",
" /|\  |",
" / \  |",
"      |",
"========="}; */

void hangman(int state){

	printf("+++++++++++++HANGMAN+++++++++++++\n");
	const char *row0[] = {"  +---+","      |","========="},
			   *row1[] = {"  |   |"},
			   *row2[] = {"  O   |"},
			   *row3[] = {"  |   |"," /|   |"," /|\\  |"},
			   *row4[] = {" /    |"," / \\  |"};
	
	if(state == 0){
		printf("%s\n",row0[0]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[2]);
	}else if(state == 1){
		printf("%s\n",row0[0]);
		printf("%s\n",row1[0]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[2]);
	}else if(state == 2){
		printf("%s\n",row0[0]);
		printf("%s\n",row1[0]);
		printf("%s\n",row2[0]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[2]);
	}else if(state == 3){
		printf("%s\n",row0[0]);
		printf("%s\n",row1[0]);
		printf("%s\n",row2[0]);
		printf("%s\n",row3[0]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[2]);
	}else if(state == 4){
		printf("%s\n",row0[0]);
		printf("%s\n",row1[0]);
		printf("%s\n",row2[0]);
		printf("%s\n",row3[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[2]);
	}else if(state == 5){
		printf("%s\n",row0[0]);
		printf("%s\n",row1[0]);
		printf("%s\n",row2[0]);
		printf("%s\n",row3[2]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[2]);
	}else if(state == 6){
		printf("%s\n",row0[0]);
		printf("%s\n",row1[0]);
		printf("%s\n",row2[0]);
		printf("%s\n",row3[2]);
		printf("%s\n",row4[0]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[2]);
	}else if(state == 7){
		printf("%s\n",row0[0]);
		printf("%s\n",row1[0]);
		printf("%s\n",row2[0]);
		printf("%s\n",row3[2]);
		printf("%s\n",row4[1]);
		printf("%s\n",row0[1]);
		printf("%s\n",row0[2]);
	}
}
