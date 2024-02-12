//
// Created by Azmir.Sleman on 1/11/2024.
//

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
using namespace std;

class Department {
private:
    int id;
    string name;
    int collegeId;

public:
    Department(int id, const string &name, int collegeId);

    int getId() const;
    void setId(int id);

    const string &getName() const;
    void setName(const string &name);

    int getCollegeId() const;
    void setCollegeId(int collegeId);
};

#endif // DEPARTMENT_H
