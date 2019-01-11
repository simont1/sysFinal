#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clas.h"

int main(){
  srand(time(NULL));
  int i = 10;

  printf("Printing out 10 random dogs: \n");
  while(i){
    firstPet();
    reachStats();
    i-=1;
  }
  
  return 0; 
}

