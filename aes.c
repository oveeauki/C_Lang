/*
@details this is Test for AES encryption&decrypt via immintrin methods 

_int8_t 1 byte (8 bits)
_int32_t 4 bytes (32bits)
_int64_t 8 bytes (64 bits)
__int128_t 16 bytes (128 bits)                                 
                                                                           **/
#define _GNU_SOURCE 
#include "immintrin.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "unistd.h"
#include "ctype.h"

typedef struct AES{
  int32_t* outmsg;
  int32_t* ot;
  __m128i raw_msgarray;
  __m128i encodedmsg_arr;
  __m128i decoded;
  char msg[1000];
  char raw_input[1000];
 } aes;

int32_t r(void){return(int32_t)arc4random();}

__m128i bitvec(void){
  return(_mm_set_epi32(r(),r(),r(),r()));
}

signed main(void){
  aes obj;
  __m128i resvec = bitvec();
  __int128_t key = (__int128_t)_mm_aeskeygenassist_si128(resvec,0xAB);
  printf("Generated AES key (0x%02X)\n\nInput \n\u279c ",key);
  scanf("%s",&obj.raw_input);
  obj.raw_msgarray = _mm_loadu_si128((__m128i*)obj.raw_input);
  obj.encodedmsg_arr = _mm_aesenc_si128(obj.raw_msgarray,(__m128i)key);
  obj.outmsg = malloc(sizeof(__int32_t));
  memcpy(obj.outmsg,(__int32_t*)&obj.encodedmsg_arr,sizeof(obj.encodedmsg_arr));
  puts("Encrypted Msg :");
  for(short i=0;i<4;i++){
    printf("(0x%02X) ",obj.outmsg[i]);
}
  printf("Decrypt (y/n)?\n\u279c ");
  scanf("%s",&obj.raw_input);
  free(obj.outmsg);
  if(strcmp(obj.raw_input,"n") == 0){
    return(1);
  }
  obj.decoded = _mm_aesdec_si128(obj.encodedmsg_arr,(__m128i)key);
  unsigned char hh[17];
  _mm_storeu_si128((__m128i*)hh,obj.decoded);
  int32_t* juu = (int32_t*)&obj.decoded;
  puts("The Unencrypted string ");
  for(short i=0;i<4;i++){
    printf("(0x%02X) ",juu[i]);
}
  return(0); 
}