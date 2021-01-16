#ifndef PROYECTO_1_DATOS_BST_H
#define PROYECTO_1_DATOS_BST_H
#include "Node.h"


template<class T>
class BST {
private:
    Node<T>* root;
    int size;
public:
    BST();
    virtual ~BST();
    void insert(T x);
    void remove(T x);
    void display();
    void getCopy(HeapPriorityQueue<T>& queue);
    void search(int x);
    int getSize() const;
};

template<class T>
BST<T>::BST() {
    root = NULL;
    size = 0;
}

template<class T>
BST<T>::~BST() {
    //root = root->makeEmpty(root);
}

template<class T>
void BST<T>::insert(T x) {
    root = root->insert(x, root);
    size++;
}

template<class T>
void BST<T>::remove(T x) {
    root = root->remove(x, root);
}

template<class T>
void BST<T>::display() {
    root->inorder(root);
    std::cout << std::endl;
}

template<class T>
void BST<T>::getCopy(HeapPriorityQueue<T>& queue) {
    root->getAllData(root,queue);
    std::cout << std::endl;
}

template<class T>
void BST<T>::search(int x) {
    root = root->find(root, x);
}

template<class T>
int BST<T>::getSize() const {
    return size;
}


#endif //PROYECTO_1_DATOS_BST_H
