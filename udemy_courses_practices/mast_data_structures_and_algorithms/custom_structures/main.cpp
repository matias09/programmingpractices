#include "array.h"


int main(int argc, char* args[])
{
  if ( not LengthCeroAtEmptyConstruction( Array<int>() ) ) {
      std::cout << "-- LengthCeroAtEmptyConstruction \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthGreaterThanCeroAtConstructionWithInitializerList( Array<int>({1, 2}) ) ) {
      std::cout << "-- LengthGreaterThanCeroAtConstructionWithInitializerList \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthEqualToOneAfterOnePushBack( Array<int>() )) {
      std::cout << "-- LengthEqualToOneAfterOnePushBack \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthBackToCeroAfterOnePushAndOnePop( Array<int>() )) {
      std::cout << "-- LengthBackToCeroAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthAfterThreePush( Array<int>() )) {
      std::cout << "-- LengthAfterThreePush \t FAIL" << '\n';
      return -1;
  }

  if ( not ResizeContainerToDoubleCapacityAfterPushTheLimits( Array<int, 3>() )) {
      std::cout << "-- ResizeContainerToDoubleCapacityAfterPushTheLimits \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_Minus_1( Array<int, 3>() )) {
      std::cout << "-- InsertAtIndex_Minus_1 \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_0_OnEmptyContainer( Array<int, 3>() )) {
      std::cout << "-- InsertAtIndex_0_OnEmptyContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_1_OnContainerWithLength_3( Array<int, 3>() )) {
      std::cout << "-- InsertAtIndex_1_OnContainerWithLength_3 \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_8_OnFullContainer( Array<int>() )) {
      std::cout << "-- InsertAtIndex_8_OnFullContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_0_OnFullContainer( Array<int>() )) {
      std::cout << "-- InsertAtIndex_0_OnFullContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_5_OnAlmostFullContainer( Array<int>() )) {
      std::cout << "-- InsertAtIndex_5_OnAlmostFullContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_0_OnEmptyContainer( Array<int>() )) {
      std::cout << "-- EraseAtIndex_0_OnEmptyContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_0_OnContainerWithOneElement( Array<int>() )) {
      std::cout << "-- EraseAtIndex_0_OnContainerWithOneElement \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_0_OnContainerWithTwoElement( Array<int>() )) {
      std::cout << "-- EraseAtIndex_0_OnContainerWithTwoElement \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtLastIndexOnFullContainer( Array<int>() )) {
      std::cout << "-- EraseAtLastIndexOnFullContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not ReverseEmptyContainer( Array<int>() )) {
      std::cout << "-- ReverseEmptyContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not ReverseContainerFrom_1_to_3( Array<int>() )) {
      std::cout << "-- ReverseContainerFrom_1_to_3 \t FAIL" << '\n';
      return -1;
  }

  std::cout << "\t ALL TEST SUCCEDED "<< '\n';
  return 0;
}
