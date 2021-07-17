#include "list.h"

int main(int argc, char* args[])
{
  if ( not LengthCeroAtEmptyConstruction( SingleList<int>() ) ) {
      std::cout << "-- LengthCeroAtEmptyConstruction \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthGreaterThanCeroAtConstructionWithInitializerList( SingleList<int>({1, 2}) ) ) {
      std::cout << "-- LengthGreaterThanCeroAtConstructionWithInitializerList \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthEqualToOneAfterOnePushBack( SingleList<int>() )) {
      std::cout << "-- LengthEqualToOneAfterOnePushBack \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthBackToCeroAfterOnePushAndOnePop( SingleList<int>() )) {
      std::cout << "-- LengthBackToCeroAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthAfterThreePush( SingleList<int>() )) {
      std::cout << "-- LengthAfterThreePush \t FAIL" << '\n';
      return -1;
  }

  if ( not ErrorAfterOnePushAndOnePop( SingleList<int>() )) {
      std::cout << "-- ErrorAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }

  std::cout << "\t ALL TEST SUCCEDED "<< '\n';
  return 0;
}
