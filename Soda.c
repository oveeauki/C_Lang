/**
@ref Remake of a old practice from 5 years ago 
                                               */
#define _GNU_SOURCE
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbit.h"
#include "math.h"

#ifdef _WIN32
  #define clear() system("cls");
#else 
  #define clear() system("clear");
#endif

#define ASZ(arr) (sizeof(arr)/sizeof(arr[0]))

const float prices[] = {1.23,2.5,1.90};

const char* drinks[] = {
  "Coca",
  "Pepsi",
  "Sprite"
};

typedef struct{
  float cash,_drink;
  char* drink;
}obj;

void* cmp(size_t ss,char* uin,const char** drinks,obj* ptr){
  for(short i=0;i<ss;i++){
    if(!strcasecmp(uin,drinks[i])){
      ptr->cash = prices[i]; 
      ptr->drink = (char*)drinks[i];
    }   
  }
}

int notenough(float money){
  if(money < 0)
    printf("Bro has noo moneyy lmao\nlacking(%.2f)€\n",fabs(money));
    sleep(3);
    return(1);
}

signed main(int argc,char** argv){
  obj* jeps = malloc(sizeof(obj));
  char inp[10];
  while(true){
    printf("\nInput Soda Name (Coca,Pepsi or Sprite)\nThen your money\n(Drink Cash)\n\u279c ");
    scanf("%s %.2f",&inp,&jeps->_drink);
    if(!strcasecmp(inp,"exit")) break;
    cmp(ASZ(drinks),inp,drinks,jeps);
    float rmn = (jeps->_drink-jeps->cash);
    if(notenough(rmn)) break;
    clear();
    printf("Money Input(%.2f)€\nSelected(%s)(%.2f)€\nRemaining Money(%.2f)€\n",jeps->_drink,jeps->drink,jeps->cash,rmn);
  }
    free(jeps);
    return(0);
}
