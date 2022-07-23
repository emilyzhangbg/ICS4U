#include <fstream>
#include "Teacher.h"
#include "Student.h"

//constructors
Teacher::Teacher(string fileName) {
  //opening file to read
  ifstream inFile;
  inFile.open(fileName);
  
  //test for error
  if(inFile.fail()) {
    cerr << fileName << " does not exist" << endl;
    exit(1);
  }

  //read in info about teacher and store
  inFile >> sections;
  inFile >> teacheables;
  
  string id , f, l, a;
  inFile >> id;
  inFile >> f;
  inFile >> l;
  getline(inFile, a); //gets the \n character that is left over
  getline(inFile, a);

  setFirstName(f);
  setLastName(l);
  setAddress(a);

  if (isValidId(id))
    employeeId = id;
  else
    employeeId = "invalid id";

  //read in info about students and store in class list
  inFile >> numStudents;
  classList = new Student[MAX_STUDENTS];

  for (int i = 0; i < numStudents; i++) {
    inFile >> f;
    inFile >> l;
    classList[i] = Student(f , l);
  }

  inFile.close();
}

Teacher::Teacher(string first, string last)
  : Person(first, last) {
  teacheables = "no classes";
  employeeId = "undefined";
  sections = 0;
  numStudents = 0;
  sections = 0;
  classList = new Student[MAX_STUDENTS];
}

Teacher::Teacher(string f, string l, string a, string t, string id, int sections) 
  : Person(f, l, a) {
  teacheables = t;
  numStudents = 0;
  classList = new Student[MAX_STUDENTS];
    
  if (isValidId(id))
    employeeId = id;
  else
    employeeId = "invalid id";
}

Teacher::Teacher(string f, string l, string t, string id)
  : Person(f, l) {
  teacheables = t;
  numStudents = 0;
  sections = 0;
  classList = new Student[MAX_STUDENTS];
    
  if (isValidId(id))
    employeeId = id;
  else
    employeeId = "invalid id";
}

Teacher::~Teacher() {
  delete[] classList;
}

//check if ID is valid
bool Teacher::isValidId(string id) {
  if (id.length() != 6)
    return false;

  if (toupper(id[0]) != 'C')
    return false;

  for (int i = 1; i < 6; i++) {
    if (!isdigit(id[i]))
      return false;
  }

  employeeId[0] = toupper(id[0]);
  
  return true;
}

//setter and getters
string Teacher::getTeachables() {
  return teacheables;  
}

string Teacher::getEmployeeId() {
  return employeeId;
}

void Teacher::setTeachables(string t) {
  teacheables = t;
}

void Teacher::setEmployeeId(string id) {
  if (isValidId(id))
    employeeId = id;
  else
    employeeId = "invalid id";
}

//action
void Teacher::markStudentLate(Student &s) {
  s.addLate();
}

string Teacher::toString() {
  string output = getFirstName() + " " + getLastName() +  " resides at " + getAddress() + "\nTeacheable: " + teacheables + "\nTeacher ID: " + employeeId + "\nThey teach " + to_string(sections) + " section(s).";
  return output;
}
