/**
  @details Flip String Advanced Method
                                        */
#define _GNU_SOURCE
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct {
  char** ptr_arr;
} obj; 

 void* flipastring(char* str,obj* ptr,size_t len){
  short a = 0;
  for(short i=len-1;i>=0;i--){
    memcpy((char*)&ptr->ptr_arr[0][a++],(char*)&ptr->ptr_arr[1][i],1);
  }
}

signed main(int argc,char** argv){
  if(!argv[1]){
    puts("Enter Input!! (./binpath [stringinput])");
    return(EXIT_FAILURE);
  }

  size_t len = strlen(argv[1]);
  obj b;
  b.ptr_arr = malloc(2*sizeof(char*));
  b.ptr_arr[0] = malloc(sizeof(char*)*len);
  b.ptr_arr[1] = malloc(sizeof(char*)*len);
  strcpy(b.ptr_arr[1],(char*)argv[1]);
  flipastring((char*)b.ptr_arr[1],&b,len);
  printf("(%s) \u279c (%s) BUT Backwards xd\n",b.ptr_arr[1],b.ptr_arr[0]);
  free(b.ptr_arr);
  return EXIT_SUCCESS;
}
