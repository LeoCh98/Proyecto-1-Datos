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
};

template <class T>
Node<T>::Node() = default;

template <class T>
Node<T>* Node<T>::makeEmpty(Node<T>* t) {
    if(t == NULL)
        return NULL;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
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
    //int x1 = stoi(x.getId());           //Acá esta el problema al ingresar los datos al arbol
    //int x2 = stoi(t->data.getId());     //como este ejemplo trata de int se compara mayor y menor para ingresarlos
    else if(x < t->data)                          //y hay que modificar a que se compruebe el id, pero para eso no podria ser un Nodo con template
        t->left = insert(x, t->left);   //ya que hay que acceder a la id como dato
    else if(x > t->data)
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
    std::cout << t->data << " ";
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


#endif //PROYECTO_1_DATOS_NODE_H
