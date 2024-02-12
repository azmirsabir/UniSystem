//
// Created by Azmir.Sleman on 12/14/2023.
//
#include "College.h"

//constructor
College::College(int id, const string &name) : id(id), name(name) {}

//setters and getters

int College::getId() const {
    return id;
}

void College::setId(int id) {
    College::id = id;
}

const string &College::getName() const {
    return name;
}

void College::setName(const string &name) {
    College::name = name;
}
