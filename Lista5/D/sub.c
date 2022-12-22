#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Sub(char *str, char *sub) {
  char *auxiliar = malloc(strlen(str));
  if(strlen(str) < strlen(sub))
    return 0;

  if(strcmp(strncpy(auxiliar, str, strlen(sub)), sub) == 0) {
    if (strcmp(strncpy(auxiliar, str + strlen(str) - strlen(sub), strlen(str)), sub) == 0) {
      return strlen(str);
    } else {
      return Sub(strncpy(auxiliar, str, strlen(str)-1), sub);
    }
  }

  return Sub(strncpy(auxiliar, str + 1, strlen(str)), sub);
}

int main() {
  char str[101], sub[100];
  scanf("%s %s", str, sub);
  str[strlen(str)] = '\0';
  sub[strlen(sub)] = '\0';

  printf("%d\n", Sub(str, sub));
  return 0;
}
