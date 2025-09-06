/**
  @details Enable 256bit Term colors before running 
                                                    */
#define _GNU_SOURCE
#include "stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "unistd.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

#ifndef __linux__
  printf("Linux Only\n");
  return EXIT_FAILURE;
#endif

signed main(void) {
    while(true){
      for(int i = 0; i <= 256; i++) {
          printf("%03d \x1b[38;5;%dm\x1b[48;5;%dm\n", i, i, i);
          usleep(10);
        }
}
    return 0;
}
