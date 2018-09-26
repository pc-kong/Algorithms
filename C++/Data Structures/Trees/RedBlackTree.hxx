template <class T> 
RedBlackTree<T>::RedBlackTree() : BinarySearchTree<T>() {}

template <class T> 
template <typename Iterable> 
RedBlackTree<T>::RedBlackTree(const Iterable& it) : BinarySearchTree<T>(it) {}