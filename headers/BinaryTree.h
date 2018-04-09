#ifdef DEBUGGING

#define DEBUG_LOG(m1, m2) \
  std::cout << m1 << m2 << "\n";

#define DEBUG_MSG(msj) \
  std::cout << msj;

#else

#define DEBUG_LOG(m1, m2)
#define DEBUG_MSG(msj)

#endif // DEBUGGING

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

  Node(const Node& cpyNode)
  {
    if (cpyNode.mLower != nullptr)
    {
      this->mLower = new Node(cpyNode.mLower->n);
    }
    else
    {
      this->mLower = nullptr;
    }

    if (cpyNode.mGreater != nullptr)
    {
      this->mGreater = new Node(cpyNode.mGreater->n);
    }
    else
    {
      this->mGreater = nullptr;
    }

    this->n = cpyNode.n;
    this->mLeftDirectionTaken = cpyNode.mLeftDirectionTaken;
    this->mRightDirectionTaken = cpyNode.mRightDirectionTaken;
    this->mLevelInGreatestSide = cpyNode.mLevelInGreatestSide;
    this->mLevelInLowestSide = cpyNode.mLevelInLowestSide;
  }

  Node& operator=(const Node& cpyNode)
  {
    if (cpyNode.mLower != nullptr)
    {
      this->mLower = new Node(cpyNode.mLower->n);
    }
    else
    {
      this->mLower = nullptr;
    }

    if (cpyNode.mGreater != nullptr)
    {
      this->mGreater = new Node(cpyNode.mGreater->n);
    }
    else
    {
      this->mGreater = nullptr;
    }

    this->n = cpyNode.n;
    this->mLeftDirectionTaken = cpyNode.mLeftDirectionTaken;
    this->mRightDirectionTaken = cpyNode.mRightDirectionTaken;
    this->mLevelInGreatestSide = cpyNode.mLevelInGreatestSide;
    this->mLevelInLowestSide = cpyNode.mLevelInLowestSide;

    return *this;
  }

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

    void ShowNode(Node* node);
    void SaveNode(Node* node, Node& parentNode, const int n);
    void ProcessBalance(Node& newHeadNode, Node& parentNode);
    void ReleaseNode(Node* node);
    void ReleaseNodes(Node* node);
    void CheckUnbalanced(Node& node, Node& parentNode);
    bool EraseNode(Node* node, Node& parentNode, const int n);
    bool EraseNodeFlow(Node* nodeToErase, Node& parentNode, const bool& isTheLowestChild);
    unsigned int GetHigherLevel(const Node& node) const;
    Node* FindNode(Node& startNode, const int& n);
    Node* GetLowestNodeFromThisNode(Node* node, Node* parentNode, const bool& returnParentNode = false);
    Node* GetGreatestNodeFromThisNode(Node* node, Node* parentNode, const bool& returnParentNode = false);

    unsigned int mCount;
    Node* mHeadNode;
};

#endif // BINARY_TREE
