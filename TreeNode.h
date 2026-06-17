#pragma once

#include <iostream>
#include "BaseNode.h"

using namespace std;

template <typename T>
class TreeNode : public BaseNode<T>
{
private:
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *parent;

public:
    TreeNode(T value);

    void printInfo() const override;

    TreeNode<T> *getLeft() const;
    TreeNode<T> *getRight() const;
    TreeNode<T> *getParent() const;
    
    void setLeft(TreeNode<T> *node);
    void setRight(TreeNode<T> *node);
    void setParent(TreeNode<T> *node);
};

#include "TreeNode.tpp"
