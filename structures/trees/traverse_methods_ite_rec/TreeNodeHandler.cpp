#include <algorithm>
#include <cmath>
#include <stdlib.h>

#include "TreeNodeHandler.h"

void TreeNodeHandler::Insert(const std::vector<int32_t> &elms)
{
  auto itb = elms.begin();
  auto ite = elms.end();

  std::for_each(itb, ite, [&] (const int32_t e){ Insert(e); });
}

void TreeNodeHandler::Insert(const int32_t e) {
  if (n == NULL) {
    n = new TreeNode(e);
  } else {
    InsertValue(*n, e);
  }
}

void TreeNodeHandler::InsertValue(TreeNode &head, const int32_t e) {
  if (e < head.val) {
    if (head.left == NULL) {
      head.left = new TreeNode(e);
    } else {
      InsertValue( *(head.left), e);
    }
  } else {
    if (head.right == NULL) {
      head.right = new TreeNode(e);
    } else {
      InsertValue( *(head.right), e);
    }
  }
}

void TreeNodeHandler::ReleaseValues(TreeNode *n){
  if (n != NULL) {
    if (n->left != NULL)
      ReleaseValues(n->left);

    if (n->right != NULL)
      ReleaseValues(n->right);

    delete n;
  }
}

void TreeNodeHandler::FillByLevel(const std::vector<int32_t> &values)
{
  uint16_t nodesize = values.size();
  std::vector<TreeNode*> nodes(nodesize, NULL);

  auto itB = values.begin();
  auto itE = values.end();

  uint16_t i = 0;
  std::for_each (itB, itE, [&] (const int32_t &v) {
    nodes[++i - 1] = new TreeNode(v);
  });

  n = FillNodes(nodes);
}

void TreeNodeHandler::FillByLevel(const std::vector<std::string> &values)
{
  uint16_t nodesize = values.size();
  std::vector<TreeNode*> nodes(nodesize, NULL);

  auto itB = values.begin();
  auto itE = values.end();

  uint16_t i = 0;
  std::for_each (itB, itE, [&] (const std::string &v) {
    if (v[0] != 'n' && v[0] != 'N') {
      nodes[i] = new TreeNode( atoi( v.c_str() ) );
    }
    ++i;
  });

  n = FillNodes(nodes);
}

void TreeNodeHandler::FillByLevel(const std::vector<const char*> &values)
{
  uint16_t nodesize = values.size();
  std::vector<TreeNode*> nodes(nodesize, NULL);

  auto itB = values.begin();
  auto itE = values.end();

  uint16_t i = 0;
  std::for_each (itB, itE, [&] (const char *v) {
    if ( v[0] != 'n' && v[0] != 'N') {
      nodes[i] = new TreeNode( atoi(v) );
    }
    ++i;
  });

  n = FillNodes(nodes);
}

void TreeNodeHandler::FillByLevel(const uint16_t size, const char* values[])
{
  uint16_t nodesize = size - 1;
  std::vector<TreeNode*> nodes(nodesize, NULL);

  for (uint16_t i = 0; i < nodesize; ++i) {
    if ( values[i + 1][0] != 'n' && values[i + 1][0] != 'N') {
      nodes[i] = new TreeNode( atoi( values[i + 1] ) );
    }
  }

  n = FillNodes(nodes);
}

TreeNode* TreeNodeHandler::FillNodes(std::vector<TreeNode*> &nodes)
{
  TreeNode *current_head = NULL;

  uint16_t nodesize = nodes.size();
  uint16_t old_nodes = 0;
  uint16_t cur_head_nodes = 0;

  uint8_t cur_level = 0;

  uint8_t cur_head_idx = 0;
  uint8_t cur_chld_idx = 0;
  uint8_t cur_level_limit = 0;

  do
  {
    cur_head_nodes = std::pow(2, cur_level);

    cur_head_idx = old_nodes;
    cur_chld_idx = cur_head_nodes + old_nodes;
    cur_level_limit = cur_chld_idx;

    for (; cur_head_idx < cur_level_limit &&
        cur_head_idx < nodesize; ++cur_head_idx, cur_chld_idx += 2)
    {
      if (nodes[cur_head_idx] == NULL) continue;

      current_head = nodes[cur_head_idx];

      if ( cur_chld_idx < nodesize && nodes[cur_chld_idx] != NULL ) {
        current_head->left = nodes[cur_chld_idx];
      }

      if ( (cur_chld_idx + 1) < nodesize && nodes[cur_chld_idx + 1] != NULL ) {
        current_head->right = nodes[cur_chld_idx + 1];
      }
    }

    old_nodes += cur_head_nodes;
    ++cur_level;
  } while (old_nodes < nodesize);

  return nodes[0];
}
