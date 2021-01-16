//
// Created by gerso on 9/1/2021.
//

#include "FileManager.h"

FileManager::FileManager() {
    filePath = "..\\..\\archivos\\";
}

void FileManager::setFilepath(const std::string &filePath) {
    FileManager::filePath = filePath;
}

const string &FileManager::getFilePath() const {
    return filePath;
}

BST<Client> FileManager::readClientCSV(const string &filename) {
    ifstream csv;
    BST<Client> _clientTree;
    try {
        csv.open( filePath + filename, ios::in);
        if(csv.good()) { //+
            csv.seekg(55); //Break line
            while (!csv.eof() && csv.good()) {
                Client _client = loadClient(csv);
                _clientTree.insert(_client);
            }
        }
        csv.close();
    }
    catch (std::ifstream::failure a) {
        exit(1);
    }
    return _clientTree;
}
int FileManager::calculatePriority(string pA, string pB, string pC, string pD) {
    int a, b, c, d;
    if(pA == "Yes"){ //Ninio
        a=20;
    }else{a=0;}
    if(pB == "Yes"){ //Embarazada
        b=25;
    }else{b=0;}
    if(pC == "Yes"){ //Adulto mayor
        c=20;
    }else{c=0;}
    if(pD=="1"){ //Categoria 1
        d=20;
    }
    if(pD=="2"){ //Categoria 2
        d=10;
    }else{ //Categoria 3
        d=0;
    }

    return a+b+c+d;
}
Client FileManager::loadClient(ifstream &csvInfo) {
    Client _client;
    string name, id, kid, pregnant, elderly, cat;
    getline(csvInfo, name, ',');
    getline(csvInfo, id, ',');
    getline(csvInfo, kid, ',');
    getline(csvInfo, pregnant, ',');
    getline(csvInfo, elderly, ',');
    getline(csvInfo, cat, '\n');



    _client.setName(name);
    _client.setId(id);
    _client.setKid(kid);
    _client.setPregnant(pregnant);
    _client.setElderly(elderly);
    _client.setCategory(cat);
    return _client;
}
