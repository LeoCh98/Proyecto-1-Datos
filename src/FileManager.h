//
// Created by gerso on 9/1/2021.
//

#ifndef PROYECTO_1_DATOS_FILEMANAGER_H
#define PROYECTO_1_DATOS_FILEMANAGER_H
#include "Client.h"
#include "BST.h"
#include <fstream>

class FileManager {
private:
    string filePath;
public:
    FileManager();
    void setFilepath(const string &filepath);
    const string &getFilePath() const;
    BST<Client> readClientCSV (const string &filename);
    Client loadClient(ifstream &csvInfo);


};


#endif //PROYECTO_1_DATOS_FILEMANAGER_H
