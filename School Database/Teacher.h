#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"
#include "Student.h"

class Teacher: public Person {
  private:
    string teacheables;
    string employeeId;
    int sections;
    static const int MAX_STUDENTS = 100;
    int numStudents; 
    Student *classList;

  private:
    virtual bool isValidId(string id);

  public:
    //friend function to print
    friend void printClassList(Teacher &t);
    //constructors and destructor
    Teacher(string fileName);
    Teacher(string first, string last);
    Teacher(string f, string l, string a, string t, string id, int sections = 0);
    Teacher(string f, string l, string t, string id);
    ~Teacher();
    //getter and setters
    string getTeachables();
    string getEmployeeId();
    void setTeachables(string t);
    void setEmployeeId(string id);
    //actions
    void markStudentLate(Student &s);
    virtual string toString();
};

#endif
