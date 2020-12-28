#include <string>
#include <vector>
#include <cstdint>

struct TreeNode
{
  TreeNode(int32_t param_val) : val(param_val) {}

  int32_t val = 0;
  TreeNode *left  = NULL;
  TreeNode *right = NULL;
};

class TreeNodeHandler
{
public:
   TreeNodeHandler() : n(NULL) {}
  ~TreeNodeHandler(){ ReleaseValues(n); }

  TreeNode* GetTreeNodePtr() const { return n; }
  void Insert(const int32_t e);
  void Insert(const std::vector<int32_t> &elms);

  void FillByLevel(const std::vector<std::string> &values);
  void FillByLevel(const std::vector<const char*> &values);
  void FillByLevel(const std::vector<int32_t> &values);
  void FillByLevel(const uint16_t size, const char* values[]);

private:
  TreeNode* FillNodes(std::vector<TreeNode*> &nodes);

  void InsertValue(TreeNode &head, const int32_t e);
  void ReleaseValues(TreeNode *head);

  TreeNode *n;
};
