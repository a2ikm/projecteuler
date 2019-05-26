#include <stdio.h>

long sum_of_squares(int target) {
  long s = 0;
  for (int i = 0; i <= target; i++) {
    s += i * i;
  }
  return s;
}

long square_of_sum(int target) {
  long s = 0;
  for (int i = 0; i <= target; i++) {
    s += i;
  }
  return s * s;
}

long solve(int target) {
  return square_of_sum(target) - sum_of_squares(target);
}

int main(int argc, char **args) {
  long a;

  a = solve(10);
  if (a != 2640) {
    printf("expeced %ld, but got %ld\n", (long)2640, a);
    return 1;
  }

  a = solve(100);
  printf("answer = %ld\n", a);
  return 0;
}
