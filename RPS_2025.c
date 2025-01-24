/**
  _int8_t 1 byte (8 bits)
  _int32_t 4 bytes (32bits)
  _int64_t 8 bytes (64 bits)
  __int128_t 16 bytes (128 bits)
                                */
#define _GNU_SOURCE
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "time.h"

typedef struct{
  short loses;
  short wins;
  short ties;
  char input[10];
} player;

char *opt[] = {"rock","paper","scissors"};
char rnd[15];

void* p_alloc(player** pl,bool cond){
  short a = 0;
  do{
    pl[a++] = (void*)malloc(sizeof(player));
  }while(pl[a] != NULL);

  if(cond == 0){
    for(short i=0;i<2;i++){
      free(pl[i]);
    }
  }
}

int cmp(char* a,char* b){
  return strcmp(a,b) == 0;
}

char* logic(char* p,char* ai,player** pl){
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

void scores(player** pl){
    system("clear");
    printf("Returned [%s]\
          \nScores(w/l):\nAi:[%d/%d]\
          \nPlayer:[%d/%d]\nTies[%d]\n",rnd,pl[0]->wins,pl[0]->loses,pl[1]->wins,pl[1]->loses,pl[0]->ties);
}

short main(void){
  player* pl[2];
  srand(UINT32_MAX &~! (time(NULL))); // Just some random values for seed
  p_alloc(pl,true);
  for(;;){
    system("clear");                    
    short abc = rand() % 3;
    fprintf(stdout,"[RPS_2025]\nEnter\n\u279c ");
    strcpy(pl[0]->input,opt[abc]);
    scanf("%s",pl[1]->input);
    if(cmp("exit",pl[1]->input)) break;
    char* ret = logic(pl[0]->input,pl[1]->input,pl);
    strcpy(rnd,ret);
    scores(pl);
    memset(&rnd,0,sizeof(rnd));
    sleep(2);
  }
  scores(pl);
  p_alloc(pl,false);
  puts("\nExited...");
  return(0);
}
