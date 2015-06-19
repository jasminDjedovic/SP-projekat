#ifndef _BST_HXX_
#define _BST_HXX_
#include <iostream>
#include "node.hxx"

template <typename T>
class BST
{
  protected:
    NodeBST<T> *root;
  public:
    BST() : root(nullptr) {}
    BST(const BST &);
    BST(BST &&);
    ~BST();
    void copy(NodeBST<T>* &, NodeBST<T> *);
    bool find(const T &) const;
    void insert(const T &);
    void printInorder() {inorder(root);}
    void printPreorder() {preorder(root);}
    void printPostorder() {postorder(root);}
    void inorder(NodeBST<T> *);
    void preorder(NodeBST<T> *);
    void postorder(NodeBST<T> *);
    void destroy(NodeBST<T> *tmp);
    void remove(const T &);
    bool isEmpty(){return root == nullptr;}
};

template <typename T>
void BST<T>::copy(NodeBST<T>* &dst, NodeBST<T> *src)
{
  if(src==nullptr)
    dst = nullptr;
  else
  {
    dst = new NodeBST<T> (src->getValue());
    copy(dst->getLeftNode(), src->getLeftNode());    
    copy(dst->getRightNode(), src->getRightNode());
  }
}

template <typename T>
BST<T>::BST(const BST &b)
{
  copy(root, b.root);
}

template <typename T>
BST<T>::BST(BST &&b)
{
  root = b.root();
  b.root = nullptr;
}

template <typename T>
void BST<T>::destroy(NodeBST<T> *tmp)
{
  if(tmp->getLeftNode() != nullptr)
    destroy(tmp->getLeftNode());

  if(tmp->getRightNode() != nullptr)
    destroy(tmp->getRightNode());

  delete tmp;

}

template <typename T>
BST<T>::~BST()
{
  if(root!=nullptr)
  {
    destroy(root);
    root = nullptr;
  }
}

template <typename T>
bool BST<T>::find(const T &val) const
{
  NodeBST<T> *tmp = root;

  while(tmp!=nullptr)
  {
    if(tmp->getValue() == val)
      return true;

    if(tmp->getValue() < val)
      tmp = tmp->getRightNode();
    else
      tmp = tmp->getLeftNode();
  }
  return false;

}

template <typename T>
void BST<T>::insert(const T &val)
{
  if(!find(val))
  {
    NodeBST<T> *tmp = new NodeBST<T>(val);
    if(root == nullptr)
      root = tmp;
    else
    {
      NodeBST<T> *current = root;
      NodeBST<T> *target;

      while(current!=nullptr)
      {
        target = current;
        if(current->getValue() < val)
          current = current->getRightNode();
        else
          current = current->getLeftNode();
      }

      if(target->getValue() < val)
        target->setRightNode(tmp);
      else
        target->setLeftNode(tmp);
    }

    tmp = nullptr;
  }
}

template <typename T>
void BST<T>::inorder(NodeBST<T> *tmp)
{
  if(tmp->getLeftNode() != nullptr)
    inorder(tmp->getLeftNode());

  std::cout<<tmp->getValue()<<std::endl;
  
  if(tmp->getRightNode() != nullptr)
    inorder(tmp->getRightNode());
}

template <typename T>
void BST<T>::preorder(NodeBST<T> *tmp)
{
  std::cout<<tmp->getValue()<<std::endl;
  
  if(tmp->getLeftNode() != nullptr)
    preorder(tmp->getLeftNode());

  if(tmp->getRightNode() != nullptr)
    preorder(tmp->getRightNode());
}

template <typename T>
void BST<T>::postorder(NodeBST<T> *tmp)
{
  if(tmp->getLeftNode() != nullptr)
    postorder(tmp->getLeftNode());

  if(tmp->getRightNode() != nullptr)
    postorder(tmp->getRightNode());

  std::cout<<tmp->getValue()<<std::endl;
  
}

template <typename T>
void BST<T>::remove(const T &val)
{
  NodeBST<T> *target = root;
  NodeBST<T> *parrent;
  
  while(target!=nullptr)
  {
    if(target->getValue() == val)
      break;

    parrent = target;
    if(target->getValue() < val)
      target = target->getRightNode();
    else
      target = target->getLeftNode();
  }

  if(target->getLeftNode() == nullptr && target->getRightNode() == nullptr) //bez djece
  {
     if(parrent->getLeftNode() == target)
      parrent->setLeftNode(nullptr);
     else
      parrent->setRightNode(nullptr);
  }
  else if(target->getLeftNode() != nullptr && target->getRightNode() == nullptr)
  {//ima samo lijevo dijete

     if(parrent->getLeftNode() == target)
      parrent->setLeftNode(target->getLeftNode());
     else
      parrent->setRightNode(target->getLeftNode());
    
  }
  else if(target->getLeftNode() == nullptr && target->getRightNode() != nullptr)
  {//ima samo desno dijete

     if(parrent->getLeftNode() == target)
      parrent->setLeftNode(target->getRightNode());
     else
      parrent->setRightNode(target->getRightNode());
    
  }
  else
  {
    NodeBST<T> *tmp = target;
    target = target->getRightNode();
    parrent = tmp;
    while(target->getLeftNode() != nullptr)
    {
      parrent = target;
      target = target->getLeftNode();  
    }

    tmp->setValue(target->getValue());
    
    if(parrent->getLeftNode() == target)
      parrent->setLeftNode(nullptr);
    else
      parrent->setRightNode(nullptr);

  }

  delete target;
}

#endif
