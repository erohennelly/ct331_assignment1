#include <stdio.h>

int main(int arg, char* argc[]){
  // create variables of the following types: int, int*, long, double*, char**


  printf("Sizeof int: %i \n", sizeof(int));
  printf("Sizeof int*: %i \n", sizeof(int*));
  printf("Sizeof long: %ld \n", sizeof(long));
  printf("Sizeof double*: %u \n", sizeof(double*));
  printf("Sizeof char**: %u \n", sizeof(char**));
  
  return 0;
}
