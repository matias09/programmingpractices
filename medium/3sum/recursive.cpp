#include <iostream>
#include <vector>
#include <assert.h>

void GetCeroTotalSums_Right(const std::vector<int> &nums,
                            std::vector<std::vector<int>> &sums_vectors,
                            const size_t p, size_t q, const size_t r) {
  if (q != r) {
    GetCeroTotalSums_Right(nums, sums_vectors, p, q + 1, r);

    if ((nums[p] + nums[q] + nums[r]) == 0)
      sums_vectors.push_back(std::vector<int>{nums[p], nums[q], nums[r]});
  }

  return;
}

void GetCeroTotalSums_Left(const std::vector<int> &nums,
                           std::vector<std::vector<int>> &sums_vectors,
                           const size_t p, size_t q, const size_t r) {
  if (q != p) {
    GetCeroTotalSums_Left(nums, sums_vectors, p, q - 1, r);

    if ((nums[p] + nums[q] + nums[r]) == 0)
      sums_vectors.push_back(std::vector<int>{nums[p], nums[q], nums[r]});
  }

  return;
}

void sum3(const std::vector<int> &nums, std::vector<std::vector<int>> &res,
          size_t p, size_t q, size_t r) {
  if (p != r) {
    sum3(nums, res, p + 1, q, r - 1);

    GetCeroTotalSums_Left(nums, res, p, q, r);
    GetCeroTotalSums_Right(nums, res, p, q, r);
  }

  return;
}

int main() {
  //std::vector<int> nums = {4, 1, 2, -1, 15, -14, 11, -10, -3, -6, -20, 5};
  std::vector<int> nums = {-5, 3, 2, 7};
  std::vector<std::vector<int>> res;

  size_t nums_size = nums.size();
  unsigned int middle_index = ( (nums_size % 2) == 0) ? (nums_size / 2) : (nums_size / 2) - 1;

  sum3(nums, res, 0, middle_index, nums_size - 1);

  size_t res_size = res.size();
  for (size_t i = 0; i < res_size; ++i) {
    for (size_t j = 0; j < 3; ++j)
      std::cout << " nums in vector " << i + 1 << " : " << res[i][j];

    std::cout << '\n';
  }
  return 0;
}
