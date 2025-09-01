
/*exit() codes : 
 *2 : Cannot open file
 *3 : File is empty 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHANCES 7
#define MAX_WORD_LENGTH 15 //the size 15 has been selected arbitrarily	
void word_selector(char *word, char *answer);
void hangman(int state);
void player_console(char *word, char *answer);

int main(){
	srand(time(NULL));
	char word[MAX_WORD_LENGTH],answer[MAX_WORD_LENGTH]; 	
	for(int i = 0; i < 8; i++){
		hangman(i);
		printf("\n");
	}	    
	word_selector(word, answer);
	printf("%s %d\n",word, strlen(word));
	printf("%s %d",answer, strlen(word));
	return 0;
}

void word_selector(char *word, char *answer){
	int count = 0, totalWords = 0, randomNumber;
	FILE *file;

	file = fopen("wordbank","r");
	if(file == NULL){
		printf("Cannot open file \n");
		exit(2);
	}
	
	//counting number of words in file 
	while(fegts(word,MAX_WORD_LENGTH, file)){
		total++;
	}
	if(total == 0){
		printf("Wordbank is empty\n");
		close(file);
		exit(3);
	}

	randomNumber = rand() % totalWords;
	
	//reading the file and selecting a random word
	rewind(file);
	for(int i = 0; i <= randomNumber; i++){
		fgets(word, MAX_WORD_LENGTH, file);
	}	
	fclose(file);
	
	//removing the '\n'
	word[strcspn(word, "\n")] = '\0'; 

	//copying the selected word into answer
	strcpy(answer, word);
}

/*
"  +---+"
"  |   |",
"  O   |",
" /|\  |",
" / \  |",
"      |",
"========="}; 
*/

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

void player_console(char *word, char *answer){
	
}
