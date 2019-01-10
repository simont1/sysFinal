#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clas.h"

int main(){
  srand(time(NULL));
  int i = 10;

  printf("Printing out 10 random pokemons: \n");
  while(i){
    firstPet();
    reachStats();
    i-=1;
  }

  printf("\nChanging the value of pokemon: \nOriginal Pokemon --> ");
  
  reachStats();
  printf("Changing name to Charizard --> ");
  changeName("Charizard");
  reachStats();
  printf("Changing name to Ditto --> ");
  changeName("Ditto");
  reachStats();
  
  return 0; 
}
