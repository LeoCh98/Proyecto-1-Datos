//
// Created by leoch on 09/01/2021.
//

#ifndef PROYECTO_1_DATOS_CLIENT_H
#define PROYECTO_1_DATOS_CLIENT_H
#include <iostream>
#include <sstream>
using namespace std;

class Client {
private:
    string name;
    string id;
    string kid;
    string pregnant;
    string elderly;
    string category;
public:
    Client();
    virtual ~Client();
    const string &getName() const;
    void setName(const string &name);
    const string &getId() const;
    void setId(const string &id);
    const string &getKid() const;
    void setKid(const string &kid);
    const string &getPregnant() const;
    void setPregnant(const string &pregnant);
    const string &getElderly() const;
    void setElderly(const string &elderly);
    const string &getCategory() const;
    void setCategory(const string &category);
    string toString();
};


#endif //PROYECTO_1_DATOS_CLIENT_H
