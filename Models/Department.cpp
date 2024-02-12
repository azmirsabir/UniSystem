//
// Created by Azmir.Sleman on 12/14/2023.
//

#include "Department.h"

//constructor
Department::Department(int id, const string &name, int collegeId) : id(id), name(name), collegeId(collegeId) {}

//setters and getters
int Department::getId() const {
    return id;
}

void Department::setId(int id) {
    Department::id = id;
}

const string &Department::getName() const {
    return name;
}

void Department::setName(const string &name) {
    Department::name = name;
}

int Department::getCollegeId() const {
    return collegeId;
}

void Department::setCollegeId(int collegeId) {
    Department::collegeId = collegeId;
}
