//
// Created by leoch on 15/01/2021.
//

#ifndef PROYECTO_1_DATOS_HEAPPRIORITYQUEUE_H
#define PROYECTO_1_DATOS_HEAPPRIORITYQUEUE_H
#include "Vector.h"

template <class T>
class HeapPriorityQueue {
private:
    Vector<T> _vect;
public:
    void insert(T x);
    int size();
    bool empty();
    void front();
    void pop();
    void display();
};

template<class T>
void HeapPriorityQueue<T>::insert(T x) {
    _vect.push(x);
}

template<class T>
int HeapPriorityQueue<T>::size() {
    return _vect.getSize();
}

template<class T>
bool HeapPriorityQueue<T>::empty() {
    return _vect.getSize() == 0;
}

template<class T>
void HeapPriorityQueue<T>::front() {
    _vect.maxElement();
}

template<class T>
void HeapPriorityQueue<T>::pop() {
    _vect.maxElement();
    _vect.deleteMax();
}

template<class T>
void HeapPriorityQueue<T>::display() {
    if(!empty())
        cout << _vect.toString() <<endl;
}


#endif //PROYECTO_1_DATOS_HEAPPRIORITYQUEUE_H
