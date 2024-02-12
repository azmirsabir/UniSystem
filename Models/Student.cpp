//
// Created by Azmir.Sleman on 12/14/2023.
//

#include "Student.h"

//constructors
Student::Student() {}
Student::Student(int id, const string &name, const string &email, const string &phone, int departmentId, int graduationDate)
        : id(id), name(name), email(email), phone(phone), departmentId(departmentId), graduationDate(graduationDate) {}

//setters and getters
int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    Student::id = id;
}

const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

const string &Student::getEmail() const {
    return email;
}

void Student::setEmail(const string &email) {
    Student::email = email;
}

const string &Student::getPhone() const {
    return phone;
}

void Student::setPhone(const string &phone) {
    Student::phone = phone;
}

int Student::getDepartmentId() const {
    return departmentId;
}

void Student::setDepartmentId(int departmentId) {
    Student::departmentId = departmentId;
}

int Student::getGraduationDate() const {
    return graduationDate;
}

void Student::setGraduationDate(int graduationDate) {
    Student::graduationDate = graduationDate;
}
