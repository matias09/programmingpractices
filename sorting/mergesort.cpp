#include <iostream>
#include <vector>
#include <limits>

template <typename T>
void Merge(std::vector<T> & v, int const p, int const q, int const r)
{
  std::vector<T> a, b;

  std::size_t n = q - p + 1;
  for (std::size_t i = 0; i < n; ++i)
    a.emplace_back( v[p + i] );
  a.emplace_back(std::numeric_limits<int>::max());

  n = q - p + 1;
  for (std::size_t i = 0; i < n; ++i)
    b.emplace_back(v[q + i + 1]);
  b.emplace_back(std::numeric_limits<int>::max());

  for (std::size_t i = 0, j = 0, k = p; k < r + 1; ++k) {
    if ( a[i] <= b[j] )
      v[k] = a[i++];
    else
      v[k] = b[j++];
  }
}

template <typename T>
void MergeSort(std::vector<T> & v, int const p, int const r)
{
  if (r <= p) return;

  int q = ( (p + r) / 2);
  MergeSort(v, p, q);
  MergeSort(v, q + 1, r);
  Merge(v, p, q, r);
}

int main(int argc, const char* args[])
{
  std::vector<int> v {-8,70,2,4,1,3,5,6};

  std::size_t len = v.size();
  MergeSort(v, 0, len - 1);

  for (std::size_t i = 0; i < len; ++i)
    std::cout << v[i] << ' ';

  std::cout << '\n';
  return 0;
}
