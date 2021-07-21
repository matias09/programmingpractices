#include <iostream>
#include <stdint.h>

struct MaxSubArrayResult
{
  uint16_t max_left;
  uint16_t max_right;
  uint16_t left_right_sum;
};

MaxSubArrayResult FindMaxCrossingSubarray(uint16_t array[]
                                         ,uint16_t low
                                         ,uint16_t mid
                                         ,uint16_t high)
{
  uint16_t sum = 0;
  uint16_t left_sum = 0;
  uint16_t max_left = 0;

  for (uint16_t i = mid; i <= low; --i) {
    sum = sum + array[i];

    if (sum > left_sum) {
      left_sum = sum;
      max_left = i;
    }
  }

  sum = 0;
  uint16_t right_sum = 0;
  uint16_t max_right = 0;

  for (uint16_t i = mid + 1; i <= high; ++i) {
    sum = sum + array[i];

    if (sum > right_sum) {
      right_sum = sum;
      max_right = i;
    }
  }

  return {max_left, max_right, static_cast<uint16_t>(left_sum + right_sum)};
}

MaxSubArrayResult FindMaximumSubarray(uint16_t array[]
                                     ,uint16_t low
                                     ,uint16_t high)
{
  if (high == low) {
    return {low, high, array[high]};
  } else  {
    MaxSubArrayResult sub_array_res;
    uint16_t mid = (low + high) / 2;

    sub_array_res = FindMaximumSubarray(array, low, mid);
    uint16_t left_low = sub_array_res.max_left;
    uint16_t left_high = sub_array_res.max_right;
    uint16_t left_sum = sub_array_res.left_right_sum;

    sub_array_res = FindMaximumSubarray(array, mid + 1, high);
    uint16_t right_low = sub_array_res.max_left;
    uint16_t right_high = sub_array_res.max_right;
    uint16_t right_sum = sub_array_res.left_right_sum;
    
    sub_array_res = FindMaxCrossingSubarray(array, low, mid, high);
    uint16_t cross_low = sub_array_res.max_left;
    uint16_t cross_high = sub_array_res.max_right;
    uint16_t cross_sum = sub_array_res.left_right_sum;

    if (left_sum >= right_sum && left_sum >= cross_sum)
      return {left_low, left_high, left_sum};
    else if (right_sum >= left_sum && right_sum >= cross_sum)
      return {right_low, right_high, right_sum};
    else
      return {cross_low, cross_high, cross_sum};
  }

  return {};
}

int main(int argc, char* args[])
{
  const uint16_t n = 7;
  const uint16_t starting_index = 0;
  uint16_t array[] = {1,2,3,10,4,5,6};

  MaxSubArrayResult sub_array_res;
  sub_array_res = FindMaximumSubarray(array, starting_index, n);

  std::cout << "\t Max sum array: " << sub_array_res.left_right_sum << '\n';
  return 0;
}
