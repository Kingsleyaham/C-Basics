#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char *name, *semester;

  printf("Enter your name: ");
  name = read_input(BUF_SIZE);

  printf("Which semester are you currently on: ");
  semester = read_input(BUF_SIZE);

  if (name == NULL) {
    perror("Failed to read input\n");
    return 1;
  }

  if (semester == NULL) {
    perror("Failed to read input\n");
    return 1;
  }

  printf("Your name is %s\n", name);
  printf("You are currency on %s semester.\n", semester);

  if (name != NULL) {
    free(name);
    name = NULL;
  }

  if (semester != NULL) {
    free(semester);
    semester = NULL;
  }

  return 0;
}

char *read_input(int max_len) {
  char *input = malloc(max_len);

  if (input == NULL) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }

  if (fgets(input, max_len, stdin) != NULL) {
    size_t input_len = strlen(input);
    if (input_len == 1 && input[0] == '\n') {
      printf("string cannot be empty");
      free(input);
      exit(EXIT_FAILURE);
    } else {
      // Remove the newline character, if present
      if (input[input_len - 1] == '\n') {
        input[input_len - 1] = '\0';

      } else if (input_len == max_len - 1 && input[input_len - 1] != '\n') {
        // Input was too long, flush the remaining characters
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
          ;
        printf("Input was too long, excess characters discarded\n");
      }
    }

    return input;
  } else {
    if (feof(stdin)) {
      printf("End of file reached");
    } else if (ferror(stdin)) {
      printf("An error occured while reading input.\n");
    }

    clearerr(stdin); // clear the error flags
    free(input);
    exit(EXIT_FAILURE);
  }
}