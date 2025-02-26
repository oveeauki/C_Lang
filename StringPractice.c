/**
  @details makes every other char
  of the input string higher case
                                 */
#define _GNU_SOURCE
#include "stdio.h"
#include "string.h"
#include "ctype.h"

char* strcase(size_t size,char* word){
  short a = 0;
  char array[size+1];
  strcpy(array,word);
  while(array[a] != '\0'){ 
    if(a % 2 != 0){
      array[a] = toupper(array[a]);
  }
    a++;
  }
  strcpy(word,array);
  return(word);
}

signed main(void){
  char jaakko[100];
  puts("Enter Shit:"); 
  fgets(jaakko,sizeof(jaakko),stdin);
  char* res = strcase(strlen(jaakko),jaakko);
  puts(res);
  return(0);
}
