
/*exit() codes : 
 * 2 : Cannot open file
 * 3 : File is empty 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHANCES 7
#define MAX_WORD_LENGTH 50 //the size 50 has been selected arbitrarily	

void word_selector(char *word);
void run();
void word_display(char *answer);
void clear_screen();
void hangman(int state);
int input_console(char *word, char *answer, char *guess, int *count);
void add_word(char *destination, char source);
void guess_display(char *guess, int count);

int main(){
	srand(time(NULL)); 	
	run();
	return 0;
}

void word_selector(char *word){
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
	
	//converting everything to uppercase just in case 
	strupr(word);

	//exhanging the '\n'from the selected word to a null
	word[strcspn(word, "\n")] = '\0'; 

}

void run(){
	int unsigned chances = MAX_CHANCES, state = 0, guessCount = 0;
	char word[MAX_WORD_LENGTH], guess[MAX_WORD_LENGTH], answer[MAX_WORD_LENGTH];

	word_selector(word);//selects a random word

	//char answer[strlen(word) + 1]; //the '+ 1' is for the '\0' character in the answer array (or buffer?)
	
	//there probably is a better way to do it but i have no idea what
	//this loop makes the elements of the answer an empty char or ' ' and adds a null terminator ('\0') 
	/*
	 * for(int i = 0; i <= strlen(word) + 1; i++){
	 * answer[i] = ' ';
	 * if(i == strlen(word)){
	 * answer[i] = '\0';
	 * }
	}
	*/

	//found it 
	memset(answer, ' ', strlen(word));
	answer[strlen(word)] = '\0';
	memset(guess, ' ', MAX_WORD_LENGTH);
	guess[MAX_WORD_LENGTH - 1] = '\0';

	//main gameplay loop
	clear_screen();

	while(chances != 0){
		hangman(state);
		printf("Chances :: %d\n", chances);
		word_display(answer);
		guess_display(guess, guessCount);
		if(!(input_console(word, answer, guess, &guessCount))){
			state++;
			chances--;
		}


		clear_screen();
	}

	//ending screen
	if(chances > 0){
		clear_screen();
		hangman(state);
		printf("YOU SAVED YOUR MAN \nYOU WIN!\n");
	}else{
		clear_screen();
		hangman(MAX_CHANCES);
		printf("YOU HANGED YOUR MAN \nYOU LOSE!\n");
	}
		
}

int input_console(char *word, char *answer, char *guess, int *count){
	char input, *checkInGuess;
	int isCorrect = 0;
	printf("%s\n", word);
	printf(">>>");
	scanf(" %c", &input);

	strupr(&input);//uppercaseing the input

	//putting the input in the guess array
	checkInGuess = strchr(guess, input);
	if(checkInGuess == NULL){
		printf("gay\n");
		guess[*count] = input;
		(*count)++;
	}
		
	//putting correct input into answer array
	for(int i = 0; i < strlen(word); i++){
		if(input == word[i]){
			answer[i] = input;
			isCorrect = 1;
		}
	}

	if(isCorrect){
		return 1;
	}
	return 0;

}

void word_display(char *answer){
	//prints dashes or the correct word based on the answer
	for(int i = 0; i < strlen(answer); i++){
		if(answer[i] == ' '){
			printf("_");
		}else{
			printf("%c", answer[i]);
		}
	}
	printf("\n");
}

void guess_display(char *guess, int count){
	for(int i = 0; i < count; i++){
		printf("%c ",(guess[i]));
	}	
	printf("\n");
}

void clear_screen(){
//	printf("\e[1;1H\e[2J"); 
	system("cls");
}

/*
"  +---+"
"  |   |",
"  O   |",
" /|\  |",
" / \  |",
"      |",
"========="; 
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
