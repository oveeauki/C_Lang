/**
  @details Reverse a String 
                            */
#define _GNU_SOURCE
#include "stdio.h"
#include "stdlib.h"
#include "stdbit.h"
#include "stdint.h"
#include "string.h"
#include "unistd.h"
#include "ctype.h"

char* rvrs(const char* strptr){
  size_t l = strlen(strptr); 
  char* buf = malloc(sizeof(char)*l);
  short a = 0;
  for(short i=l-1;i>=0;i--){
    buf[a++] += strptr[i];
  }
  return(buf);
}

signed main(int argc,char** argv){
  if(!argv[1]){
    puts("Bro Enterr Argv[1]...");
    return(1);
  }
  char* str = strdup(argv[1]);
  char* ret = rvrs(str);
  printf("The String [%s]\nin Reverseeed [%s]\n",str,ret);
  return(0);
}
