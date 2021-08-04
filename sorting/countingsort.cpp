#include <iostream>
#include <vector>

template <typename T>
void CountingSort(std::vector<T> & a, std::vector<T> & b, int k)
{
  std::size_t len = a.size();
  std::vector<T> c(++k, 0);

  for (std::size_t j = 0; j < len; ++j)
    ++c[ a[j] ];

  for (std::size_t j = 1; j < k; ++j)
    c[j] = c[j] + c[j - 1];

  for (int j = len - 1; j > -1; --j) 
    b[ --c[ a[j] ] ] = a[j];
}

int main(int argc, const char* args[])
{
  std::vector<int> unsorted {9,8,7,2,33,4,4,1,3,5,6,10};
  std::size_t len = unsorted.size();
  int unsorted_max_value = 15;

  std::vector<int> sorted(len, 0);
  CountingSort(unsorted, sorted, unsorted_max_value);

  for (std::size_t i = 0; i < len; ++i)
    std::cout << sorted[i] << ' ';

  std::cout << '\n';
  return 0;
}
