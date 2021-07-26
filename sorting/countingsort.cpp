#include <iostream>
#include <vector>

template <typename T>
void CountingSort(std::vector<T> & a, std::vector<T> & b, int const k)
{
  std::size_t len = a.size();
  std::vector<T> c(k, 0);

  for (std::size_t j = 0; j < len; ++j)
    ++c[ a[j] ];

  for (std::size_t j = 1; j < k; ++j)
    c[j] = c[j] + c[j - 1];

  for (int j = len - 1; j > -1; --j) 
    b[ --c[ a[j] ] ] = a[j];
}

int main(int argc, const char* args[])
{
  std::vector<int> a {9,8,7,2,4,1,3,5,6};
  std::size_t len = a.size();

  std::vector<int> b(len, 0);
  CountingSort(a, b, 10);

  for (std::size_t i = 0; i < len; ++i)
    std::cout << b[i] << ' ';

  std::cout << '\n';
  return 0;
}
