
template <typename T>
TreeNode<T>::TreeNode(T value) : BaseNode<T>(value), left(nullptr), right(nullptr), parent(nullptr)
{
}

template <typename T>
void TreeNode<T>::printInfo() const
{
    cout << this->getData() << " ";
}

template <typename T>
TreeNode<T> *TreeNode<T>::getLeft() const
{
    return left;
}

template <typename T>
TreeNode<T> *TreeNode<T>::getRight() const
{
    return right;
}

template <typename T>
TreeNode<T> *TreeNode<T>::getParent() const
{
    return parent;
}

template <typename T>
void TreeNode<T>::setLeft(TreeNode<T> *node)
{
    left = node;
}

template <typename T>
void TreeNode<T>::setRight(TreeNode<T> *node)
{
    right = node;
}

template <typename T>
void TreeNode<T>::setParent(TreeNode<T> *node)
{
    parent = node;
}
