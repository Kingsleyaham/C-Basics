#include "input.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  int age;

  printf("Enter an integer: ");

  if (scanf("%i", &age) == 1) {
    printf("You are %i years old\n", age);
  } else {
    // perror("An error occured reading input");

    exit(EXIT_FAILURE);
  }

  return 0;
}