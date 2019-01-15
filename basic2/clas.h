#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct myPets {char * name;char * breed;char * background; int experience;};
struct myPets dog;

char* pickBreed();

char * description();

void interaction();

void namegen(char * input);

int userAction(char * input);

int saveProgress();

int loadProgress();

struct myPets firstPet();

void reachStats();

void changeName(char *newName);
