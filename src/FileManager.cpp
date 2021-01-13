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
