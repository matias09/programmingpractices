#include "red_black_tree.h"
#include "unit_test.h"

#include <iostream>

int main(int argc, char* args[])
{
  if ( not SizeCeroAtEmptyConstruction( RedBlackTree<int>() ) ) {
    std::cout << "\t-- SizeCeroAtEmptyConstruction \t FAIL" << '\n';
    return -1;
  }

  if ( not SizeGreaterThanCeroAtConstructionWithInitializerList( RedBlackTree<int>({2,1,3}) ) ) {
    std::cout << "\t-- SizeGreaterThanCeroAtConstructionWithInitializerList \t FAIL" << '\n';
    return -1;
  }

  if ( not SizeEqualToOneAfterOneInsert( RedBlackTree<int>() ) ) {
    std::cout << "\t-- SizeEqualToOneAfterOneInsert \t FAIL" << '\n';
    return -1;
  }

  if ( not SizeAfterThreeInsert( RedBlackTree<int>() ) ) {
    std::cout << "\t-- SizeAfterThreeInsert \t FAIL" << '\n';
    return -1;
  }

  if ( not TransplantRootLeftChildWithRootRightChild( RedBlackTree<int>() ) ) {
    std::cout << "\t-- TransplantRootLeftChildWithRootRightChild \t FAIL" << '\n';
    return -1;
  }

  if ( not GetMinimunNodeStartingFromRoot( RedBlackTree<int>() ) ) {
    std::cout << "\t-- GetMinimunNodeStartingFromRoot \t FAIL" << '\n';
    return -1;
  }

  if ( not SizeBackToCeroAfterOneInsertAndOneErase( RedBlackTree<int>() ) ) {
    std::cout << "\t-- SizeBackToCeroAfterOneInsertAndOneErase \t FAIL" << '\n';
    return -1;
  }

  if ( not SizeCeroAfterInsertAndTwoErase( RedBlackTree<int>() ) ) {
    std::cout << "\t-- SizeCeroAfterInsertAndTwoErase \t FAIL" << '\n';
    return -1;
  }

  std::cout << '\n'
            << "\t ----------------------" << '\n'
            << "\t    ALL TEST SUCCEDED  " << '\n'
            << "\t ----------------------" << '\n';
  return 0;
}
