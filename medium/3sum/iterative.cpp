#include <iostream>
#include <vector>
#include <assert.h>


int main() {
  //std::vector<int> nums = {4, 1, 2, -1, 15, -14, 11, -10, -3, -6, -20, 5};
  //std::vector<int> nums = {-5, 3, 2, -8, 8, 0, 1};
  //std::vector<int> nums = {-5, 3, 2, -5};
  //std::vector<int> nums = {-5, 3, 2, -8, 8, 0};

  std::vector<int> nums = {4, 1, 2, -1, 15, -14, 11, -10, -3, -6, -20, 5, 4, 2, 1};
  std::vector<std::vector<int>> res;

  size_t nums_size = nums.size();
  for (size_t i = 0; i < nums_size; ++i)
    for (size_t j = i + 1; j < nums_size; ++j)
      for (size_t k = j + 1; k < nums_size; ++k)
        if ( (nums[i] + nums[j] + nums[k]) == 0)
          res.push_back({nums[i], nums[j], nums[k]});



  size_t res_size = res.size();
  for (size_t i = 0; i < res_size; ++i) {
    std::cout << " nums in vector " << i + 1;

    for (size_t j = 0; j < 3; ++j)
      std::cout << " : " << res[i][j];

    std::cout << '\n';
  }
  return 0;
}
