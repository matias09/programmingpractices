#include <iostream>
#include <vector>

template <typename T>
void Swap(std::vector<T> & v, int i, int j)
{
  T tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}

template <typename T>
std::size_t Partition(std::vector<T> & v, int const p, int const r)
{
  T x = v[r];
  int i = p - 1;
  int j = r;

  for (;;) {
    while (v[++i] < x);
    while (x < v[--j]);

    if  (j == p || i >= j) break;

    Swap(v, i, j);
  }
  Swap(v, i, r);

  return i;
}

template <typename T>
void QuickSort(std::vector<T> & v, int const p, int const r)
{
  if (r <= p) return;

  int q = Partition(v, p, r);
  QuickSort(v, p, q - 1);
  QuickSort(v, q + 1, r);
}

int main(int argc, const char* args[])
{
  std::vector<int> v {110,8,70,2000,4,1,30,5,6};

  std::size_t len = v.size();
  QuickSort(v, 0, len - 1);

  for (std::size_t i = 0; i < len; ++i)
    std::cout << v[i] << ' ';

  std::cout << '\n';
  return 0;
}
