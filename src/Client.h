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
    int priority;
public:


public:
    Client(const string &name, const string &id, const string &kid, const string &pregnant, const string &elderly,
           const string &category, const int priority);

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
    int getPriority() const;
    void setPriority(int priority);
    string toString();
};


#endif //PROYECTO_1_DATOS_CLIENT_H
