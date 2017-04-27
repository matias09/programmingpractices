#include <string.h>
#include <iostream>
#include <memory>

// Own Classes
#include "BinaryTree.h"

int main(int argsc, char** args)
{
  // ---------------------------------------------------------- //
  // We must test with a lot of cases, the Erase() method.
  // In some cases we are accessing a Null Ptr
  // ---------------------------------------------------------- //

  int n;
  std::unique_ptr<BinaryTree> binaryTree = std::unique_ptr<BinaryTree>(new BinaryTree());

  // For the moment the half of the
  // balance algorithm is working
  // with natural numbers in the tree.
  // I have to test it with negatives numbers
  // for to see if this BLOW UP THROUGH THE AIR
  binaryTree->Insert(100);
  binaryTree->Insert(60);
  binaryTree->Insert(40);
  binaryTree->Insert(90);
  binaryTree->Insert(30);
  binaryTree->Insert(50);
  binaryTree->Insert(70);
  binaryTree->Insert(95);

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
    std::cout << "Next number to erase : ";
    std::cin >> n;
    std::cout << "\n \n";
  }


  // I'm leaking memory as a champion, but is
  // a improvement that i will do soon

  return 0;
}
