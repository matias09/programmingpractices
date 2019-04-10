#include <iostream>
#include <vector>

int main()
{
  std::vector< std::vector<int> > res;
  res.push_back(std::vector<int>({100, 2, 1}));

  std::cout << res[0][2] << '\n';

  return 0;
}
