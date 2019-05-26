#include <stdio.h>

int resolve(int target) {
  int s = 0;
  for (int n = 1; n < target; n++) {
    if ((n % 3 == 0) || (n % 5 == 0)) {
      s += n;
    }
  }
  return s;
}

int main(int argc, char **args) {
  int result = resolve(10);
  if (result != 23) {
    printf("assertion failure: expected %d but got %d\n", 23, result);
    return 1;
  }

  result = resolve(1000);
  printf("answer = %d\n", result);
  return 0;
}
