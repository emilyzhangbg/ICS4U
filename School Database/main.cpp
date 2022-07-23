#include <iostream>
#include "Teacher.h"
#include "Student.h"
using namespace std;

void printClassList(Teacher &t); // friend function

int main() {
  Teacher p2("Jim", "Bai");
  cout << p2.toString() << endl;

  cout << endl;

  Student p3("Sarah", "Benomar", 100, "S121200033");
  p2.markStudentLate(p3);
  cout << p3.toString() << endl;

  cout << endl;

  //upcasting teacher to person
  //they quit
  Person *p4 = &p2; 

  //creating teacher object from reading from a file
  Teacher p5("Teacher_Info/Barney_Andre.txt");
  cout << p5.toString() << endl;

  cout << endl;


  Teacher p6("Teacher_Info/Shery_Worne.txt");
  cout << p6.toString() << endl;

  cout << endl;
  
  Teacher p7("Teacher_Info/Jonathan_Howle.txt");
  cout << p7.toString() << endl;

  cout << "\nStudents taking " << p7.getTeachables() << " with " << p7.getLastName() << ": "<< endl;
  cout << "----------------" << endl;

  printClassList(p7);
}

void printClassList(Teacher &t) {
  for (int i = 0; i < t.numStudents; i++) {
    cout << i+1 << ". " << t.classList[i].toString() << endl;
    cout << "---" << endl;
  }
}
