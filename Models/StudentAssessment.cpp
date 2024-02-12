//
// Created by Azmir.Sleman on 12/20/2023.
//

#include "StudentAssessment.h"

//constructor
StudentAssessment::StudentAssessment(int studentId, int moduleId, double quizWeight, double midtermWeight,
                                     double assignmentWeight, double finalExamWeight, int attendance)
        : studentId(studentId), moduleId(moduleId), quizWeight(quizWeight), midtermWeight(midtermWeight),
          assignmentWeight(assignmentWeight), finalExamWeight(finalExamWeight), attendance(attendance) {}

//setters and getters
int StudentAssessment::getStudentId() const {
    return studentId;
}

void StudentAssessment::setStudentId(int studentId) {
    StudentAssessment::studentId = studentId;
}

int StudentAssessment::getModuleId() const {
    return moduleId;
}

void StudentAssessment::setModuleId(int moduleId) {
    StudentAssessment::moduleId = moduleId;
}

double StudentAssessment::getQuizWeight() const {
    return quizWeight;
}

void StudentAssessment::setQuizWeight(double quizWeight) {
    StudentAssessment::quizWeight = quizWeight;
}

double StudentAssessment::getMidtermWeight() const {
    return midtermWeight;
}

void StudentAssessment::setMidtermWeight(double midtermWeight) {
    StudentAssessment::midtermWeight = midtermWeight;
}

double StudentAssessment::getAssignmentWeight() const {
    return assignmentWeight;
}

void StudentAssessment::setAssignmentWeight(double assignmentWeight) {
    StudentAssessment::assignmentWeight = assignmentWeight;
}

double StudentAssessment::getFinalExamWeight() const {
    return finalExamWeight;
}

void StudentAssessment::setFinalExamWeight(double finalExamWeight) {
    StudentAssessment::finalExamWeight = finalExamWeight;
}

int StudentAssessment::getAttendance() const {
    return attendance;
}

void StudentAssessment::setAttendance(int attendance) {
    StudentAssessment::attendance = attendance;
}
