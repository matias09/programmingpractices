#include "vector.h"
#include "unit_test.h"

int main(int argc, char* args[])
{
  if ( not LengthCeroAtEmptyConstruction( Vector<int>() ) ) {
      std::cout << "-- LengthCeroAtEmptyConstruction \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthGreaterThanCeroAtConstructionWithInitializerList( Vector<int>({1, 2}) ) ) {
      std::cout << "-- LengthGreaterThanCeroAtConstructionWithInitializerList \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthEqualToOneAfterOnePushBack( Vector<int>() )) {
      std::cout << "-- LengthEqualToOneAfterOnePushBack \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthBackToCeroAfterOnePushAndOnePop( Vector<int>() )) {
      std::cout << "-- LengthBackToCeroAfterOnePushAndOnePop \t FAIL" << '\n';
      return -1;
  }

  if ( not LengthAfterThreePush( Vector<int>() )) {
      std::cout << "-- LengthAfterThreePush \t FAIL" << '\n';
      return -1;
  }

  if ( not ResizeContainerToDoubleCapacityAfterPushTheLimits( Vector<int, 3>() )) {
      std::cout << "-- ResizeContainerToDoubleCapacityAfterPushTheLimits \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_Minus_1( Vector<int, 3>() )) {
      std::cout << "-- InsertAtIndex_Minus_1 \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_0_OnEmptyContainer( Vector<int, 3>() )) {
      std::cout << "-- InsertAtIndex_0_OnEmptyContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_1_OnContainerWithLength_3( Vector<int, 3>() )) {
      std::cout << "-- InsertAtIndex_1_OnContainerWithLength_3 \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_8_OnFullContainer( Vector<int>() )) {
      std::cout << "-- InsertAtIndex_8_OnFullContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_0_OnFullContainer( Vector<int>() )) {
      std::cout << "-- InsertAtIndex_0_OnFullContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_5_OnAlmostFullContainer( Vector<int>() )) {
      std::cout << "-- InsertAtIndex_5_OnAlmostFullContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_0_OnEmptyContainer( Vector<int>() )) {
      std::cout << "-- EraseAtIndex_0_OnEmptyContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_0_OnContainerWithOneElement( Vector<int>() )) {
      std::cout << "-- EraseAtIndex_0_OnContainerWithOneElement \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_0_OnContainerWithTwoElement( Vector<int>() )) {
      std::cout << "-- EraseAtIndex_0_OnContainerWithTwoElement \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtLastIndexOnFullContainer( Vector<int>() )) {
      std::cout << "-- EraseAtLastIndexOnFullContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not ReverseEmptyContainer( Vector<int>() )) {
      std::cout << "-- ReverseEmptyContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not ReverseContainerFrom_1_to_3( Vector<int>() )) {
      std::cout << "-- ReverseContainerFrom_1_to_3 \t FAIL" << '\n';
      return -1;
  }

  if ( not LeftRotateEmptyContainer( Vector<int>() )) {
      std::cout << "-- LeftRotateEmptyContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not LeftRotateContainerFrom_1_to_5( Vector<int>() )) {
      std::cout << "-- LeftRotateContainerFrom_1_to_5 \t FAIL" << '\n';
      return -1;
  }

  if ( not RigthRotateEmptyContainer( Vector<int>() )) {
      std::cout << "-- RigthRotateEmptyContainer \t FAIL" << '\n';
      return -1;
  }

  if ( not RightRotateContainerFrom_1_to_5( Vector<int>() )) {
      std::cout << "-- RightRotateContainerFrom_1_to_5 \t FAIL" << '\n';
      return -1;
  }

  std::cout << "\t ALL TEST SUCCEDED "<< '\n';
  return 0;
}
