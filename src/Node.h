//
// Created by leoch on 09/01/2021.
//

#ifndef PROYECTO_1_DATOS_NODE_H
#define PROYECTO_1_DATOS_NODE_H

template <class T>
class Node{
private:
        T data;
        Node<T>* left;
        Node<T>* right;
public:
    Node();
    Node<T>* find(Node<T>* t, T x);
    void inorder(Node<T>* t);
    Node<T>* remove(T x, Node<T>* t);
    Node<T>* findMax(Node<T>* t);
    Node<T>* findMin(Node<T>* t);
    Node<T>* insert(T x, Node<T>* t);
    Node<T>* makeEmpty(Node<T>* t);

    T getData() const;
    Node<T> *getLeft() const;
    Node<T> *getRight() const;
};

template <class T>
Node<T>::Node() = default;

template <class T>
Node<T>* Node<T>::makeEmpty(Node<T>* t) {
    if(t == NULL)
        return NULL;
    {
        makeEmpty(t->getLeft());
        makeEmpty(t->getRight());
        delete t;
    }
    return NULL;
}

template <class T>
Node<T>* Node<T>::insert(T x, Node<T>* t)
{
    if(t == NULL)
    {
        t = new Node;
        t->data = x;
        t->left = t->right = NULL;
    }
    else if(x.getId() < t->getData().getId())
        t->left = insert(x, t->left);
    else if(x.getId() > t->getData().getId())
        t->right = insert(x, t->right);
    return t;
}

template <class T>
Node<T>* Node<T>::findMin(Node<T>* t)
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

template <class T>
Node<T>* Node<T>::findMax(Node<T>* t) {
    if(t == NULL)
        return NULL;
    else if(t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

template <class T>
Node<T>* Node<T>::remove(T x, Node<T>* t) {
    Node<T>* temp;
    if(t == NULL)
        return NULL;
    else if(x < t->data)
        t->left = remove(x, t->left);
    else if(x > t->data)
        t->right = remove(x, t->right);
    else if(t->left && t->right)
    {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    else
    {
        temp = t;
        if(t->left == NULL)
            t = t->right;
        else if(t->right == NULL)
            t = t->left;
        delete temp;
    }
    return t;
}

template <class T>
void Node<T>::inorder(Node<T>* t) {
    if(t == NULL)
        return;
    inorder(t->left);
    std::cout << t->getData().toString() << " ";
    inorder(t->right);
}

template <class T>
Node<T>* Node<T>::find(Node<T>* t, T x) {
    if(t == NULL)
        return NULL;
    else if(x < t->data)
        return find(t->left, x);
    else if(x > t->data)
        return find(t->right, x);
    else
        return t;
}

template<class T>
T Node<T>::getData() const {
    return data;
}

template<class T>
Node<T> *Node<T>::getLeft() const {
    return left;
}

template<class T>
Node<T> *Node<T>::getRight() const {
    return right;
}


#endif //PROYECTO_1_DATOS_NODE_H
