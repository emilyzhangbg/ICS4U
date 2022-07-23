#include "Student.h"

//constructors
Student::Student() 
  : Person() {}

Student::Student(string first, string last) 
  : Person(first, last) {
  grade = 0;
  studentId = "undefined";
  numLate = 0;
}

Student::Student(string f, string l, string a, int g, string id) 
  : Person(f, l, a) {
  if (g >= 0 && g <= 100)
    grade = g;
  else
    grade = 0;

  if (isValidId(id))
    studentId = id;
  else
    studentId = "invalid id";
    
  numLate = 0;    
}

Student::Student(string f, string l, int g, string id) 
  : Person(f, l) {
  if (g >= 0 && g <= 100)
    grade = g;
  else
    grade = 0;

  if (isValidId(id))
    studentId = id;
  else
    studentId = "invalid id";
    
  numLate = 0;
}

bool Student::isValidId(string id) {
  if (id.length() != 10)
    return false;

  if (toupper(id[0]) != 'S')
    return false;

  for (int i = 1; i < 10; i++) {
    if (!isdigit(id[i]))
      return false;
  }

  return true;
}

//getter and setters
int Student::getGrade() {
  return grade;
}

string Student::getStudentId() {
  return studentId;
}

int Student::getNumLates() {
  return numLate;
}

void Student::setGrade(int n) {
  if (n >= 0 && n <= 100)
    grade = n;
  else
    grade = 0;
}

void Student::setStudentId(string id) {
  if (isValidId(id))
    studentId = id;
  else
    studentId = "invalid id";
}

//actions
void Student::addLate() {
  numLate++;
}

string Student::toString() {
  string output = getFirstName() + " " + getLastName() +  " resides at " + getAddress() + "\nGrade: " + to_string(grade) + "\nStudent ID: " + studentId + "\nLates: " + to_string(numLate);
  return output;
}
