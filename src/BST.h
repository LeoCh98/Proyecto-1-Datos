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
    void display();
    void getCopy(HeapPriorityQueue<T>& queue);
    void saveTree(ofstream& csv);
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

}

template<class T>
void BST<T>::insert(T x) {
    root = root->insert(x, root);
    size++;
}

template<class T>
void BST<T>::display() {
    root->inorder(root);
}

template<class T>
void BST<T>::getCopy(HeapPriorityQueue<T>& queue) {
    root->getAllData(root,queue);
    std::cout << std::endl;
}

template<class T>
void BST<T>::saveTree(ofstream& csv) {
        root->saveNode(root,csv);
}

template<class T>
void BST<T>::search(int x) {
    if(!root->find(root,x)){
        cout<<"Queued Node.\n";
    }
}

template<class T>
int BST<T>::getSize() const {
    return size;
}


#endif //PROYECTO_1_DATOS_BST_H
