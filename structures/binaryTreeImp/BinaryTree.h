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
  unsigned int n;
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
    Node* Find(const int n);
  private:
    void ExecuteBalance();
    void ReleaseNodes();
    void ShowNode(Node* node);
    void SaveNode(Node* node, const int n, unsigned int& levelCounter);
    void ProcessVerticalBalance();
    void MakeVerticalChanges(Node* node);
    void CalculateTotalNodesValues(Node* node, unsigned int& total);
    Node* FindNode(Node& startNode, const int& n, unsigned int i = 0);
    Node* GetAverageNode();

    unsigned int mCountLowestNumbers;
    unsigned int mCountGreatestNumbers;
    unsigned int mCount;
    Node* mHeadNode;
};

#endif // BINARY_TREE
