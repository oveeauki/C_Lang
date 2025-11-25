/**
                         */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void** lparalloc(void*** arr,size_t m){
  *arr = malloc(sizeof(void*)*m);
  memset(*arr,0,sizeof(void*)*m);
  for(short i=0;i<m;i++){
    (*arr)[i] = malloc(1000);
  }
  return((void**)arr);
}

signed main(int argc,char** argv){ 
  void** jaa;
  lparalloc(&jaa,19);
  printf("Enter\n\u279c "); 
  scanf("%s %d",(char*)&jaa[0],(int*)&jaa[1]);
  printf("%s %d len(%d)\n",&jaa[0],*(int*)&jaa[1],strlen((char*)&jaa[0]));
  return(0);
}
