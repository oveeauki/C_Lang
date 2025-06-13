/*
    Create a function which validates whether a bridge is safe to walk on 
    Example input("########### #####") => Returns (Crap Bridge with a fault thats in position X) 
                                                                                                 */
#define _GNU_SOURCE
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

void** bridgepos(const char* input){
  void** res = malloc(3*sizeof(void*));
  char* ptr = strrchr(input,(int)' ');
  if(ptr != 0){ 
    size_t len = (strlen(input)-strlen(ptr))+1;
    size_t* lenptr = (size_t*)len;
    res[0] = ptr;
    res[1] = lenptr;
    res[2] = (char*)input;
    return(res);
  }
  return(((void*)1));
}

signed main(void){
  char* in = malloc(34);
  scanf("%33[^\n]",in);
  void** res = bridgepos((char*)in);
  if(res == ((void*)1)){
    printf("Bridge Intact...\nPointer Returned %p\n",res);
    return(1);
  }
  printf("The Bridge (%s) Is Broken from Position: %d\nFault Ptr %p\n",res[2],res[1],res[0]);
  return(0);
}