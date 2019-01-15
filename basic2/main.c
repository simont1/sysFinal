#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clas.h"

int main(){
  // srand(time(NULL));
  // int i = 10;
  //
  // printf("Printing out 10 random dogs: \n");
  // while(i){
  //   firstPet();
  //   reachStats();
  //   i-=1;
  // }
  //
  // interaction();
  //
  // return 0;
  char input[10];
  int status;

  printf("Let's make a pet\n");
  firstPet();
  printf("What is your pet's name? (10 chars max)\n");
  scanf(" %[^\n]s", input);
  namegen(input);
  while (1){
    printf("Options: \n(1) Reach Stats \n(2) Interact with pet \n(3) Exit \nInput a number below\n");
    scanf(" %[^\n]s", input);
    status = userAction(input);
    if (status == -2){
      printf("Exiting...\n");
      printf("%d\n", saveProgress());
      return 0;
    }
    if(status == -1){
      printf("Invalid argument, try again\n");
    }
  }
  return 0;
}
