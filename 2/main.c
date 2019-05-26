#include <stdio.h>

int resolve(int target) {
  int a = 1, b = 2, s = 0;

  while (b < target) {
    if (b % 2 == 0) {
      s += b;
    }

    int c = a + b;
    a = b;
    b = c;
  }

  return s;
}

int main(int argc, char **args) {
  int result;

  result = resolve(1);
  if (result != 0) {
    printf("assertion failure: expected %d but got %d\n", 0, result);
    return 1;
  }

  result = resolve(50);
  if (result != 2 + 8 + 34) {
    printf("assertion failure: expected %d but got %d\n", 2 + 8 + 34, result);
    return 1;
  }

  result = resolve(4000000);
  printf("answer = %d\n", result);
  return 0;
}
