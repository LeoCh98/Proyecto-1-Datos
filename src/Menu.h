//
// Created by gerso on 12/1/2021.
//

#ifndef PROYECTO_1_DATOS_MENU_H
#define PROYECTO_1_DATOS_MENU_H
#include "BST.h"
#include "FileManager.h"

class Menu {
private:
    FileManager fm;
    BST<Client> clientTree;
    HeapPriorityQueue<Client> clientQueue;
public:
    Menu();
    ~Menu();
    void DataMenu();
    void caseOne();
    void caseTwo();
    void caseThree();
    void caseFour();
    void caseFive();
    void caseSix();
    void caseSeven();
};


#endif //PROYECTO_1_DATOS_MENU_H
