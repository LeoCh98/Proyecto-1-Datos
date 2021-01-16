#include "Client.h"

Client::Client(const string &name, const string &id, const string &kid, const string &pregnant, const string &elderly,
               const string &category) : name(name), id(id), kid(kid), pregnant(pregnant), elderly(elderly),
                                         category(category){}

Client::Client() = default;

Client::~Client() {

}

const string &Client::getName() const {
    return name;
}

void Client::setName(const string &name) {
    Client::name = name;
}

const string &Client::getId() const {
    return id;
}

void Client::setId(const string &id) {
    Client::id = id;
}

const string &Client::getKid() const {
    return kid;
}

void Client::setKid(const string &kid) {
    Client::kid = kid;
}

const string &Client::getPregnant() const {
    return pregnant;
}

void Client::setPregnant(const string &pregnant) {
    Client::pregnant = pregnant;
}

const string &Client::getElderly() const {
    return elderly;
}

void Client::setElderly(const string &elderly) {
    Client::elderly = elderly;
}

const string &Client::getCategory() const {
    return category;
}

void Client::setCategory(const string &category) {
    Client::category = category;
}

int Client::priority() {
    int _priority=0;
    if(kid=="Yes"||kid=="yes")
        _priority+=20;
    if(pregnant=="Yes"||pregnant=="yes")
        _priority+=25;
    if(elderly=="Yes"||elderly=="yes")
        _priority+=35;
    switch(stoi(category)){
        case 1:
            _priority+=20;
            break;
        case 2:
            _priority+=10;
            break;
        case 3:
            _priority+=0;
            break;
    }
    return _priority;
}

string Client::toString() {
    stringstream output;
    output << name << "," << id << "," << kid << "," << pregnant << "," << elderly << "," << category << "," << priority() << "%" <<endl;
    return output.str();
}