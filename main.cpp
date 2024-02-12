#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <optional>
#include <algorithm>
#include <chrono>
#include "Models/Helper/ExcelReader.cpp"
#include "Models/Helper/CMD.cpp"
using namespace std;

    //for College, Department, Student, Module, Assessment and DepartmentModule
    //class has been used instead of structures
    //the classes are in Models folder
    //the excel files located in cmake-build-debug/files

    //struct to store top students
    struct TopStudents{
        int studentId;
        double overallMark;
        TopStudents(int studentId, double overallMark) : studentId(studentId), overallMark(overallMark) {}
    };
    //the below method returns all college from colleges file
    vector<College> getAllColleges(){
        return ExcelReader::openFile("colleges.csv").getColleges();
    }

    //the below method returns all students from students file
    vector<Student> getAllStudents(){
        return ExcelReader::openFile("students.csv").getStudents();
    }

    //the below method returns all departments from departments file
    vector<Department> getAllDepartments(){
        return ExcelReader::openFile("departments.csv").getDepartments();
    }

    //the below method returns all modules from modules file
    vector<Module> getAllModules(){
    return ExcelReader::openFile("modules.csv").getModules();
}

    //the below method returns all departmentModules from excel file
    vector<DepartmentModule> getAllDepartmentModules(){
    return ExcelReader::openFile("DepartmentModules.csv").getDepartmentCourses();
}

    //the below method returns all assessments from assessments file
    vector<StudentAssessment> getAllAssesments(){
    return ExcelReader::openFile("assessments.csv").getAssessments();
}

    //has been used for validation purpose
    int getCurrentYear(){
        auto now = chrono::system_clock::now();
        // Convert the current time point to a time_t object
        time_t currentTime = chrono::system_clock::to_time_t(now);
        // Convert the time_t object to a tm structure
        tm* timeInfo = localtime(&currentTime);
        int currentYear = timeInfo->tm_year + 1900;
        return currentYear;
    }

    //has been used for heap sorting of top students
    bool compareTopStudents(const TopStudents& a, const TopStudents& b) {
        // Sorting in descending order
        return a.overallMark > b.overallMark;
    }

    //this method returns departments of specifies college
    vector<Department> findDepartmentsByCollege(int collegeId){
        vector<Department> depts;
        vector<Department> departments=getAllDepartments();
        for (int i = 0; i < departments.size(); ++i) {
            if(departments.at(i).getCollegeId()==collegeId){
                depts.push_back(departments.at(i));
            }
        }
        return depts;
    }

    //it finds a student by studentID
    Student getStudentById(const int studentId){
        vector<Student> students=getAllStudents();
        for(int i=0;i<students.size();i++){
            if(students.at(i).getId()==studentId) return students.at(i);
        }
        return *new Student();
    }

    //finds the students of specified department
    vector<Student> findStudentsInDept(int deptID){
        vector<Student> stus;
        vector<Student> students=getAllStudents();
        for (int i = 0; i < students.size(); ++i) {
            if(students.at(i).getDepartmentId()==deptID){
                stus.push_back(students.at(i));
            }
        }
        return stus;
    }

    // prints list of student in a specifies department
    void listOfStudents(const Department& dept){
//        CMD::clear();
        CMD::ukh();
        vector<Student> studs= findStudentsInDept(dept.getId());
        cout<<"\t\t\tList of ("<<dept.getName()<<") students:\n";
        for (int i = 0; i < studs.size(); ++i) {
            cout<<"\t\t\t"<<studs.at(i).getId()<<": "<<studs.at(i).getName()<<endl;
        }
    }//

    // it checks either student exist in a department or not
    int StudentExistInDepartment(const int studentId,const Department & dept){
    vector<Student> studentsInDept= findStudentsInDept(dept.getId());
    for (int i=0;i<studentsInDept.size();i++) {
        if(studentId==studentsInDept.at(i).getId()) return 1;
    }
    return 0;
}

    // it returns stage of module
    int getStageByModuleId(const int moduleId){
        vector<DepartmentModule> modules=getAllDepartmentModules();
        for (int i = 0; i < modules.size(); ++i) {
            if(modules.at(i).getModuleId()==moduleId) return modules.at(i).getStage();
        }
        return 0;
    }

    //it calculates average of a student marks for specified stage
    double calcMarkPerStage(const int stage,int studentId) {
        vector<StudentAssessment> assessments=getAllAssesments();
        double mark=0,average;int moduleCounter=0;
        for (int i = 0; i < assessments.size(); ++i) {
            StudentAssessment asses=assessments.at(i);
            if(asses.getStudentId()==studentId){
                if(stage==getStageByModuleId(assessments.at(i).getModuleId())){
                    ++moduleCounter;
                    mark +=asses.getAssignmentWeight()
                           +asses.getQuizWeight()
                           +asses.getMidtermWeight()
                           +asses.getFinalExamWeight();
                }
            }
        }
        average=mark/moduleCounter;
        return round(average);
    }

    //calculates overall attendance of a student
    void calculateOverallAttendance(const Department& dept){
        studentAttendace:
        //it prints UKH header
        CMD::ukh();
        cout<<"\t\t\tEnter Student ID:";
        int studentId;
        cin>>studentId;

        //validation of student exist or not
        if(studentId<=0 || !StudentExistInDepartment(studentId,dept)){
            cout<<"\n\t\t\tInvalid StudentID, try again..."<<endl<<endl;
            goto studentAttendace;
        }

        //filtering assessments for selected student
        vector<StudentAssessment> assessments=getAllAssesments();
        int attendance=0,moduleCounter=0;
        for (int i = 0; i < assessments.size(); ++i) {
            StudentAssessment asses=assessments.at(i);
            if(asses.getStudentId()==studentId){
                moduleCounter++;
                attendance +=assessments.at(i).getAttendance();
            }
        }
        cout<<"\n\t\t\tStudent Name : "<< getStudentById(studentId).getName();
        cout<<"\n\t\t\tOverall attendance : "<< round(attendance/moduleCounter)<<" %"<<endl<<endl;
    }

    //the method has been used to find overall student average
    void studentAverage(const Department& dept){
        studentAverage:
        //prints UKH header
        CMD::ukh();
        cout<<"\t\t\tEnter Student ID:";
        int studentId;
        cin>>studentId;
        if(studentId==0) exit(0);

        if(studentId<0 || !StudentExistInDepartment(studentId,dept)){
            cout<<"\n\t\t\tInvalid StudentID, try again..."<<endl<<endl;
            goto studentAverage;
        }
        cout<<"\n\t\t\tStudent Name : "<< getStudentById(studentId).getName()<<endl;

        //finds average of each year
        double stage1Average=calcMarkPerStage(1,studentId);
        double stage2Average=calcMarkPerStage(2,studentId);
        double stage3Average=calcMarkPerStage(3,studentId);
        double stage4Average=calcMarkPerStage(4,studentId);

        //finds overall average
        double overall=(stage1Average*0.1)
                +(stage2Average*0.2)
                +(stage3Average*0.3)
                +(stage4Average*0.4);

        //student marks per each year
        cout<<"\n\t\t\tStage 1 average : "<< stage1Average;
        cout<<"\n\t\t\tStage 2 average : "<< stage2Average;
        cout<<"\n\t\t\tStage 3 average : "<< stage3Average;
        cout<<"\n\t\t\tStage 4 average : "<< stage4Average;
        cout<<"\n\n\t\t\tOverall average : "<< overall<<endl;

        //student grading
        char grade;
        if (overall >= 90) {
            grade = 'A';
        }
        else if (overall >= 80) {
            grade = 'B';
        }
        else if (overall >= 70) {
            grade = 'C';
        }
        else if (overall >= 60) {
            grade = 'D';
        }
        else {
            grade = 'F';
        }

        cout<<"\n\t\t\tStudent Grade : "<< grade<<endl;

    }

    //it calculates and prints top students in a department
    void calculateTopStudents(const Department &dept){
        startTopStudents:
        //prints UKH header
        CMD::ukh();
        cout<<"\t\t\tEnter graduation year:";
        int year;
        cin>>year;
        //year validation
        if(year<2010 || year>getCurrentYear()) {
            cout<<"\n\t\t\tInvalid Year, try again..."<<endl<<endl;
            goto startTopStudents;
        };
        vector<Student> students=findStudentsInDept(dept.getId());
        vector<TopStudents> tops;

        for (int i = 0; i < students.size(); ++i) {
            int studentId=students.at(i).getId();
            int graduationYear=students.at(i).getGraduationDate();
            if(graduationYear==year){
                double overall=(calcMarkPerStage(1,studentId)*0.1)
                               +(calcMarkPerStage(2,studentId)*0.2)
                               +(calcMarkPerStage(3,studentId)*0.3)
                               +(calcMarkPerStage(4,studentId)*0.4);
                tops.emplace_back(studentId,overall);
                if(tops.size()==10) break;// only top 10 student
            }
        }

        //sorting by using heap sorting
        if(!tops.empty()){
            //heap sorting
            make_heap(tops.begin(), tops.end(), compareTopStudents);
            sort_heap(tops.begin(), tops.end(), compareTopStudents);
            //print students with their marks
            for (int i = 0; i < tops.size(); ++i) {
                cout<<"\n\t\t\t"<<i+1<<": "<< getStudentById(tops.at(i).studentId).getName()
                    <<" : "<<tops.at(i).overallMark<<endl;
            }
        }

    }

    //the menu of the program
    void StartProgram(){
        const vector<College>& colleges=getAllColleges();
        startCollege:
        //prints UKH header
        CMD::ukh();
        cout<<"\t\t\tList of Colleges:\n";
        for (int i = 0; i < colleges.size(); ++i) {
            cout<<"\t\t\t"<<colleges.at(i).getId()<<": "<<colleges.at(i).getName()<<endl;
        }
        cout<<"\n\t\t\tEnter <0> to Exit program"
            <<"\n\n\t\t\tEnter Your Choice:";
        int college_choice;
        cin>>college_choice;
        if(college_choice==0) exit(0);
        //college validation
        if(college_choice<0 || college_choice>colleges.size()){
            cout<<"\n\t\t\tCollege not found, try again..."<<endl<<endl;
            goto startCollege;
        }
        startDept:

        CMD::ukh();
        vector<Department> depts= findDepartmentsByCollege(college_choice);

//        CMD::clear();

        //prints departments
        if(depts.empty()){
            cout<<"\n\t\t\t"<<colleges.at(college_choice).getName()<<" has no department, please choose another college.\n"<<endl;
            goto startCollege;
        }else{
            cout<<"\t\t\t  List of Departments:\n";
            for (int i = 0; i < depts.size(); ++i) {
                cout<<"\t\t\t"<<i+1<<": "<<depts.at(i).getName()<<endl;
            }
        }

        cout<<"\n\t\t\tEnter <0> to Exit program"
            <<"\n\t\t\tEnter <-1> to choose another colleges"
            <<"\n\n\t\t\tEnter Your Choice:";

        int deptChoice;
        cin>>deptChoice;
        if(deptChoice<-1){
            goto startDept;
        }
        switch (deptChoice) {
            case -1:goto startCollege;
            case 0:exit(0);
        }
        Department dept=depts.at(deptChoice-1);

        CMD::ukh();
        startStu:
        cout<<"\n\t\t\t<1> List of ("<<dept.getName()<<") students"
            <<"\n\t\t\t<2> Student average & grade"
            <<"\n\t\t\t<3> ("<<dept.getName()<<") top 10 students"
            <<"\n\t\t\t<4> Overall Student attendance"

            <<"\n\t\t\tEnter <0> to Exit program"
            <<"\n\t\t\tEnter <-1> to choose another colleges"
            <<"\n\n\t\t\tEnter Your Choice:";
        int stuChoice;
        cin>>stuChoice;
        if(stuChoice<-1){
            return;
        }
        switch (stuChoice) {
            case 1:listOfStudents(dept);break;
            case 2:studentAverage(dept);break;
            case 3:calculateTopStudents(dept);break;
            case 4:calculateOverallAttendance(dept);break;
            case -1:goto startDept;
            case 0:exit(0);
            default:
                return;
        }
        goto startStu;
    }

    int main() {
        StartProgram();
        return 0;
    }