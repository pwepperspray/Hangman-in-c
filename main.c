
/*exit() codes : 
 *2 : Cannot open file
 *3 : File is empty 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHANCES 7
#define MAX_WORD_LENGTH 50 //the size 50 has been selected arbitrarily	

void word_selector(char *word, char *answer);
void run(char *word, char *answer);
void (char *word);
void clear_screen();
void hangman(int state);

int main(){
	srand(time(NULL));
	char word[MAX_WORD_LENGTH],answer[MAX_WORD_LENGTH]; 	
	run(word, answer);
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
	while(fgets(word,MAX_WORD_LENGTH, file)){
		totalWords++;
	}
	if(totalWords == 0){
		printf("Wordbank is empty\n");
		fclose(file);
		exit(3);
	}
	
	//gettting a random number
	randomNumber = rand() % totalWords;
	
	//reading the file and selecting a random word
	rewind(file);
	for(int i = 0; i <= randomNumber; i++){
		fgets(word, MAX_WORD_LENGTH, file);
	}	
	fclose(file);
	file = NULL;//fukcing hate dangling pointers
	
	//removing the '\n'
	word[strcspn(word, "\n")] = '\0'; 

	//copying the selected word into answer
	strcpy(answer, word);
}

void run(char *word, char *answer){
	int state = 0;
	


}


void clear_screen(){
	printf("\e[1;1H\e[2J"); 
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
