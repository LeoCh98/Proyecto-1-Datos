//
// Created by leoch on 09/01/2021.
//

#include "Client.h"

Client::Client(const string &name, const string &id, const string &kid, const string &pregnant, const string &elderly,
               const string &category) : name(name), id(id), kid(kid), pregnant(pregnant), elderly(elderly),
                                         category(category) {}

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

string Client::toString() {
    stringstream output;
    output<<name<<","<<id<<","<<kid<<","<<pregnant<<","<<elderly<<","<<category<<endl;
    return output.str();
}
