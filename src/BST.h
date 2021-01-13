#ifndef PROYECTO_1_DATOS_BST_H
#define PROYECTO_1_DATOS_BST_H
#include "Node.h"

template<class T>
class BST {
private:
    Node<T>* root;
public:
    BST();
    virtual ~BST();
    void insert(T x);
    void remove(T x);
    void display();
    void search(T x);

};

template<class T>
BST<T>::BST() {
    root = NULL;
}

template<class T>
BST<T>::~BST() {
    //root = root->makeEmpty(root);
}

template<class T>
void BST<T>::insert(T x) {
    root = root->insert(x, root);
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
void BST<T>::search(T x) {
    root = root->find(root, x);
}


#endif //PROYECTO_1_DATOS_BST_H
