#include <stdio.h>
#include <stdlib.h>

int is_palindrome_7d(int k) {
  char s[8];
  sprintf(s, "%d", k);
  for (int i = 0; i < 3; i++) {
    if (s[i] != s[6 - i]) {
      return 0;
    }
  }
  return 1;
}

int is_palindrome_6d(int k) {
  char s[7];
  sprintf(s, "%d", k);
  for (int i = 0; i < 3; i++) {
    if (s[i] != s[5 - i]) {
      return 0;
    }
  }
  return 1;
}

int is_palindrome_5d(int k) {
  char s[6];
  sprintf(s, "%d", k);
  for (int i = 0; i < 2; i++) {
    if (s[i] != s[4 - i]) {
      return 0;
    }
  }
  return 1;
}

int is_palindrome(int k) {
  if (k >= 1000000) {
    return is_palindrome_7d(k);
  } else if (k >= 100000) {
    return is_palindrome_6d(k);
  } else {
    return is_palindrome_5d(k);
  }
}

int main(int argc, char **args) {
  int max = 0;
  for (int i = 999; i >= 100; i--) {
    for (int j = 999; j >= 100; j--) {
      int k = i * j;
      if (is_palindrome(k) && (k > max)) {
        max = k;
      }
    }
  }
  if (max > 0) {
    printf("answer = %d\n", max);
    return 0;
  } else {
    return 1;
    printf("not found\n");
  }
}
