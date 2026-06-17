#ifndef COMPLETE_BINARY_TREE_H
#define COMPLETE_BINARY_TREE_H

#include <iostream>
#include "TreeNode.h"
#include "TreeException.h"

template <typename T>
class CompleteBinaryTree {
private:
    TreeNode<T>* root;
    int size;

    void destroyTree(TreeNode<T>* node);
    TreeNode<T>* copyTree(TreeNode<T>* node, TreeNode<T>* parent);

    TreeNode<T>* getNodeByIndex(int index) const;
    int getBinaryLength(int number) const;

public:
    CompleteBinaryTree();
    ~CompleteBinaryTree();

    CompleteBinaryTree(const CompleteBinaryTree<T>& other);
    CompleteBinaryTree<T>& operator=(const CompleteBinaryTree<T>& other);

    void insert(T value);
    void removeLast();
    void levelOrderTraversal() const;

    bool isEmpty() const;
    int getSize() const;

    void clear();
};

#include "CompleteBinaryTree.tpp"

#endif
