#include <stdio.h>
#include "txtfind.h"
#include "string.h"

#define LINE 256
#define WORD 30

char w[WORD];
char s[LINE];

int getLine(char s[]) {
  int count = 0;
  while((s[count]!='\n') && (count < LINE) && (s[count] != '\0')) {
    count++;
  }
  return count;
}

int getword (char w[]){
  int count = 0;
  while((w[count]!='\n') && (w[count]!='\t') && (w[count]!=' ') && (count < WORD) && (w[count] != '\0')){
  count++;
}
return count;
}

int substring (char *str1, char *str2){
  int flag = 0;
  int num = 0;
  char *temp1, *temp2;
  for (int i = 0; i < LINE ; i++) {
      if (*str1 == *str2) {
        temp1 = str1;
        temp2 = str2;
        for (int j = 0; j < strlen(str2); j++){
          if (*temp1 == *temp2) {
              temp1++;
              temp2++;
              num++;
              if (num == strlen(str2)){
                break;
              }
          }
          else break;
        }
        temp2 = str2;
        if (num == strlen(str2)){ //finish to over all str2
          flag = 1;
          break;
        }
      }
      str1++;
    }
    return flag;
}

int similar (char *s, char *t, int n){
  int i = 0;
  int count = 0;
  int sizeS = strlen(s);
  if (sizeS < strlen(t)){ 
    return 0;
  }
  while (i < sizeS){
    if (*s == *t){
      s++;
      t++;
    }
    else{
      count++;
      s++;
    }
    i++;
  }
  if (count <= n){
    return 1;
  }
  else return 0;
}

void print_lines(char *str){
  char s[LINE];
	char w[WORD];
	fgets(s, LINE , stdin); //to skip the second line
	while(fgets(s, LINE , stdin)){
		int j=0;
		for(int i = 0 ; i < LINE && s[i] != '\n' ; i++){
			if(s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0'){
				w[j] = s[i];
				j++;
			}
			else {
				if(substring(str,w)){
					printf("%s",s);
					break;
				}
				j=0;
        memset(w , 0 , WORD); //reset the word
			}
		}
	}
}

void print_similar_words(char *str){
  char s[LINE];
  char w[WORD];
  fgets(s, LINE , stdin);
  while (fgets(s, LINE , stdin)){
		int j=0;
		int lenline = strlen(s);
		for(int i = 0 ; i < lenline  ; i++){
			if(s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0'){
				w[j] = s[i];
				j++;	
			}
			else{
        char *temp = w;
				if (similar(w, str , 1)){
					printf("%s\n",temp);
				}
				j=0;
				memset(w , 0 , WORD); //reset the word
			}
		}
  }
}