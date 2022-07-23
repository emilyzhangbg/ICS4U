#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
  private:
    int grade;
    string studentId;
    int numLate;

  private:
    virtual bool isValidId(string id);

  public:
    //constructor
    Student();
    Student(string first, string last);
    Student(string f, string l, string a, int g, string id);
    Student(string f, string l, int g, string id);
    //getter and setters
    int getGrade();
    string getStudentId();
    int getNumLates();
    void setGrade(int n);
    void setStudentId(string id);
    //actions
    void addLate();
    virtual string toString();
};

#endif
