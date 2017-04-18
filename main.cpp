#include <iostream>
#include <memory>

// Own Classes
#include "BinaryTree.h"

int main(int argsc, char** args)
{
    std::unique_ptr<BinaryTree> binaryTree = std::unique_ptr<BinaryTree>(new BinaryTree());

    // For the moment the half of the
    // balance algorithm is working
    // with natural numbers in the tree.
    // I have to test it with negatives numbers
    // for to if this BLOW UP THROUGH THE AIR
    binaryTree->Insert(10);
    binaryTree->Insert(5);
    binaryTree->Insert(15);
    binaryTree->Insert(13);
    binaryTree->Insert(19);
    binaryTree->Insert(22);
    binaryTree->Insert(23);
    binaryTree->Insert(20);
    binaryTree->Insert(11);
    binaryTree->Insert(14);

    std::cout << "Number of Nodes : " << binaryTree->GetNumberOfElements() << "\n";
    binaryTree->ShowElements();

    // I'm leaking memory as a champion, but is
    // a improvement that i will do soon

    return 0;
}
