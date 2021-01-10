//
// Created by gerso on 9/1/2021.
//

#include "FileManager.h"

FileManager::FileManager() {
    string file_path = __FILE__;
    file_path = file_path.substr(0, file_path.rfind("/"));
    string dir_path = file_path.substr(0, file_path.rfind("/"));
    dir_path = dir_path.substr(0, file_path.rfind("/"));
    filePath = dir_path + "/Archivos/";

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
        if(csv.good()) {
            csv.seekg(52); //Salto de linea para no leer la primera linea del archivo (en teoria en esa primera linea hay 52 caracteres)
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
    getline(csvInfo, name, ',');
    getline(csvInfo, id, ',');
    getline(csvInfo, kid, ',');
    getline(csvInfo, pregnant, ',');
    csvInfo >> cat;
    csvInfo.ignore();
    //csvInfo.ignore();

    _client.setName(name);
    _client.setId(id);
    _client.setKid(kid);
    _client.setPregnant(pregnant);
    _client.setElderly(elderly);
    _client.setCategory(cat);
    return _client;
}
