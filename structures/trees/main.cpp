#include "binary_search_tree.h"
#include "red_black_tree.h"
#include "avl_tree.h"
#include "unit_test.h"

#include <iostream>

int main(int argc, char* args[])
{
  // Binary Search Tree Especific Test
  std::cout << "-- Binary Search Tree" << '\n';
  if ( not SizeCeroAtEmptyConstruction( BinarySearchTree<int>() ) ) {
    std::cout << "\t-- SizeCeroAtEmptyConstruction \t FAIL" << '\n';
    return -1;
  }

  if ( not SizeGreaterThanCeroAtConstructionWithInitializerList(
        BinarySearchTree<int>({2,1,3}) ) )
  {
    std::cout << "\t-- SizeGreaterThanCeroAtConstructionWithInitializerList"
              << "\t FAIL" << '\n';
    return -1;
  }

  if ( not SizeEqualToOneAfterOneInsert( BinarySearchTree<int>() ) ) {
    std::cout << "\t-- SizeEqualToOneAfterOneInsert \t FAIL" << '\n';
    return -1;
  }

  if ( not SizeAfterThreeInsert( BinarySearchTree<int>() ) ) {
    std::cout << "\t-- SizeAfterThreeInsert \t FAIL" << '\n';
    return -1;
  }

  if ( not TransplantRootLeftChildWithRootRightChild(
        BinarySearchTree<int>() ) )
  {
    std::cout << "\t-- TransplantRootLeftChildWithRootRightChild"
              << "\t FAIL" << '\n';
    return -1;
  }

  if ( not GetMinimunNodeStartingFromRoot( BinarySearchTree<int>() ) ) {
    std::cout << "\t-- GetMinimunNodeStartingFromRoot \t FAIL" << '\n';
    return -1;
  }

  if ( not SizeBackToCeroAfterOneInsertAndOneErase(
        BinarySearchTree<int>() ) )
  {
    std::cout << "\t-- SizeBackToCeroAfterOneInsertAndOneErase \t FAIL" << '\n';
    return -1;
  }

  if ( not SizeCeroAfterInsertAndTwoErase( BinarySearchTree<int>() ) ) {
    std::cout << "\t-- SizeCeroAfterInsertAndTwoErase \t FAIL" << '\n';
    return -1;
  }

  // Red Black Tree Especific Test
  std::cout << "-- Red Black Tree" << '\n';
  if ( not RightRotateLevel_2_Right( RedBlackTree<int>() ) ) {
    std::cout << "\t-- RightRotateLevel_2_Right \t FAIL" << '\n';
    return -1;
  }

  if ( not InsertAndBalance_4_Levels( RedBlackTree<int>() ) ) {
    std::cout << "\t-- InsertAndBalance_4_Levels \t FAIL" << '\n';
    return -1;
  }

  // AVL Tree Especific Test
  std::cout << "-- AVL Tree<< '\n';
  if ( not SizeCeroAtEmptyConstruction( AvlTree<int>() ) ) {
    std::cout << "\t-- SizeCeroAtEmptyConstruction \t FAIL" << '\n';
    return -1;
  }

  std::cout << '\n'
            << "\t ----------------------" << '\n'
            << "\t    ALL TEST SUCCEDED  " << '\n'
            << "\t ----------------------" << '\n';
  return 0;
}
