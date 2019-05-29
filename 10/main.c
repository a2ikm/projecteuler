#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long resolve(long target) {
  long sum = 0;

  int *flags = malloc(target * sizeof(int));
  for (long i = 0; i < target; i++) {
    flags[i] = 1;
  }

  long limit = ceil(sqrt(target));
  for (long i = 2; i < limit; i++) {
    if (flags[i]) {
      sum += i;
      for (int j = 2; i * j < target; j++) {
        flags[i * j] = 0;
      }
    }
  }

  for (long i = limit; i < target; i++) {
    if (flags[i]) {
      sum += i;
    }
  }

  return sum;
}

int main(int argc, char **args) {
  long a;

  a = resolve(10);
  if (a != 17) {
    printf("expected %ld but got %ld\n", (long)17, a);
    return 1;
  }

  a = resolve(2*1000*1000);
  printf("answer = %ld\n", a);

  return 0;
}
