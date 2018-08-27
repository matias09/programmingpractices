#include <iostream>
#include <vector>

// Helpers prototypes
std::vector<int> GetMatrice3x3();


int main()
{
  std::cout << "\n ---------------------------- \n";
  const unsigned int ori = 0;
  const unsigned int des = 8;

  // PathFinding
  std::vector<int> A = GetMatrice3x3();



  std::cout << "\n ---------------------------- \n";
  return 0;
}


// Helper Declarations
std::vector<int> GetMatrice3x3()
{
  std::vector<int> A = {
    1,1,1,
    1,0,1,
    1,1,1
  }
  return A;
}

