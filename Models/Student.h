//
// Created by Azmir.Sleman on 1/11/2024.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    string email;
    string phone;
    int departmentId;
    int graduationDate;

public:
    Student();
    Student(int id, const string &name, const string &email, const string &phone, int departmentId, int graduationDate);

    int getId() const;
    void setId(int id);

    const string &getName() const;
    void setName(const string &name);

    const string &getEmail() const;
    void setEmail(const string &email);

    const string &getPhone() const;
    void setPhone(const string &phone);

    int getDepartmentId() const;
    void setDepartmentId(int departmentId);

    int getGraduationDate() const;
    void setGraduationDate(int graduationDate);
};

#endif // STUDENT_H
