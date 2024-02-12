//
// Created by Azmir.Sleman on 1/11/2024.
//

#ifndef STUDENTASSESSMENT_H
#define STUDENTASSESSMENT_H

class StudentAssessment {
private:
    int studentId;
    int moduleId;
    double quizWeight;
    double midtermWeight;
    double assignmentWeight;
    double finalExamWeight;
    int attendance;

public:
    StudentAssessment(int studentId, int moduleId, double quizWeight, double midtermWeight, double assignmentWeight,
                      double finalExamWeight, int attendance);

    int getStudentId() const;
    void setStudentId(int studentId);

    int getModuleId() const;
    void setModuleId(int moduleId);

    double getQuizWeight() const;
    void setQuizWeight(double quizWeight);

    double getMidtermWeight() const;
    void setMidtermWeight(double midtermWeight);

    double getAssignmentWeight() const;
    void setAssignmentWeight(double assignmentWeight);

    double getFinalExamWeight() const;
    void setFinalExamWeight(double finalExamWeight);

    int getAttendance() const;
    void setAttendance(int attendance);
};

#endif // STUDENTASSESSMENT_H

