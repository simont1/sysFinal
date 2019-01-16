#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct myPets {char * name;char * breed;char * background; int experience; int friendliness; int obedience; int strength;};
struct myPets dog;

char* pickBreed(char * input);

char * description();

void interaction();

void namegen(char * input);

int userAction(char * input);

void printName();

int saveProgress();

int loadProgress();

struct myPets firstPet(char * input);

void reachStats();

void changeName(char *newName);

void goodBoy();

void about();

void dogRun();
