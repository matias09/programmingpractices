#include <forward_list>
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

std::vector<int> PreOrderTraversalIter(Tree *head)
{
  if (head == nullptr) return std::vector<int>({});

  // Safe Guard
  int i = -1;

  Tree *tmp_node = head;
  std::vector<int> res = {};
  std::stack<Tree *> tree_ptrs;
  size_t size_tree_ptrs = 0;

  tree_ptrs.push(tmp_node);

  for (;;) {
    if (size_tree_ptrs < tree_ptrs.size()) {
      if (tmp_node->lower != nullptr) {
        tree_ptrs.push(tmp_node->lower);
        ++size_tree_ptrs;

        tmp_node = tmp_node->lower;
        continue;
      } else {
        if (tmp_node->greater != nullptr) {
          tree_ptrs.push(tmp_node->greater);
          ++size_tree_ptrs;

          tmp_node = tmp_node->greater;
          continue;
        } else {
          res.push_back(tmp_node->n);
          tmp_node = tree_ptrs.top();
          tree_ptrs.pop();
        }
      }
    } else {

      // TODO: This is not quite Right, becouse
      // you are not saving the root node
      // when you previusly save the lower child node.
      //
      // Think about that. How to Save the
      // right node.
      if (tmp_node->greater != nullptr) {
        tree_ptrs.push(tmp_node->greater);

        tmp_node = tmp_node->greater;
        continue;
      } else {
        res.push_back(tmp_node->n);
        tmp_node = tree_ptrs.top();
        tree_ptrs.pop();
      }
    }

    if (tree_ptrs.size() == 0) break;

    // Safe Guard to prevent Inf Loop
    if ((++i) > 500) {
      std::cout << "I go out thanks to \"i\" local variable . . . \n";
      break;
    }
  }

  return res;
}

int main() {
  Tree *tree = new Tree(100);

  std::forward_list<int> values = {100, 50, 25, 75, 60, 80, 20, 30, 150, 125, 175, 160, 180, 120, 130};

  for (auto &e : values)
    Insert(tree, e);

  ReleaseValues(tree);
  return 0;
}
