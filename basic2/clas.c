#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clas.h"


char* namegen(){
  char *breeds[5] = {"Border Collie", "German Sheppard", "Labrador", "Poodle", "Husky"};
  return breeds[(rand()%5)] ;
}



struct myPets firstPet(){
  dog.name = namegen();
  return dog;
}

void reachStats(){
  printf("Dog Name: %s\n", dog.name);
}


void changeName(char *newName){
  dog.name = newName;
}


