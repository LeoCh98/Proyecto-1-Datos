#include "Menu.h"
Menu::Menu() {
}
Menu::~Menu() {
}
void Menu::DataMenu() {
    int opcion;
    do {
        cout << "\n\n";
        cout << "\n\n";
        cout << " _________________________________________________________ \n";
        cout << "|   Bienvenidos al programa de datos                      |\n";
        cout << "|_________________________________________________________|\n";
        cout << "|                                                         |\n";
        cout << "|       1. Encolar todos los clientes                     |\n";
        cout << "|                                                         |\n";
        cout << "|       2. Encolar un cliente                             |\n";
        cout << "|                                                         |\n";
        cout << "|       3. Atender los siguientes 5 clientes              |\n";
        cout << "|                                                         |\n";
        cout << "|       4. Mostrar el siguiente cliente a ser atendido    |\n";
        cout << "|                                                         |\n";
        cout << "|       5. Simulación de Atención de Clientes             |\n";
        cout << "|                                                         |\n";
        cout << "|       6. Agregar un Cliente Nuevo                       |\n";
        cout << "|                                                         |\n";
        cout << "|       7. Salir                                          |\n";
        cout << "|_________________________________________________________|\n";
        cout << "Digite su opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                break;
            }
        }
    }while(opcion<7);

}
