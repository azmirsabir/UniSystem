//
// Created by Azmir.Sleman on 1/11/2024.
//

#ifndef COLLEGE_H
#define COLLEGE_H

#include <string>
using namespace std;

class College {
private:
    int id;
    string name;

public:
    College(int id, const string &name);

    int getId() const;
    void setId(int id);

    const string &getName() const;
    void setName(const string &name);
};

#endif // COLLEGE_H
