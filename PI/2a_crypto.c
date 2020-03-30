#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 101	//	100 chars + nullbyte

void encrypt(char* message) {
	int wordStart = -1;
	int len = -1;
	for(int i = 0; i < N; i++){
	    if(wordStart == -1 && message[i] != ' ')wordStart = i;
	    if(wordStart != -1 && (message[i] == ' ' || message[i] == '\n')){
	        len = i - wordStart;
	        break;
	    }
	}
	char letter = message[0];
	int i = 0;
    do{
        if(letter != ' '){
            char start = 0;
            if(letter <= 'Z')start = 'A';
            else start = 'a';
            int asciIndex = letter - start;
            letter = start + (asciIndex + len)%26;
            message[i] = letter;
        }
        i++;
        letter = message[i];
    }while(letter != '\0' && letter != '\n');
}

int main() {
	char message[N];
	fgets(message, N, stdin);
	encrypt(message);
	printf("%s\n", message);
	return 0;
}