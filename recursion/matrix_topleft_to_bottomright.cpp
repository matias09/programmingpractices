#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint8_t** get_matrix_from_heap(const uint8_t width, const uint8_t height);

void free_matrix(      uint8_t ** matrix
                ,const uint8_t    width);

void show_matrix(      uint8_t ** matrix
                ,const uint8_t    width
                ,const uint8_t    height);

uint16_t memo_amount_of_steps(      uint8_t * matrix[]
                            , const uint8_t width
                            , const uint8_t height
                            , uint8_t i
                            , uint8_t j
                            , uint8_t * cache[])
{
  if (i == (width - 1) || j == (height - 1))
    return 1;

  if (cache[i][j] != 0) {
    return cache[i][j];
  } else {
    cache[i][j] = memo_amount_of_steps(matrix, width, height, (i+1), j, cache)
                + memo_amount_of_steps(matrix, width, height, i, (j+1), cache);
  }

  return cache[i][j];
}

int main(int argc, char* args[])
{
  const uint8_t width = 2;
  const uint8_t height = 3;
  const uint8_t starting_index = 0;

  uint8_t ** matrix = get_matrix_from_heap(width, height);
  show_matrix(matrix, width, height);

  uint8_t ** cache = get_matrix_from_heap(width, height);
  uint16_t s = memo_amount_of_steps(matrix
                                  , width 
                                  , height
                                  , starting_index
                                  , starting_index
                                  , cache);

  printf("\t memo amount of steps of a %dx%d matrix = %d \n", width, height, s);

  free_matrix(cache, width);
  free_matrix(matrix, width);
  return 0;
}

uint8_t** get_matrix_from_heap(const uint8_t width, const uint8_t height)
{
  uint8_t ** matrix = new uint8_t*[width];

  for (uint8_t i = 0; i < width; ++i) {
    matrix[i] = new uint8_t[height];
    memset(matrix[i], 0, sizeof(uint8_t) * height);
  }


  return matrix;
}

void show_matrix(      uint8_t ** matrix
                ,const uint8_t    width
                ,const uint8_t    height)
{
  for (uint8_t i = 0; i < width; ++i) {
    for (uint8_t j = 0; j < height; ++j) {
      printf("%d ", matrix[i][j]); 
    }
    printf("\n"); 
  }
}

void free_matrix(      uint8_t ** matrix
                ,const uint8_t    width)
{
  for (uint8_t i = 0; i < width; ++i)
    delete[] matrix[i];
  delete[] matrix;
}

