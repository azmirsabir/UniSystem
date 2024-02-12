//
// Created by Azmir.Sleman on 1/11/2024.
//

#ifndef DEPARTMENTMODULE_H
#define DEPARTMENTMODULE_H

class DepartmentModule {
private:
    int departmentId;
    int moduleId;
    int stage;
    int semester;

public:
    DepartmentModule(int departmentId, int moduleId, int stage, int semester);

    int getDepartmentId() const;
    void setDepartmentId(int departmentId);

    int getModuleId() const;
    void setModuleId(int moduleId);

    int getStage() const;
    void setStage(int stage);

    int getSemester() const;
    void setSemester(int semester);
};

#endif // DEPARTMENTMODULE_H
