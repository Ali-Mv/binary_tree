
template <typename T>
CompleteBinaryTree<T>::CompleteBinaryTree() : root(nullptr), size(0)
{
}
template <typename T>
CompleteBinaryTree<T>::~CompleteBinaryTree()
{
    clear();
}
template <typename T>
CompleteBinaryTree<T>::CompleteBinaryTree(const CompleteBinaryTree<T> &other) : root(nullptr), size(0)
{
    if (other.root != nullptr)
    {
        root = copyTree(other.root, nullptr);
        size = other.size;
    }
}

template <typename T>
CompleteBinaryTree<T> &CompleteBinaryTree<T>::operator=(const CompleteBinaryTree<T> &other)
{
    if (this != &other)
    {
        clear();

        if (other.root != nullptr)
        {
            root = copyTree(other.root, nullptr);
            size = other.size;
        }
    }

    return *this;
}

template <typename T>
void CompleteBinaryTree<T>::destroyTree(TreeNode<T> *node)
{
    if (node == nullptr)
        return;

    destroyTree(node->getLeft());
    destroyTree(node->getRight());

    delete node;
}

template <typename T>
TreeNode<T> *CompleteBinaryTree<T>::copyTree(TreeNode<T> *node, TreeNode<T> *parent)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    TreeNode<T> *newNode = new TreeNode<T>(node->getData());
    newNode->setParent(parent);

    TreeNode<T> *leftCopy = copyTree(node->getLeft(), newNode);
    TreeNode<T> *rightCopy = copyTree(node->getRight(), newNode);

    newNode->setLeft(leftCopy);
    newNode->setRight(rightCopy);

    return newNode;
}

template <typename T>
void CompleteBinaryTree<T>::clear()
{
    destroyTree(root);
    root = nullptr;
    size = 0;
}
template <typename T>
bool CompleteBinaryTree<T>::isEmpty() const
{
    return size == 0;
}
template <typename T>
int CompleteBinaryTree<T>::getSize() const
{
    return size;
}

template <typename T>
TreeNode<T> *CompleteBinaryTree<T>::getNodeByIndex(int index) const
{
    if (index < 1 || index > size || root == nullptr)
        return nullptr;

    if (index == 1)
        return root;

    TreeNode<T> *cur = root;

    int length = 0;
    int num = index;

    while (num > 0)
    {
        length++;
        num /= 2;
    }

    for (int i = length - 2; i >= 0; i--)
    {
        int bit = (index >> i) & 1;

        if (bit == 0)
            cur = cur->getLeft();
        else
            cur = cur->getRight();
    }

    return cur;
}

template <typename T>
void CompleteBinaryTree<T>::insert(T value)
{
    TreeNode<T> *newNode = new TreeNode<T>(value);

    if (root == nullptr)
    {
        root = newNode;
        size = 1;
        return;
    }

    int newIndex = size + 1;
    int parentIndex = newIndex / 2;

    TreeNode<T> *parentNode = getNodeByIndex(parentIndex);

    newNode->setParent(parentNode);

    if (newIndex % 2 == 0)
        parentNode->setLeft(newNode);
    else
        parentNode->setRight(newNode);

    size++;
}

template <typename T>
void CompleteBinaryTree<T>::removeLast()
{
    if (size == 0)
        throw TreeException("Cannot remove from an empty tree.");

    if (size == 1)
    {
        delete root;
        root = nullptr;
        size = 0;
        return;
    }

    int lastIndex = size;

    TreeNode<T> *lastNode = getNodeByIndex(lastIndex);
    TreeNode<T> *parentNode = lastNode->getParent();

    if (parentNode->getLeft() == lastNode)
        parentNode->setLeft(nullptr);
    else if (parentNode->getRight() == lastNode)
        parentNode->setRight(nullptr);

    delete lastNode;
    size--;
}

template <typename T>
void CompleteBinaryTree<T>::levelOrderTraversal() const
{
    for (int i = 1; i <= size; i++)
    {
        TreeNode<T> *node = getNodeByIndex(i);
        node->printInfo();
        cout << " ";
    }
    cout << endl;
}