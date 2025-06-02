#include <stdio.h>

int add(int, int);
int sub(int, int);

int main() {
  int a = 4, b = 2;
  
  printf("add: %d\n", add(a, b));
  printf("sub: %d\n", sub(a, b));
  return 0;
}
