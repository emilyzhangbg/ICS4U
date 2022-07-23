#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
  private:
    string firstName;
    string lastName;
    string address;

  private:
    //pure virtual function requires to be overwritten in all derived classes
    //classes that contain a pure virtual function are abstract classes
    //https://www.youtube.com/watch?v=ndz3EHpFEZc
    virtual bool isValidId(string id) = 0; 

  public:
    //constructor
    Person();
    Person(string first, string last);
    Person(string first, string last, string add);
    //getter and setter
    string getFirstName();
    string getLastName();
    string getAddress();
    void setFirstName(string n);
    void setLastName(string n);
    void setAddress(string a);
    //virtual function that has a definition but can be overwritten in deried classes
    virtual string toString();
};

#endif
