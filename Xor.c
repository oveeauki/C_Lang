// Simple Xor Implementation in C
#include "stdio.h"
#include "string.h"

__u_char xor(char data[],char key){
  int len = strlen(data);
  for(size_t i=0;i<len;i++){
   data[i] = (data[i] ^= key);
}
  return data;
}

signed main(int argc,char* argv[]){
  char data[] = "hello";
  printf("%s\n",data);
  char key = 0xA;
  char res = xor(data,key);
  printf("%s\n",res);
}
