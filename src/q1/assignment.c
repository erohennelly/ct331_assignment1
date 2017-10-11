#include <stdio.h>

int main(int arg, char* argc[]){
  // create variables of the following types: int, int*, long, double*, char**
  int a;
  int* b;
  long c;
  double* d;
  char** e;
  printf("the size of int is: %zu\n",sizeof(a));
  printf("the size of int pointer is: %zu\n",sizeof(b));
  printf("the size of long is: %zu\n",sizeof(c));
  printf("the size of double pointer is: %zu\n",sizeof(d));
  printf("the size of a char pointer is: %zu\n",sizeof(e));
  return 0;
}
