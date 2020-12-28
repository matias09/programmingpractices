#include "TreeNodeHandler.h"

#include <iostream>

void PrintInPostOrderTraversal(const TreeNode &current) {
  if (current.left != nullptr)
    PrintInPostOrderTraversal(*current.left);

  if (current.right != nullptr)
    PrintInPostOrderTraversal(*current.right);

  std::cout << current.val << ", ";
}

int main() {
  TreeNodeHandler tree_handler;

  std::vector<std::string> values = {
    "100",
    "50", "150",
    "40", "60", "140", "160",
    "30", "45", "55", "70", "130", "145", "155", "170"
  };

  tree_handler.FillByLevel(values);

#ifdef DEBUG
  std::cout << '\n' << '\n'
            << "-- In order function result: "
            << '\n' << '\t';
#endif
  TreeNode *tree = tree_handler.GetTreeNodePtr();

  if (tree) {
    PrintInPostOrderTraversal( *tree );
  }

#ifdef DEBUG
  std::cout << '\n';
#endif
}
