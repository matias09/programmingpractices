#include "TreeNodeHandler.h"

#include <iostream>
#include <algorithm>

#include <vector>
#include <stack>

std::vector<int32_t> PreOrderTraversalIte(TreeNode *head) {
  if (head == nullptr) return std::vector<int32_t>({});

  TreeNode *tmp_node = head;
  std::vector<int32_t> res;
  std::vector<uint8_t> tracked_nodes;
  std::stack<TreeNode *> stack_tree_ptrs;

  res.push_back(head->val);

  do {
    if (tmp_node->left != nullptr) {
      stack_tree_ptrs.push(tmp_node);

      tracked_nodes.emplace_back('L');

      tmp_node = tmp_node->left;
      res.emplace_back(tmp_node->val);

      continue;
    }

    if (tmp_node->right != nullptr) {
      stack_tree_ptrs.push(tmp_node);
      tracked_nodes.emplace_back('R');

      tmp_node = tmp_node->right;
      res.emplace_back(tmp_node->val);

      continue;
    }

    for (int16_t j = tracked_nodes.size() - 1; j > -1; --j) {
      tmp_node = stack_tree_ptrs.top();

      if (tracked_nodes[j] == 'L' && tmp_node->right != nullptr) {
        tracked_nodes[j] = 'R';

        tmp_node = tmp_node->right;
        res.push_back(tmp_node->val);

        break;
      } else {
        stack_tree_ptrs.pop();
        tracked_nodes.pop_back();
      }
    }

  } while ( ! stack_tree_ptrs.empty() );

  return res;
}

int main(int argc, const char *args[])
{
  TreeNodeHandler tree_handler;
  std::vector<int32_t> ns;

  if (argc > 1) {
    tree_handler.FillByLevel(argc, args);
  } else {
    std::vector<std::string> values = {
      "100",
      "50", "150",
      "40", "60", "140", "160",
      "30", "45", "55", "70", "130", "145", "155", "170"
    };

    tree_handler.FillByLevel(values);
  }

  TreeNode *tree = tree_handler.GetTreeNodePtr();

  if (tree) {
    ns = PreOrderTraversalIte( tree );
  }

#ifdef DEBUG
  std::cout << '\n' << '\n'
            << "-- In order function result: "
            << '\n' << '\t';
#endif

  auto itB = ns.begin();
  auto itE = ns.end();

  std::for_each(itB, itE, [&](const uint32_t n) {
    std::cout << n << ' ';
  });

#ifdef DEBUG
  std::cout << '\n';
#endif
}
