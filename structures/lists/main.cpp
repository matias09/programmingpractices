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

  if ( not InsertAtIndex_0_AtTheBeggining( SingleList<int>() )) {
      std::cout << "\t-- InsertAtIndex_0_AtTheBeggining \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_3_InTheMiddle( SingleList<int>() )) {
      std::cout << "\t-- InsertAtIndex_3_InTheMiddle \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_5_AtTheEnd( SingleList<int>() )) {
      std::cout << "\t-- InsertAtIndex_5_AtTheEnd \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_0_WithNoElements( SingleList<int>() )) {
      std::cout << "\t-- EraseAtIndex_0_WithNoElements \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_0_WithElements( SingleList<int>() )) {
      std::cout << "\t-- EraseAtIndex_0_WithElements \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_3_BetweenOriginAndEnd( SingleList<int>() )) {
      std::cout << "\t-- EraseAtIndex_3_BetweenOriginAndEnd \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_5_AtTheEnd( SingleList<int>() )) {
      std::cout << "\t-- EraseAtIndex_5_AtTheEnd \t FAIL" << '\n';
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

  if ( not InsertAtIndex_0_AtTheBeggining( CircularSingleList<int>() )) {
      std::cout << "\t-- InsertAtIndex_0_AtTheBeggining \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_3_InTheMiddle( CircularSingleList<int>() )) {
      std::cout << "\t-- InsertAtIndex_3_InTheMiddle \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_5_AtTheEnd( CircularSingleList<int>() )) {
      std::cout << "\t-- InsertAtIndex_5_AtTheEnd \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_0_AtTheBeggining( CircularSingleList<int>() )) {
      std::cout << "\t-- InsertAtIndex_0_AtTheBeggining \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_3_InTheMiddle( CircularSingleList<int>() )) {
      std::cout << "\t-- InsertAtIndex_3_InTheMiddle \t FAIL" << '\n';
      return -1;
  }

  if ( not InsertAtIndex_5_AtTheEnd( CircularSingleList<int>() )) {
      std::cout << "\t-- InsertAtIndex_5_AtTheEnd \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_0_WithNoElements( CircularSingleList<int>() )) {
      std::cout << "\t-- EraseAtIndex_0_WithNoElements \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_0_WithElements( CircularSingleList<int>() )) {
      std::cout << "\t-- EraseAtIndex_0_WithElements \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_3_BetweenOriginAndEnd( CircularSingleList<int>() )) {
      std::cout << "\t-- EraseAtIndex_3_BetweenOriginAndEnd \t FAIL" << '\n';
      return -1;
  }

  if ( not EraseAtIndex_5_AtTheEnd( CircularSingleList<int>() )) {
      std::cout << "\t-- EraseAtIndex_5_AtTheEnd \t FAIL" << '\n';
      return -1;
  }


  // std::cout << "--- Double List Test" << '\n';
  // if ( not LengthCeroAtEmptyConstruction( DoubleList<int>() ) ) {
  //     std::cout << "\t-- LengthCeroAtEmptyConstruction \t FAIL" << '\n';
  //     return -1;
  // }
  //
  // if ( not LengthGreaterThanCeroAtConstructionWithInitializerList( DoubleList<int>({1, 2}) ) ) {
  //     std::cout << "\t-- LengthGreaterThanCeroAtConstructionWithInitializerList \t FAIL" << '\n';
  //     return -1;
  // }
  //
  // if ( not LengthEqualToOneAfterOnePushBack( DoubleList<int>() )) {
  //     std::cout << "\t-- LengthEqualToOneAfterOnePushBack \t FAIL" << '\n';
  //     return -1;
  // }
  //
  // if ( not LengthBackToCeroAfterOnePushAndOnePop( DoubleList<int>() )) {
  //     std::cout << "\t-- LengthBackToCeroAfterOnePushAndOnePop \t FAIL" << '\n';
  //     return -1;
  // }
  //
  // if ( not LengthAfterThreePush( DoubleList<int>() )) {
  //     std::cout << "\t-- LengthAfterThreePush \t FAIL" << '\n';
  //     return -1;
  // }
  //
  // if ( not ErrorAfterOnePushAndOnePop( DoubleList<int>() )) {
  //     std::cout << "\t-- ErrorAfterOnePushAndOnePop \t FAIL" << '\n';
  //     return -1;
  // }


  std::cout << '\n'
            << "\t ----------------------" << '\n'
            << "\t    ALL TEST SUCCEDED  " << '\n'
            << "\t ----------------------" << '\n';
  return 0;
}
