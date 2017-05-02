#include <string.h>
#include <iostream>
#include <memory>

// Own Classes
#include "BinaryTree.h"

int main(int argsc, char** args)
{
  // ---------------------------------------------------------- //
  // Erase Method seems to work, But I have to be sure if
  // Visual Studio is not lying to me, so I have to be sure with
  // Clang compiler.
  // Another thing, is that I have to separate that nasty If Nodes.
  // That is very wrong I know, but first has to work.
  //
  // Cheers.
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
//  binaryTree->Insert(90);
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
