#include <iostream>
#include "FileManager.h"

int main() {
    std::cout << "Hello World! \n";

    std::cout <<"Binary tree with templates only as a proof\n";
    BST<int> T;
    T.insert(8);
    T.insert(5);
    T.insert(6);
    T.insert(3);
    T.insert(4);
    T.insert(0);
    T.display();

    /*FileManager fm;
    std::cout << fm.getFilePath() << std::endl;
    BST<Client> Clients;
    Clients = fm.readClientCSV("Datos.csv");
    Clients.display();*/


    return 0;
}