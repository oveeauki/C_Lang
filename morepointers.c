/**
                         */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void** lparalloc(void*** arr,size_t m){
  *arr = malloc(sizeof(void*)*m);
  memset(*arr,0x0,sizeof(*arr));
  for(short i=0;i<m;i++){
    (*arr)[i] = malloc(1000);
  }
  return((void**)arr);
}

signed main(int argc,char** argv){ 
  void** jaa;
  lparalloc(&jaa,1);
  printf("Enter String and Int\n\u279c "); 
  scanf("%s %d",(char*)jaa[0],(int*)&jaa[1]);
  printf("Str (%s) Int(%d) strlen(%d)\n",(char*)jaa[0],(int*)jaa[1],((size_t)strlen((char*)jaa[0])));
  memset(jaa,0x0,sizeof(jaa));
  free(jaa);
  return(0);
}
