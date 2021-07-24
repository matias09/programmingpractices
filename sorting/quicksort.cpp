#include <iostream>
#include <vector>

template <typename T>
void swap(std::vector<T> & v, int i, int j)
{
  T tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}


template <typename T>
std::size_t Partition(std::vector<T> & v, int const p, int const r)
{
  int x = v[r - 1];
  int i = p - 1;

  for(std::size_t j = p; j < r; ++j)
    if (v[j] <= x)
      swap(v, j, ++i); 

  swap(v, x, ++i); 
  return i;
}

template <typename T>
void QuickSort(std::vector<T> & v, int const p, int const r)
{
  if (p < r) {
    int q = Partition(v, p, r);
    QuickSort(v, p, q - 1);
    QuickSort(v, q, r);
  }
}

int main(int argc, const char* args[])
{
  // TODO: Revise [2,8,70,1,3,5,6,4]
  // Check with biggest numbers in different places.
  std::vector<int> v {2,8,7,1,3,5,6,4,9};

  std::size_t len = v.size();
  QuickSort(v, 0, len);

  for (std::size_t i = 0; i < len; ++i)
    std::cout << v[i] << ' ';

  std::cout << '\n';
  return 0;
}
