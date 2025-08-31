#include <stdio.h>
#include <stdlib.h>

int main(){
	int r;
	for(int i = 0; i < 20; i++){
		r = rand() % 213;
		printf("%d\n", r);
	}
	return 0;
}
