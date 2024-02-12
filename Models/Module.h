//
// Created by Azmir.Sleman on 1/11/2024.
//

#ifndef MODULE_H
#define MODULE_H

#include <string>
using namespace std;

class Module {
private:
    int id;
    string name;

public:
    Module(int id, const string &name);

    int getId() const;
    void setId(int id);

    const string &getName() const;
    void setName(const string &name);
};

#endif // MODULE_H
