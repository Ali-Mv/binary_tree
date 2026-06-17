template <typename T>
BaseNode<T>::BaseNode(T value) : data(value) {
}

template <typename T>
BaseNode<T>::~BaseNode() {
}

template <typename T>
T BaseNode<T>::getData() const {
    return data;
}

template <typename T>
void BaseNode<T>::setData(T value) {
    data = value;
}