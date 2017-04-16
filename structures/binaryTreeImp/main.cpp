#include <iostream>
#include <memory>

// Own Classes
#include "BinaryTree.h"

int main(int argsc, char** args)
{
    std::unique_ptr<BinaryTree> binaryTree = std::unique_ptr<BinaryTree>(new BinaryTree());

    binaryTree->Insert(10);
    binaryTree->Insert(5);
    binaryTree->Insert(15);
    binaryTree->Insert(13);
    binaryTree->Insert(20);
    binaryTree->Insert(11);
    binaryTree->Insert(14);

    std::cout << "Number of Nodes : " << binaryTree->GetNumberOfElements() << "\n";
    binaryTree->ShowElements();

    return 0;
}
