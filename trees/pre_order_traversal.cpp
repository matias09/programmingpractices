#include <forward_list>
#include <iostream>

class Tree {
public:
  Tree() = default;
  Tree(int param_n) : n(param_n) {}

  int n = 0;
  Tree *lower = nullptr;
  Tree *greater = nullptr;
};

void Insert(Tree *head, const int e) {
  if (head == nullptr)
    head = new Tree(e);
  else if (e < head->n) {
    if (head->lower == nullptr)
      head->lower = new Tree(e);
    else
      Insert(head->lower, e);
  } else {
    if (head->greater == nullptr)
      head->greater = new Tree(e);
    else
      Insert(head->greater, e);
  }
}

void ReleaseValues(Tree *head) {
  if (head != nullptr) {
    if (head->lower != nullptr)
      ReleaseValues(head->lower);

    if (head->greater != nullptr)
      ReleaseValues(head->greater);

    delete head;
  }
}

void PrintInPreOrderTraversal(const Tree &current) {
  if (current.lower != nullptr) {
    PrintInPreOrderTraversal(*current.lower);
    std::cout << "L-45 >>  ";
    std::cout << current.n << " , \n";
  } else {
    std::cout << "L-48 >>  ";
    std::cout << current.n << " , \n";
    return;
  }

  if (current.greater != nullptr) {
    PrintInPreOrderTraversal(*current.greater);
  } else {
    std::cout << "L-56 >>  ";
    std::cout << current.n << " , \n";
  }
}

int main() {
  Tree *tree = new Tree(100);

  //std::forward_list<int> values = {30, 4, 5, 6, 47, 7, 22, 11, 50, 54, 3};
  std::forward_list<int> values = {
    100,
    50, 150,
    40, 60, 140, 160,
    30, 45,55,70,130, 145, 155,170};

  for (auto &e : values)
    Insert(tree, e);

  PrintInPreOrderTraversal(*tree);

  ReleaseValues(tree);
  return 0;
}
