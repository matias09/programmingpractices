// ------------------------- T O D O  T H I N G S --------------------------------------------------------------- //
// TODO : Improve EraseNode() Method because there are to many IF statements. Try to separate in more functions
// TODO : Finish the ProcessVerticalBalance() Method to finish the AVL Tree
// TODO : Create the ReleaseNodesFromMemory() Method to clean the Heap from Node Garbage and not Leak Memory
// TODO : Create test files
// ------------------------- T O D O  T H I N G S --------------------------------------------------------------- //
#include <string.h>
#include <iostream>
#include <memory>

// Own Classes
#include "BinaryTree.h"

int main(int argsc, char** args)
{
  int n;
  std::unique_ptr<BinaryTree> binaryTree = std::unique_ptr<BinaryTree>(new BinaryTree());

  binaryTree->Insert(100);
  binaryTree->Insert(60);
  binaryTree->Insert(40);
  binaryTree->Insert(90);
//  binaryTree->Insert(30);
//  binaryTree->Insert(50);
//  binaryTree->Insert(95);
//  binaryTree->Insert(70);

  std::cout << "Number of Nodes : " << binaryTree->GetNumberOfElements() << "\n";
  binaryTree->ShowElements();

  std::cout << "\n \n";
  std::cout << "Number to Erase (-1) to exit : ";
  std::cin >> n;
  std::cout << "\n \n";

  while (n != -1)
  {
    binaryTree->Erase(n);

    std::cout << "\n \n";
    std::cout << "Number of Nodes : " << binaryTree->GetNumberOfElements() << "\n";
    binaryTree->ShowElements();

    std::cout << "\n \n";
    std::cout << "Number to Erase (-1) to exit : ";
    std::cin >> n;
    std::cout << "\n \n";
  }

  // I'm leaking memory as a champion, but is
  // an improvement that i will do soon

  return 0;
}
