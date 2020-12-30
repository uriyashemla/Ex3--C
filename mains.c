#include <stdio.h>
#include "txtfind.h"
#include "string.h"

#define LINE 256
#define WORD 30

int main() {
    char line[LINE];
	char w[WORD];
	fgets(line, LINE ,stdin);
	int j = 0;
	int i = 0;
	for(i = 0 ; i < LINE ; i++){
		if(line[i] == ' ' || line[i] == '\t' ){
			break;
		}
		else{
			w[j] = line[i];
			j++;
		}
	}
	w[j] = '\0';
	i++;
	if(line[i] == 'a'){
		print_lines(w);
	}
	if(line[i] == 'b'){
		print_similar_words(w);
	}
	return 0;
}