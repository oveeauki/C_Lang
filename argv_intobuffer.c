/*
    Practice 
               */
#define _GNU_SOURCE
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct{
  char name[100];
  int age;
  char* buf;
} abc;

short pa(char *ar[]) {
  short size = 0;
  do{
    size++;
  }while(ar[size] != NULL);
  return(size);
}

char* memjoin(abc* ptr,short size,char* arr[]){
  int sz = 1;
  for(short i=0;i<size;i++){
    sz += strlen(arr[i]);
}
  printf("Argv Size Total (%d)\n",sz);
  ptr->buf = (char*)malloc(sz);
  for(short i=0;i<size;i++){
    strcat(ptr->buf,arr[i]);
}
  return(ptr->buf);
}

signed main(int argc,char* argv[]){
  abc obj;
  short argsize = pa(argv);
  memjoin(&obj,argsize,argv);
  puts(obj.buf);
  return(0);
}
