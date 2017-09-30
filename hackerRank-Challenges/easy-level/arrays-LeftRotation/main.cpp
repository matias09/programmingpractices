#include <vector>
#include <iostream>

std::vector<int> array_left_rotation(std::vector<int> a, int n, int k)
{
  std::vector<int> v2(n, 0);
  int i2 = 0;

  for (int i = 0; i < n; ++i)
  {
    i2 = i - k;

    if (i2 < 0)
    {
      i2 = n + i2;
      v2[i2] = a[i];
    }
    else
    {
      v2[i2] = a[i];
    }
  }

  return v2;
}

int main(){
  int n;
  int k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for(int a_i = 0; a_i < n; a_i++){
    std::cin >> a[a_i];
  }
  std::vector<int> output = array_left_rotation(a, n, k);
  for(int i = 0; i < n;i++)
    std::cout << output[i] << " ";
  std::cout << "\n";
  return 0;
}
