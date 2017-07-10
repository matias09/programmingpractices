#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct Node
{
  Node(unsigned int pn) : n(pn)
  {
    mLeftDirectionTaken = false;
    mRightDirectionTaken = false;
    mLevelInGreatestSide = 0;
    mLevelInLowestSide = 0;
    mLower = nullptr;
    mGreater = nullptr;
  }
  ~Node(){}

  bool mLeftDirectionTaken;
  bool mRightDirectionTaken;
  unsigned int mLevelInGreatestSide;
  unsigned int mLevelInLowestSide;
  int n;
  Node* mLower;
  Node* mGreater;
} Node;

class BinaryTree
{
  public:
    BinaryTree();
    ~BinaryTree();

    const unsigned int GetNumberOfElements() const { return mCount; }
    void Insert(const int n);
    void ShowElements();
    void ReleaseTree();
    bool Erase(const int n);
    Node* Find(const int n);
  private:
    static const int VERTICAL_CONDITION = 2;
    static const unsigned int START_POINT_VERTICAL_LEVEL = 1;
    static const unsigned int NODE_AMOUNT_TO_CHECK_BALANCE = 3;

    void ShowNode(Node* node);
    void SaveNode(Node* node, const int n);
    void ProcessBalance(Node* newHeadNode);
    void ReleaseNode(Node* node);
    void ReleaseNodesRecursively(Node* node);
    bool EraseNode(Node* node, Node& previousNode, const int n);
    Node* FindNode(Node& startNode, const int& n);
    Node* FindPrevNode(Node& startNode, const int& n);
    Node* GetLowestNodeFromThisNode(Node* node);
    Node* GetGreatestNodeFromThisNode(Node* node);

    unsigned int mCount;
    Node* mHeadNode;
};

#endif // BINARY_TREE
