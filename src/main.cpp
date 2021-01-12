#include <iostream>
#include "FileManager.h"

int main() {
    std::cout << "Hello World! \n";


/*
    //BST with template
    Client c1("Cliente1","5","asdad","asdsa","assd","a");
    Client c2("Cliente2","4","dasfa","asdsa","asdsad","b");
    Client c3("Cliente3","3","asdsad","asdsad","adsa","c");
    Client c4("Cliente4","2","adsas","adasd","sdas","b");
    Client c5("Cliente5","1","asdasd","asdas","asdsad","a");
    BST<Client> _clients;

    _clients.insert(c1);
    _clients.insert(c2);
    _clients.insert(c3);
    _clients.insert(c4);
    _clients.insert(c5);

    _clients.display();
     //...
     */


    /*
     * Ahí arriba esta la prueba del arbol si quieren revisarla
     * ahorita el problema que tengo es que no me quiere abrir el archivo porque
     * luego del if(csv.good()) del metodo readClientCSV sale del metodo o sea ni siquiera entra
     * entonces lo mismo lo revisamos mañana juntos
    */

    FileManager fm;
    std::cout << fm.getFilePath() << std::endl;
    BST<Client> Clients;
    Clients = fm.readClientCSV("data.csv");
    Clients.display();



    return -1;
}