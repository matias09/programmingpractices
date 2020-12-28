#include <iostream>
#include <vector>
#include <limits>
#include <cstdint>

typedef int  Int;
typedef unsigned int UInt;

// Complete the hourglassSum function below.
Int hourglassSum(std::vector<std::vector<Int>> arr)
{
  bool done = false;
  Int m     = std::numeric_limits<Int>::min();
  Int tm    = 0;
  UInt r    = 0;

  UInt hp1 = 0;
  UInt hp2 = hp1 + 1;
  UInt hp3 = hp1 + 2;

  UInt rows = arr.size();
  UInt cols = arr[0].size();

  do
  {
    tm = arr[r][hp1] + arr[r][hp2] + arr[r][hp3] +
                  arr[r + 1][hp2] +
        arr[r + 2][hp1] + arr[r + 2][hp2] + arr[r + 2][hp3];

    if (tm > m)
      m = tm;

    if ( (r + 3) == rows && ((hp1 + 3) % cols) == 0 )
    {
      done = true;
    }
    else if ( ((hp1 + 3) % cols) == 0 )
    {
      hp1 = 0;
      hp2 = hp1 + 1;
      hp3 = hp1 + 2;
      ++r;
    }
    else
    {
      ++hp1; ++hp2; ++hp3;
    }
  } while(done != true);

  return m;
}

int main()
{
  std::vector<std::vector<Int>> arr(6);
  for (UInt i = 0; i < 6; ++i)
  {
    arr[i].resize(6);

    for (UInt j = 0; j < 6; ++j)
    {
      std::cin >> arr[i][j];
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  Int result = hourglassSum(arr);
  std::cout << result;

  return 0;
}
