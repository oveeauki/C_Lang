/**
  _int8_t 1 byte (8 bits)
  _int32_t 4 bytes (32bits)
  _int64_t 8 bytes (64 bits)
  __int128_t 16 bytes (128 bits)
                                */
#define _GNU_SOURCE
#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "time.h"

typedef struct{
  short loses;
  short wins;
  short ties;
  char input[9];
} player;

char *opt[] = {"rock","paper","scissors"};

void* p_alloc(player* pl[]){
  short a = 0;
  do{
    pl[a++] = malloc(sizeof(player));
  }while(pl[a] != NULL);
}

int cmp(char* a,char* b){
  return strcmp(a,b) == 0;
}

char* logic(char* p,char* ai,player* pl[]){
  system("clear");
  if(cmp(p,ai)){
    pl[0]->ties++;
    return("Tie!");
  } 
  else if((cmp(p,opt[0]) && cmp(ai,opt[1]))||
          (cmp(p,opt[1]) && cmp(ai,opt[2]))||
          (cmp(p,opt[2]) && cmp(ai,opt[0]))){
            pl[0]->loses++;
            pl[1]->wins++;
            return("AI Win!");
  } 
  else if((cmp(p,opt[1]) && cmp(ai,opt[0]))||
          (cmp(p,opt[2]) && cmp(ai,opt[1]))||
          (cmp(p,opt[0]) && cmp(ai,opt[2]))){
            pl[0]->wins++;
            pl[1]->loses++;
            return("Player Win!");
  }
  return("Input Error");
}

short main(void){
  player* pl[2];
  srand(UINT32_MAX&~!(time(NULL)));
  p_alloc(pl);
  for(;;){
    short abc = rand() % 3;
    strcpy(pl[0]->input,opt[abc]);
    scanf("%s",pl[1]->input);
    char* ret = logic(pl[0]->input,pl[1]->input,pl);
    printf("Returned [%s]\
          \nScores(w/l):\nAi:(%d/%d)\
          \nPlayer:(%d/%d)\nTies(%d)\n",ret,pl[0]->wins,pl[0]->loses,pl[1]->wins,pl[1]->loses,pl[0]->ties);
  }
  return(0);
}
