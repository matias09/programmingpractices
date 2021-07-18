#include "single_linked_list.h"
#include "circular_single_linked_list.h"
#include "double_linked_list.h"
#include "unit_test.h"

int main(int argc, char* args[])
{
  std::cout << "--- Single List Test" << '\n';
  if ( not LengthCeroAtEmptyConstruction( SingleList<int>() ) ) {
      std::cout << "\t-- LengthCeroAtEmptyConstruction \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthGreaterThanCeroAtConstructionWithInitializerList( SingleList<int>({1, 2}) ) ) {
      std::cout << "\t-- LengthGreaterThanCeroAtConstructionWithInitializerList \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthEqualToOneAfterOnePushBack( SingleList<int>() )) {
      std::cout << "\t-- LengthEqualToOneAfterOnePushBack \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthBackToCeroAfterOnePushAndOnePop( SingleList<int>() )) {
      std::cout << "\t-- LengthBackToCeroAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthAfterThreePush( SingleList<int>() )) {
      std::cout << "\t-- LengthAfterThreePush \t FAIL" << '\n';
      return -1;
  }

  if ( not ErrorAfterOnePushAndOnePop( SingleList<int>() )) {
      std::cout << "\t-- ErrorAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_3( SingleList<int>() )) {
      std::cout << "\t-- InsertAtIndex_3 \t FAIL" << '\n';
      return -1;
  }


  std::cout << "--- Circular Single List Test" << '\n';
  if ( not LengthCeroAtEmptyConstruction( CircularSingleList<int>() ) ) {
      std::cout << "\t-- LengthCeroAtEmptyConstruction \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthGreaterThanCeroAtConstructionWithInitializerList( CircularSingleList<int>({1, 2}) ) ) {
      std::cout << "\t-- LengthGreaterThanCeroAtConstructionWithInitializerList \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthEqualToOneAfterOnePushBack( CircularSingleList<int>() )) {
      std::cout << "\t-- LengthEqualToOneAfterOnePushBack \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthBackToCeroAfterOnePushAndOnePop( CircularSingleList<int>() )) {
      std::cout << "\t-- LengthBackToCeroAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthAfterThreePush( CircularSingleList<int>() )) {
      std::cout << "\t-- LengthAfterThreePush \t FAIL" << '\n';
      return -1;
  }

  if ( not ErrorAfterOnePushAndOnePop( CircularSingleList<int>() )) {
      std::cout << "\t-- ErrorAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }


  std::cout << "--- Double List Test" << '\n';
  if ( not LengthCeroAtEmptyConstruction( SingleList<int>() ) ) {
      std::cout << "\t-- LengthCeroAtEmptyConstruction \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthGreaterThanCeroAtConstructionWithInitializerList( SingleList<int>({1, 2}) ) ) {
      std::cout << "\t-- LengthGreaterThanCeroAtConstructionWithInitializerList \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthEqualToOneAfterOnePushBack( SingleList<int>() )) {
      std::cout << "\t-- LengthEqualToOneAfterOnePushBack \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthBackToCeroAfterOnePushAndOnePop( SingleList<int>() )) {
      std::cout << "\t-- LengthBackToCeroAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthAfterThreePush( SingleList<int>() )) {
      std::cout << "\t-- LengthAfterThreePush \t FAIL" << '\n';
      return -1;
  }

  if ( not ErrorAfterOnePushAndOnePop( SingleList<int>() )) {
      std::cout << "\t-- ErrorAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }


  std::cout << '\n'
            << "\t ----------------------" << '\n'
            << "\t    ALL TEST SUCCEDED  " << '\n'
            << "\t ----------------------" << '\n';
  return 0;
}
