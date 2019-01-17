#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "clas.h"

char* pickBreed(char * input){
  char *breeds[4] = {"Border Collie", "German Shepherd", "Labrador Retriever", "Akita"};
  return breeds[atoi(input)-1];
}


void namegen(char * input){
  dog.name = input;
  printf("Welcome, %s!\n", input);
}

int userAction(char * input){
  if (!strcmp(input, "1")){
    about();
    return 1;
  }
  else if(!strcmp(input, "2")){
    reachStats();
    return 1;
  }
  else if(!strcmp(input, "3")){
    interaction();
    return 1;
  }
  else if(!strcmp(input, "4")){
    goodBoy();
    return 1;
  }
  else if(!strcmp(input, "5")){
    dogRun();
    return 1;
  }
  else if(!strcmp(input,"6")){
    return -2;
  }
  else{
    return -1;
  }
}

char * description(){
  char * details = malloc(100);
  if (!strcmp(dog.breed,"Border Collie")){
    details = "Border collies are around 19 - 22 inches tall for males and 18 - 21 inches tall for females.\n"
    "These dogs on average weigh between 30 - 55 pounds.\n"
    "Border collies have an average life expectancy of 12 - 15 years.\n"
    "Bright workahloics, agile, balanced, durable, loveable.\n"
    "2x Bonus on leveling up friendliness\n\0";
  }
  else if (!strcmp(dog.breed,"German Shepherd")){
    details = "German shepherds are around 24 - 26 inches tall for males and 22 - 24 inches tall for females.\n"
    "These dogs on average weigh between 50 - 90 pounds.\n"
    "German Shepherds have an average life expectancy of 7 - 10 years.\n"
    "Loyal, confident, courageous, and steady.\n"
    "2x bonus on leveling up obedience\n\0";
  }
  else if (!strcmp(dog.breed,"Labrador Retriever")){
    details = "Labrador Retrievers are around 22 - 24 inches tall for males and 21 - 23 inches tall for females.\n"
    "These dogs on average weigh between 55 - 80 pounds.\n"
    "Labrador Retrievers have an average life expectancy of 10 - 12 years.\n"
    "Friendly, outgoing, and high-spirited.\n"
    "2x bonus on gaining experience\n\0";
  }
  else if (!strcmp(dog.breed,"Akita")){
    details = "Akitas are around 26 - 28 inches tall for males and 24 - 26 inches tall for females.\n"
    "These dogs on average weigh between 70 - 130 pounds.\n"
    "Akitas have an average life expectancy of 10 -13 years.\n"
    "Famous for their Dignity, Courage, and Loyalty\n";
    "2x bonus on leveling up strength\n\0";
  }
  // else{
  //   details = "Wut?";
  // }
  return details;
}

struct myPets firstPet(char * input){
  dog.breed = pickBreed(input);
  dog.name = "";
  dog.background = description();
  dog.experience = 0;
  dog.friendliness = 0;
  dog.obedience = 0;
  dog.strength = 0;
  return dog;
}

void interaction(){
  char * actions[5] = {"Bark!, Bark!", "brought you a stick!", "Woof! Woof!", "Rolled over!", "played dead!"};
  for(int i = 0; i < 2; i++){
    printf("%s: %s\n", dog.name, actions[(rand()%5)]);
    printf("====================================\n");
  }
  int temp1 = 0;
  if(!strcmp(dog.breed, "Border Collie")){
    temp1 = 2;
  } else {
    temp1 = 1;
  }
  int temp = (rand() % 5)+5;
  if(!strcmp(dog.breed, "Labrador Retriever")){
    temp = temp * 2;
  }
  dog.experience += temp;
  dog.friendliness += temp1;
  printf("Experience gained: %d\n", temp);
  printf("Friendliness increased by %d points!\n", temp1);
}

void reachStats(){
  printf("Dog Name: %s\n", dog.name);
  printf("Dog Breed: %s\n", dog.breed);
  printf("Friendliness Level: %d\n", dog.friendliness);
  printf("Obedience Level: %d\n", dog.obedience);
  printf("Experience: %d\n", dog.experience);
}

void about(){
  printf("Dog Background: %s\n", dog.background);
}

void goodBoy(){
  printf("Dog School...\n");
  int temp1 = 0;
  if(!strcmp(dog.breed, "German Shepherd")){
    temp1 = 2;
  }
  else{
    temp1 = 1;
  }
  dog.obedience += temp1;
  int temp = (rand() % 5) + 5;
  if(!strcmp(dog.breed, "Labrador Retriever")){
    temp = temp * 2;
  }
  dog.experience += temp;
  printf("Experience gained: %d\n", temp);
  printf("Obedience increased by %d points!\n", temp1); 
}

void dogRun(){
  printf("Out at the dog park...\n");
  int temp1 = 0;
  if(!strcmp(dog.breed, "Akita")){
    temp1 = 2;
  } else {
    temp1 = 1;
  }
  dog.strength += temp1;
  int temp = (rand() % 5) + 5;
  if(!strcmp(dog.breed, "Labrador Retriever")){
    temp = temp * 2;
  }
  dog.experience += temp;
  printf("Experience gained: %d\n", temp);
  printf("Strength increased by %d points!\n", temp1);
}

int saveProgress(){
  char * file = "test.txt";
  int file_id = open(file, O_WRONLY);
  char * WRString = malloc(10);
  snprintf(WRString, 10, "%d", dog.experience);
  printf("%s\n", WRString);
  int write_size = write(file_id, WRString, 5);
  printf("Write Size: %d\n", write_size);
  return close(file_id);
}

int loadProgress(){
  return 1;
}

// void changeName(char *newName){
//   dog.name = newName;
// }