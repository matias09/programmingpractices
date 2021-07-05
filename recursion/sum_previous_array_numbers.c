#include <stdio.h>
#include <stdint.h>

void previous_sum_arr(const uint8_t n, uint8_t array[], uint8_t i)
{
  if (n < 1 || (i + 1) == n) return; 

  ++i;
  array[i] = array[i - 1] + array[i];
  previous_sum_arr(n, array, i);
}

int main(int argc, char* args[])
{
  const uint8_t n = 6;
  const uint8_t starting_index = 0;
  uint8_t array[] = {1,2,3,4,5,6};

  previous_sum_arr(n, array, starting_index);

  printf("\t Elements in the array after modification  \n \t \t");
  for (uint8_t i = 0; i < n; ++i) {
    printf("%d ", array[i]);
  }

  printf("\n");
  return 0;
}
