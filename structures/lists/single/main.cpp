#include "list.h"
#include "circular_list.h"
#include "unit_test.h"

int main(int argc, char* args[])
{
  if ( not LengthCeroAtEmptyConstruction( CircularSingleList<int>() ) ) {
      std::cout << "-- LengthCeroAtEmptyConstruction \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthGreaterThanCeroAtConstructionWithInitializerList( CircularSingleList<int>({1, 2}) ) ) {
      std::cout << "-- LengthGreaterThanCeroAtConstructionWithInitializerList \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthEqualToOneAfterOnePushBack( CircularSingleList<int>() )) {
      std::cout << "-- LengthEqualToOneAfterOnePushBack \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthBackToCeroAfterOnePushAndOnePop( CircularSingleList<int>() )) {
      std::cout << "-- LengthBackToCeroAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthAfterThreePush( CircularSingleList<int>() )) {
      std::cout << "-- LengthAfterThreePush \t FAIL" << '\n';
      return -1;
  }

  if ( not ErrorAfterOnePushAndOnePop( CircularSingleList<int>() )) {
      std::cout << "-- ErrorAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }

  std::cout << "\t ALL TEST SUCCEDED "<< '\n';
  return 0;
}
