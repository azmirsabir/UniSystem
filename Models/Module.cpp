//
// Created by Azmir.Sleman on 12/14/2023.
//
#include "Module.h"

//constructor
Module::Module(int id, const string &name) : id(id), name(name) {}

//setters and getters
int Module::getId() const {
    return id;
}

void Module::setId(int id) {
    Module::id = id;
}

const string &Module::getName() const {
    return name;
}

void Module::setName(const string &name) {
    Module::name = name;
}
