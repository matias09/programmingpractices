#include <iostream>
#include <vector>
#include <stack>

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

std::vector<int> PreOrderTraversalIte(Tree *head) {
  if (head == nullptr) return std::vector<int>({});

  // Safe Guard
  int i = -1;

  Tree *tmp_node = nullptr;
  std::vector<int> res;
  std::stack<Tree *> stack_tree_ptrs;

  stack_tree_ptrs.push(head);

  while (i < 500) {
    tmp_node = stack_tree_ptrs.top();

    if (tmp_node->lower != nullptr) {
      stack_tree_ptrs.push(tmp_node->lower);

      ++i;
      continue;
    } else if (tmp_node->greater != nullptr) {
      stack_tree_ptrs.push(tmp_node->greater);

      ++i;
      continue;
    } else {
      // erasing current node from stack
      // to get the Head
      if (stack_tree_ptrs.size() !=  1)
        stack_tree_ptrs.pop();

      tmp_node = stack_tree_ptrs.top();

      res.push_back(tmp_node->n);

      if (tmp_node->lower != nullptr) {
        res.push_back(tmp_node->lower->n);
      }

      stack_tree_ptrs.pop();
    }

    if (tmp_node->greater != nullptr) {
      stack_tree_ptrs.push(tmp_node->greater);

      ++i;
      continue;
    }

    if (stack_tree_ptrs.empty()) break;

    ++i;
  }

  // Safe Guard to prevent Inf Loop
  if (i == 500)
    std::cout << "I go out thanks to \"i\" local variable . . . \n";

  return res;
}

int main() {
  Tree *tree = new Tree(100);

  std::vector<int> values = {
    // 100,
    50, 150,
    40, 60, 140, 160,
    // 30, 45,55,70,130, 145, 155,170
  };

  for (auto &e : values)
    Insert(tree, e);

  std::vector<int> tree_values = PreOrderTraversalIte(tree);

  for (auto &e : tree_values)
    std::cout << e << ", ";

  ReleaseValues(tree);
  return 0;
}
