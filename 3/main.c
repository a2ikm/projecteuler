#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long *data;
  int capacity;
  int len;
} Vector;

Vector *vec_new(void) {
  Vector *v = malloc(sizeof(Vector));
  v->len = 0;
  v->capacity = 16;
  v->data = malloc(sizeof(long) * v->capacity);
  return v;
}

void vec_free(Vector *v) {
  free(v->data);
  free(v);
}

void vec_push(Vector *v, long elm) {
  if (v->len >= v->capacity) {
    v->capacity *= 2;
    v->data = realloc(v->data, sizeof(long) * v->capacity);
  }
  v->data[v->len++] = elm;
}

long solve(long target) {
  Vector *factors = vec_new();

  long x = target;
  long i = 2;
  while (x > 1) {
    if (x % i == 0) {
      vec_push(factors, i);
      x = x / i;
    } else {
      i++;
    }
  }

  if (factors->len == 0) {
    return 0;
  } else {
    return factors->data[factors->len - 1];
  }
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
