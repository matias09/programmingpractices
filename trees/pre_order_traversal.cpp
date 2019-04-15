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

void PrintInPreOrderTraversal(const Tree &head)
{
  if (head.lower != nullptr) {
    PrintInPreOrderTraversal(head.lower);
    std::cout << head.n << " , ";
  } else {
    std::cout << head.n << " , ";
  }
}

int main() {
  Tree *tree = new Tree(100);

  std::forward_list<int> values = {30, 4, 5, 6, 47, 7, 22, 11, 50, 54, 3};

  for (auto &e : values)
    Insert(tree, e);

  ReleaseValues(tree);
  return 0;
}
