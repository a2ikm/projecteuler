#include <stdio.h>

long solve(long target) {
  long max = 0;

  long x = target;
  long i = 2;
  while (x > 1) {
    if (x % i == 0) {
      max = i;
      x = x / i;
    } else {
      i++;
    }
  }

  return max;
}

int main(int argc, char **args) {
  long a;

  a = solve(2);
  if (a != 2) {
    printf("expected %ld, but got %ld\n", (long)2, a);
    return 1;
  }

  a = solve(3);
  if (a != 3) {
    printf("expected %ld, but got %ld\n", (long)3, a);
    return 1;
  }

  a = solve(13195);
  if (a != 29) {
    printf("expected %ld, but got %ld\n", (long)29, a);
    return 1;
  }

  a = solve(600851475143);
  printf("answer = %ld\n", a);

  return 0;
}
