/**
  @details Chars in the middle
                              */
#define _GNU_SOURCE
#include "stdio.h"
#include "stdlib.h"
#include "stdbit.h"
#include "stdint.h"
#include "string.h"
#include "unistd.h"
#include "ctype.h"

char* midchar(const char* str){
  size_t len = strlen(str);
  char* a = malloc(sizeof(char)*3);
  printf("%d %d %d\n",len,len%2,len/2);
  switch(len%2){
    case 0:
      short x = (len/2)-1;
      for(short i=0;i<2;i++){
         a[i] += str[x+i];
      }
      break;
    
    default:
      short xx = (len/2);
      a[0] += str[xx];
      break;
    }
    return(a); 
}

signed main(int argc,char** argv){
  char* aa = "lasikero";
  char* a = midchar(aa);
  printf("%s\n",a);
  return(0);
}
