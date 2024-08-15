#include "struct.h"
#include <stdio.h>

int main() {

  puts("Hello World");

  int nums[] = {1, 2, 4, 5, 8};
  char *fruits[8];

  fruits[0] = "Banana";
  fruits[1] = "Orange";
  fruits[2] = "Grape";

  unsigned int num_len = sizeof(nums) / sizeof(int);

  for (int i = 0; i < num_len; i++) {

    printf("nums %d is %d\n", i, nums[i]);
  }

  printf("%s", fruits[1]);

  return 0;
}