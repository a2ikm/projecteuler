#include <stdio.h>

int gcd(int m, int n) {
  // assure m >= n
  if (m < n) {
    int tmp = m;
    m = n;
    n = tmp;
  }

  while (n > 0) {
    int tmp = n;
    n = m % tmp;
    m = tmp;
  }

  return m;
}

int lcm(int m, int n) {
  return m * n / gcd(m, n);
}

int solve(int target) {
  int a = 1;
  for (int i = 1; i <= target; i++) {
    a = lcm(a, i);
  }
  return a;
}

int main(int argc, char **args) {
  int a;

  a = solve(5);
  if (a != 60) {
    printf("expected %d but got %d\n", 60, a);
    return 1;
  }

  a = solve(10);
  if (a != 2520) {
    printf("expected %d but got %d\n", 2520, a);
    return 1;
  }

  a = solve(20);
  printf("answer = %d\n", a);
  return 0;
}
