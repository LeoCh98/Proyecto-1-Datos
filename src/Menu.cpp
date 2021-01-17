#include "Menu.h"

Menu::Menu() {
    clientTree = fm.readClientCSV("data.csv");
}
Menu::~Menu() {
}
void Menu::DataMenu() {
    string option;
    do {
        cout << "\n\n";
        cout << " _________________________________________________________ \n";
        cout << "|                Welcome to Bank One                      |\n";
        cout << "|_________________________________________________________|\n";
        cout << "|                                                         |\n";
        cout << "|       1. Queue all clients                              |\n";
        cout << "|                                                         |\n";
        cout << "|       2. Queue a client                                 |\n";
        cout << "|                                                         |\n";
        cout << "|       3. Serve the next 5 clients                       |\n";
        cout << "|                                                         |\n";
        cout << "|       4. Show the next client to be served              |\n";
        cout << "|                                                         |\n";
        cout << "|       5. Client Service Simulation                      |\n";
        cout << "|                                                         |\n";
        cout << "|       6. Add a new client                               |\n";
        cout << "|                                                         |\n";
        cout << "|       7. Exit                                           |\n";
        cout << "|_________________________________________________________|\n";
        cout << "Enter a option: "; cin >> option;
        switch(atoi(option.c_str())) {
            case 1:{
                caseOne();
                break;
            }
            case 2:{
                caseTwo();
                break;
            }
            case 3:{
                caseThree();
                break;
            }
            case 4:{
                caseFour();
                break;
            }
            case 5:{
                caseFive();
                break;
            }
            case 6:{
                caseSix();
                break;
            }
            case 7:{
                caseSeven();
                cout << "\n\t Thank you for using this program... \n";
                break;
            }
            default: {
                cout << "\n\t Invalid option... Please, insert again...\n\n";
                break;
            }
        }
    }while(atoi(option.c_str())!=7);

}

void Menu::caseOne() {
    cout<<"\nQueue all clients...\n\n";
    clientTree.getCopy(clientQueue);
    clientQueue.display();
    cout << "Clients was queue successfully...\n";
}

void Menu::caseTwo() {
    cout<<"\nQueue a client...\n\n";
}

void Menu::caseThree() {
    if(!clientQueue.empty()){
        cout<<"\nServe the next 5 clients...\n\n";
        for (int i = 1; i <= 5; i++) {
            cout << "Client#" << i << ":\n";
            clientQueue.pop();
            cout << "Client was attended successfully...\n";
        }
    } else
        cout<<"Queue is empty...\n";
}

void Menu::caseFour() {
    cout<<"\nShow the next client to be served...\n\n";
    clientQueue.front();
}

void Menu::caseFive() {
        cout << "\nClient Service Simulation\n\n";
        if(clientQueue.empty())
            cout<<"Queue is empty...\n";
        int i = 1;
        while(!clientQueue.empty()){
            cout << "Client#" << i << ":\n";
            clientQueue.pop();
            cout << "Client was attended successfully...\n"; i++;
        }
}

void Menu::caseSix() {
    string name, id, kid, pregnant, elderly, cat,resp;
    cout<<"\nAdd a new client...\n\n";
    cout<<"Please enter the following data:\n";
    cout<<"Name: "; cin>>name;
    cout<<"\nId: ";cin>>id;
    cout<<"\nHas a child with you?: (Yes or No) ";cin>>kid;
    cout<<"\nAre you pregnant?: (Yes or No) "; cin>>pregnant;
    cout<<"\nAre you an older adult?: (Yes or No) ";cin>>elderly;
    cout<<"\nWhat category do you belong to?: (1,2,3) ";cin>>cat;
    Client _client(name,id,kid,pregnant,elderly,cat);
    cout<<endl<<_client.toString()<<endl;
    cout<<"Do you want to introduce the new user to the system? (Yes or No)\n";
    cin>>resp;
    if(resp == "Yes" || resp == "YES" || resp == "yes")
        clientTree.insert(_client);
}

void Menu::caseSeven() {
    fm.writeClientCSV(clientTree);
}
