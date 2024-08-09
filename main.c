#include "main.h"
#include <ctype.h>
#include <err.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char *msg = "This is my message";

  char *new_msg = str_to_lower(msg);

  printf("%s\n", msg);
  printf("%s\n", new_msg);

  int num1 = 50;
  int num2 = 75;

  printf("Num1 is %d\n", num1);
  printf("Num2 is %d\n", num2);

  swap(&num1, &num2, sizeof(int));

  printf("Num1 is %d\n", num1);
  printf("Num2 is %d\n", num2);

  char *msg1 = "Kingsley";
  char *msg2 = "Michael";

  // swap(msg1, msg2, strlen())
  swap_strings(&msg1, &msg2);

  puts(msg1);
  puts(msg2);

  char *str = "man";

  print_chars(str);

  if (new_msg) {
    free(new_msg);
    new_msg = NULL;
  }
  return 0;
}

float calculate_area_of_rectangle(float width, float height) {
  return width * height;
}

char *str_to_lower(char *str) {
  size_t str_len = strlen(str);
  char *lower = (char *)malloc(str_len + 1);

  if (lower == NULL) {
    // err(EXIT_FAILURE, "An error occured assigning memory");

    // fprintf(stderr, "Error: Failed to allocated memory: %s\n",
    // strerror(errno));

    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < str_len; i++) {
    lower[i] = tolower((unsigned char)str[i]);
  }

  lower[str_len] = '\0';

  return lower;
}

void swap(void *a, void *b, size_t size) {
  // allocate a temporal buffer
  unsigned char temp[size];

  // copy a into temp
  memcpy(temp, a, size);

  memcpy(a, b, size);

  memcpy(b, temp, size);
}

void swap_strings(char **str1, char **str2) {
  char *temp = *str1;

  *str1 = *str2;
  *str2 = temp;
}

void print_chars(const char *str) {
  // loop until the null terminator is reached

  // while (*str != '\0') {
  //   printf("%c\n", *str); // print the character pointed to by str
  //   str++;                // moves pointer to the next character
  // }

  // using a for loop

  for (; *str != '\0'; str++) {
    printf("%c\n", *str); // print the character pointed to by str
  }
}
