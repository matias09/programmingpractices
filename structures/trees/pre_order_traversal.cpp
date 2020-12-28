#include <iostream>

#include "TreeNodeHandler.h"

void PrintInPreOrderTraversal(const TreeNode &current) {
  std::cout << current.val << ", ";

  if (current.left != NULL)
    PrintInPreOrderTraversal(*current.left);

  if (current.right != NULL)
    PrintInPreOrderTraversal(*current.right);
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
    PrintInPreOrderTraversal( *tree );
  }

#ifdef DEBUG
  std::cout << '\n';
#endif
}
