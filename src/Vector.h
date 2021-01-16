//
// Created by leoch on 15/01/2021.
//

#ifndef PROYECTO_1_DATOS_VECTOR_H
#define PROYECTO_1_DATOS_VECTOR_H
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class Vector {
private:
    T* vec;
    int capacity;
    int current;
public:
    Vector();
    void push(T data);
    void sort();
    void maxElement();
    void deleteMax();
    string toString();
    int getSize() const;
};

template<class T>
Vector<T>::Vector() {
    vec = new T[1];
    capacity = 1;
    current = 0;
}

template<class T>
void Vector<T>::push(T data) {
    if(capacity == current){
        T* temp = new T[2 * capacity];
        for(int i = 0; i < capacity; i++ )
            temp[i] = vec[i];

        delete [] vec;
        capacity *= 2;
        vec = temp;
    }
    vec[current] = data;
    current++;
    sort();
}

template<class T>
void Vector<T>::sort() {
    for (int i=0; i < current; i++)
    {
        for (int j=i+1; j<current ; j++)
        {
            if(vec[i].priority() <= vec[j].priority())
            {
                auto aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}

template<class T>
void Vector<T>::maxElement() {
    cout << vec[0].toString();
}

template<class T>
void Vector<T>::deleteMax() {
    int i;

    for(i= 0 ; i<current -1; i+=1){
        vec[i]= vec[i+1];
    }
    current-=1;
}

template<class T>
string Vector<T>::toString() {
    stringstream output;
    for (int i=0; i < current; i++ )
        output << vec[i].toString() << endl;
    return output.str();
}

template<class T>
int Vector<T>::getSize() const {
    return current;
}

#endif //PROYECTO_1_DATOS_VECTOR_H
