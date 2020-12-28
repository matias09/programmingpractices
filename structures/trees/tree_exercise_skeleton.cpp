#include "TreeNodeHandler.h"

#include <iostream>
#include <algorithm>

#include <vector>

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
    // ns =
  }

#ifdef DEBUG
  std::cout << '\n' << '\n'
            << "-- function result: "
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
