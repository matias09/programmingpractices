/*
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
*/

#include "TreeNodeHandler.h"

#include <iostream>
#include <algorithm>

#include <vector>
#include <stack>

std::vector<std::vector<int32_t>> levelOrder(TreeNode *head)
{
  if (head == nullptr) return std::vector<std::vector<int32_t>>( {} );

  TreeNode *tmp_node = head;
  std::vector<std::vector<int32_t>> res = { {tmp_node->val} };
  std::vector<uint8_t> tracked_nodes;
  std::stack<TreeNode *> stack_tree_ptrs;

  uint16_t cur_lev = 0;

  do {
    if (tmp_node->left != nullptr) {
      ++cur_lev;

      stack_tree_ptrs.push(tmp_node);
      tracked_nodes.emplace_back('L');

      tmp_node = tmp_node->left;

      if ( cur_lev == res.size() ) {
        res.push_back( {tmp_node->val} );
      } else {
        res[cur_lev].push_back(tmp_node->val);
      }

      continue;
    }

    if (tmp_node->right != nullptr) {
      ++cur_lev;

      stack_tree_ptrs.push(tmp_node);
      tracked_nodes.emplace_back('R');

      tmp_node = tmp_node->right;

      if ( cur_lev == res.size() ) {
        res.push_back( {tmp_node->val} );
      } else {
        res[cur_lev].emplace_back(tmp_node->val);
      }

      continue;
    }

    for (int16_t j = tracked_nodes.size() - 1; j > -1; --j) {
      tmp_node = stack_tree_ptrs.top();
      --cur_lev;

      if (tracked_nodes[j] == 'L') {
        tracked_nodes[j] = 'R';

        if (tmp_node->right != nullptr) {
          tmp_node = tmp_node->right;

          ++cur_lev;
          if ( cur_lev == res.size() ) {
            res.push_back( {tmp_node->val} );
          } else {
            res[cur_lev].emplace_back(tmp_node->val);
          }
        } else {
          stack_tree_ptrs.pop();
          tracked_nodes.pop_back();

          continue;
        }

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
  std::vector<std::vector<int32_t>> ns;

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
    ns = levelOrder(tree);
  }

#ifdef DEBUG
  std::cout << '\n' << '\n'
            << "-- function result: "
            << '\n' << '\t';
#endif

  auto itB = ns.begin();
  auto itE = ns.end();

  std::for_each(itB, itE, [&](const std::vector<int32_t> vals) {
    auto itB_2 = vals.begin();
    auto itE_2 = vals.end();

    std::for_each(itB_2, itE_2, [&](const int32_t n) {
      std::cout << n << ',';
    });

    std::cout << '\n';
  });

#ifdef DEBUG
  std::cout << '\n';
#endif
}
