#ifndef _NODE_HXX_
#define _NODE_HXX_

template <typename T>
class NodeBST
{
  private:
    T value;
    NodeBST *leftNode = nullptr;
    NodeBST *rightNode = nullptr;
  public:
    NodeBST(const T &val) : value(val) {};
    NodeBST(const NodeBST &);
    NodeBST(NodeBST &&);
    void setValue(const T &val) {value = val;}
    void setLeftNode(NodeBST *node) {leftNode = node;}
    void setRightNode(NodeBST *node) {rightNode = node;}
    T getValue() {return value;}
    NodeBST* &getLeftNode() {return leftNode;}
    NodeBST* &getRightNode() {return rightNode;}
};

template <typename T>
NodeBST<T>::NodeBST(const NodeBST &b)
{
  value = b.value();
  leftNode = new NodeBST<T>(b.leftNode);
  rightNode = new NodeBST<T>(b.rightNode);
}
template <typename T>
NodeBST<T>::NodeBST(NodeBST &&b)
{
  value = b.value();
  leftNode = b.leftNode();
  rightNode = b.rightNode();
  b.leftNode = nullptr;
  b.rightNode = nullptr;
}

#endif
