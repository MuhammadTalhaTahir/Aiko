#include "Node.h"
template<class T>
Node<T>::Node() { next = NULL; }
template<class T>
Node<T>::Node(T z) { data = z; next = NULL; }
template<class T>
T Node<T>::getdata() { return data; }