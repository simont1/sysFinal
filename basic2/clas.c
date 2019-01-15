#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "clas.h"

char* pickBreed(){
  char *breeds[5] = {"Border Collie", "German Shepherd", "Labrador Retriever", "Akita", "Siberian Husky"};
  return breeds[(rand()%5)] ;
}

void namegen(char * input){
  dog.name = input;
  printf("Welcome, %s!\n", input);
}

int userAction(char * input){
  if (!strcmp(input, "1")){
    reachStats();
    return 1;
  }
  else if(!strcmp(input, "2")){
    interaction();
    return 1;
  }
  else if(!strcmp(input,"3")){
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
    "Bright workahloics, agile, balanced, durable, loveable.\n\0";
  }
  else if (!strcmp(dog.breed,"German Shepherd")){
    details = "German shepherds are around 24 - 26 inches tall for males and 22 - 24 inches tall for females.\n"
    "These dogs on average weigh between 50 - 90 pounds.\n"
    "German Shepherds have an average life expectancy of 7 - 10 years.\n"
    "Loyal, confident, courageous, and steady.\n\0";
  }
  else if (!strcmp(dog.breed,"Labrador Retriever")){
    details = "Labrador Retrievers are around 22 - 24 inches tall for males and 21 - 23 inches tall for females.\n"
    "These dogs on average weigh between 55 - 80 pounds.\n"
    "Labrador Retrievers have an average life expectancy of 10 - 12 years.\n"
    "Friendly, outgoing, and high-spirited.\n\0";
  }
  else if (!strcmp(dog.breed,"Akita")){
    details = "Akitas are around 26 - 28 inches tall for males and 24 - 26 inches tall for females.\n"
    "These dogs on average weigh between 70 - 130 pounds.\n"
    "Akitas have an average life expectancy of 10 -13 years.\n"
    "Famous for their Dignity, Courage, and Loyalty\n\0";
  }
  else if (!strcmp(dog.breed,"Siberian Husky")){
    details = "Huskies are around 21 - 24 inches tall for males and 20 - 22 inches tall for females.\n"
    "These dogs on average weigh between 35 - 60 pounds.\n"
    "Huskies have an average life expectancy of 12 - 14 years.\n"
    "Friendly, Fastidious, and dignified.\n\0";
  }
  // else{
  //   details = "Wut?";
  // }
  return details;
}

struct myPets firstPet(){
  dog.breed = pickBreed();
  dog.name = "";
  dog.background = description();
  dog.experience = 0;
  return dog;
}

void interaction(){
  char * actions[5] = {"Bark!, Bark!", "brought you a stick!", "Woof! Woof!", "Rolled over!", "played dead!"};
  for(int i = 0; i < 7; i++){
    printf("%s: %s\n", dog.name, actions[(rand()%5)]);
    printf("====================================\n");
    sleep(1);
  }
  int temp = (rand() % 5)+5;
  dog.experience += temp;
  printf("Experience gained: %d\n", temp);
}

void reachStats(){
  printf("Dog Name: %s\n", dog.name);
  printf("Dog Breed:%s\n", dog.breed);
  printf("Dog Background: %s\n", dog.background);
  printf("Experience: %d\n", dog.experience);
}

int saveProgress(){
  char * file = "test.txt";
  int file_id = open(file, O_RDWR);
  int write_size = write(file_id, "woad\n", 5);
  printf("Write Size: %d\n", write_size);
  return close(file_id);
}

int loadProgress(){
  return 1;
}


// void changeName(char *newName){
//   dog.name = newName;
// }
