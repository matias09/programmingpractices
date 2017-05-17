#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct Node
{
  Node(unsigned int pn) : n(pn)
  {
    mLeftDirectionTaken = false;
    mRightDirectionTaken = false;
    mLower = nullptr;
    mGreater = nullptr;
  }
  ~Node(){}

  bool mLeftDirectionTaken;
  bool mRightDirectionTaken;
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
    void SaveNode(Node* node, const int n, unsigned int& levelCounter);
    void ProcessVerticalBalance();
    void MakeVerticalChanges(Node* avgNode);
    void CalculateTotalNodesValues(Node* node, int& total);
    void ReleaseNode(Node* node);
    void ReleaseNodesRecursively(Node* node);
    void UpdateHighestLowestNode(const int n);
    bool WasBalanceProcessMade();
    bool EraseNode(Node* node, Node& previousNode, const int n);
    Node* FindNode(Node& startNode, const int& n);
    Node* FindPrevNode(Node& startNode, const int& n);
    Node* GetLowestNodeFromThisNode(Node* node);
    Node* GetGreatestNodeFromThisNode(Node* node);
    Node* GetAverageNode();

    int mCountLowestNumbers;
    int mCountGreatestNumbers;
    unsigned int mCount;
    int mHighestNodeValue;
    int mLowestNodeValue;
    Node* mHeadNode;
};

#endif // BINARY_TREE
