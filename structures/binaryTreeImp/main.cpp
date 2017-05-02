#include <string.h>
#include <iostream>
#include <memory>

// Own Classes
#include "BinaryTree.h"

int main(int argsc, char** args)
{
  // ---------------------------------------------------------- //
  // Erase Method seems to work, but for some unknown reason
  // when I delete the last node is leaving the node in some
  // unconsistance
  // Another thing, is that I have to separate that nasty If Nodes.
  // That is very wrong I know, but first has to work.
  //
  // Cheers.
  // ---------------------------------------------------------- //

  int n;
  std::unique_ptr<BinaryTree> binaryTree = std::unique_ptr<BinaryTree>(new BinaryTree());

  binaryTree->Insert(-100);
  binaryTree->Insert(-60);
//  binaryTree->Insert(-40);
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
