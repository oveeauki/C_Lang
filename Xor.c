// Simple Xor Implementation in C
#include "stdio.h"
#include "string.h"

char* xor(char* data,u_char key){
  int len = strlen(data);
  for(size_t i=0;i<len;i++){
    data[i] ^= key;
  }
  return data;
}

signed main(int argc,char* argv[]){
  u_char key = 0xf;
  char* input = strdup(argv[1]);
  char *res = xor(input,key);
  puts(res);
  return(0);
}
