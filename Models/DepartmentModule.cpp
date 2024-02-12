//
// Created by Azmir.Sleman on 12/20/2023.
//

#include "DepartmentModule.h"

//constructor
DepartmentModule::DepartmentModule(int departmentId, int moduleId, int stage, int semester)
        : departmentId(departmentId), moduleId(moduleId), stage(stage), semester(semester) {}

//setters and getters
int DepartmentModule::getDepartmentId() const {
    return departmentId;
}

void DepartmentModule::setDepartmentId(int departmentId) {
    DepartmentModule::departmentId = departmentId;
}

int DepartmentModule::getModuleId() const {
    return moduleId;
}

void DepartmentModule::setModuleId(int moduleId) {
    DepartmentModule::moduleId = moduleId;
}

int DepartmentModule::getStage() const {
    return stage;
}

void DepartmentModule::setStage(int stage) {
    DepartmentModule::stage = stage;
}

int DepartmentModule::getSemester() const {
    return semester;
}

void DepartmentModule::setSemester(int semester) {
    DepartmentModule::semester = semester;
}