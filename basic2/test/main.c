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
  srand(time(NULL));
  char input[10];
  char initName[10];
  char initBreed[5];
  char loadChoice[5];
  int status;

  printf("Let's adopt a pet\n");
  printf("(1) New or (2) Returning Pet?\n");
  scanf(" %[^\n]s", loadChoice);
  if(!strcmp(loadChoice, "2")){
    secondPet();
  }
  else{
    printf("New pet!\n");
    printf("Choose a breed: \n(1) Border Collie \n(2) German Shepherd \n(3) Labrador Retriever \n(4) Akita \n");
    scanf(" %[^\n]s", initBreed);
    while(strcmp(initBreed,"1") && strcmp(initBreed,"2") && strcmp(initBreed,"3") && strcmp(initBreed,"4") ){
      printf("Invalid argument, try again\n");
      scanf(" %[^\n]s", initBreed);
    }
    firstPet(initBreed);
    printf("Excellent choice\n");
    printf("What is your pet's name? (10 chars max)\n");
    scanf(" %[^\n]s", initName);
    namegen(initName);
    printf("Welcome, %s!\n", initName);
  }

  //namegen(input);
  while (1){
    printf("Options: \n(1) About \n(2) Reach Stats \n(3) Interact with pet \n(4) Dog Training\n(5) Dog Exercise \n(6) Exit \nInput a number below\n");
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
