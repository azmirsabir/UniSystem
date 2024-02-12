//
// Created by Azmir.Sleman on 12/19/2023.
//

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include "DataModel.cpp"

using namespace std;

//the class has been used to extract information from the excel files
class ExcelReader{
public:
    static DataModel openFile(const string& fileName) {
        DataModel dataModel;
        ifstream ip("files/" + fileName);

        if (!ip.is_open()) {
            throw runtime_error("Failed to open file: " + fileName);
        }
        string header;
        getline(ip, header);
        switch (detectFileType(fileName)) {
                case File::Colleges:{
                    dataModel.setColleges(readCollege(ip));
                    break;
                }
                case File::Students:{
                    dataModel.setStudents(readStudent(ip));
                    break;
                }
                case File::Departments:{
                    dataModel.setDepartments(readDepartment(ip));
                    break;
                }
                case File::Modules:{
                    dataModel.setModules(readModule(ip));
                    break;
                }
                case File::Assessments:{
                    dataModel.setAssessments(readAssessments(ip));
                    break;
                }
                case File::DepartmentCourses:{
                    dataModel.setDepartmentCourses(readDepartmentCources(ip));
                    break;
                }
                default:
                    throw runtime_error("Unsupported file type: " + fileName);
            }
        return dataModel;
    }
    private:
    enum class File {
        Unknown,
        Colleges,
        Students,
        Modules,
        Departments,
        Assessments,
        DepartmentCourses
    };
    static File detectFileType(const string& fileName) {
        if (fileName == "colleges.csv") {
            return File::Colleges;
        } else if (fileName == "students.csv") {
            return File::Students;
        } else if (fileName == "departments.csv") {
            return File::Departments;
        }else if(fileName == "modules.csv"){
            return File::Modules;
        }else if(fileName == "DepartmentModules.csv"){
            return File::DepartmentCourses;
        }else if(fileName == "assessments.csv"){
            return File::Assessments;
        }
        else {
            return File::Unknown;
        }
    }
    static vector<College> readCollege(ifstream& ip) {
        vector<College> colleges;
        string id, name;
        while (ip.good()) {
            getline(ip, id, ',');
            getline(ip, name, '\n');
            colleges.emplace_back(stoi(id), name);
        }
        ip.close();
        return colleges;
    }
    static vector<Module> readModule(ifstream& ip) {
        vector<Module> modules;
        string id, name;
        while (ip.good()) {
            getline(ip, id, ',');
            getline(ip, name, '\n');
            modules.emplace_back(stoi(id), name);
        }
        ip.close();
        return modules;
    }
    static vector<Department> readDepartment(ifstream& ip) {
        vector<Department> departments;
        string id, name,collegeId;
        while (ip.good()) {
            getline(ip, id, ',');
            getline(ip, name, ',');
            getline(ip, collegeId, '\n');
            departments.emplace_back(stoi(id), name,stoi(collegeId));
        }
        ip.close();
        return departments;
    }
    static vector<Student> readStudent(ifstream& ip) {
        vector<Student> students;
        string id,name,email,phone,departmentId,graduationDate;
        while (ip.good()) {
            getline ( ip, id, ',' );
            getline ( ip, name, ',' );
            getline ( ip, email, ',' );
            getline ( ip, phone, ',' );
            getline ( ip, departmentId, ',' );
            getline ( ip, graduationDate, '\n' );
            students.emplace_back(stoi(id), name, email, phone, stoi(departmentId),stoi(graduationDate));
        }
        ip.close();
        return students;
    }
    static vector<StudentAssessment> readAssessments(ifstream& ip) {
        vector<StudentAssessment> assessments;
        string studentId,moduleId,quizWeight,midtermWeight,assignmentWeight,finalExamWeight,attendance;
        while (ip.good()) {
            getline(ip, studentId, ',');
            getline(ip, moduleId, ',');
            getline(ip, quizWeight, ',');
            getline(ip, midtermWeight, ',');
            getline(ip, assignmentWeight, ',');
            getline(ip, finalExamWeight, ',');
            getline(ip, attendance, '\n');
            assessments.emplace_back(stoi(studentId), stoi(moduleId), stod(quizWeight), stod(midtermWeight), stod(assignmentWeight), stod(finalExamWeight), stoi(attendance));
        }
        ip.close();
        return assessments;
    }
    static vector<DepartmentModule> readDepartmentCources(ifstream& ip) {
        vector<DepartmentModule> departmentModules;
        string departmentId,moduleId,stage,semester;
        while (ip.good()) {
            getline(ip, departmentId, ',');
            getline(ip, moduleId, ',');
            getline(ip, stage, ',');
            getline(ip, semester, '\n');
            departmentModules.emplace_back(stoi(departmentId), stoi(moduleId), stoi(stage),stoi(semester));
        }
        ip.close();
        return departmentModules;
    }
};
