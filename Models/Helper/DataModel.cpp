//
// Created by Azmir.Sleman on 12/20/2023.
//
#include <iostream>
#include <vector>
#include "../Student.h"
#include "../College.h"
#include "../Department.h"
#include "../Module.h"
#include "../StudentAssessment.h"
#include "../DepartmentModule.h"

//this class has been used as a model to send data between classes
class DataModel{
private:
    vector<College> colleges;
    vector<Student> students;
    vector<Department> departments;
    vector<Module> modules;
    vector<StudentAssessment> assessments;
    vector<DepartmentModule> departmentCourses;
public:
    const vector<College> &getColleges() const {
        return colleges;
    }
    void setColleges(const vector<College> &colleges) {
        DataModel::colleges = colleges;
    }
    const vector<Student> &getStudents() const {
        return students;
    }
    void setStudents(const vector<Student> &students) {
        DataModel::students = students;
    }
    const vector<Department> &getDepartments() const {
        return departments;
    }
    void setDepartments(const vector<Department> &departments) {
        DataModel::departments = departments;
    }
    const vector<Module> &getModules() const {
        return modules;
    }
    void setModules(const vector<Module> &modules) {
        DataModel::modules = modules;
    }
    const vector<StudentAssessment> &getAssessments() const {
        return assessments;
    }
    void setAssessments(const vector<StudentAssessment> &assessments) {
        DataModel::assessments = assessments;
    }
    const vector<DepartmentModule> &getDepartmentCourses() const {
        return departmentCourses;
    }
    void setDepartmentCourses(const vector<DepartmentModule> &departmentCourses) {
        DataModel::departmentCourses = departmentCourses;
    }
};
