#include "Person.h"

//constructors
Person::Person() {
  firstName = "John";
  lastName = "Smith";
  address = "123 Example Street";
}

Person::Person(string first, string last) {
  firstName = first;
  lastName = last;
  address = "unknown";
}
  
Person::Person(string first, string last, string add) {
  firstName = first;
  lastName = last;
  address = add; 
}

//getter and setters
string Person::getFirstName() {
  return firstName;
}

string Person::getLastName() {
  return lastName;
}

string Person::getAddress() {
  return address;
}

void Person::setFirstName(string n) {
  firstName = n;
}

void Person::setLastName(string n) {
  lastName = n;
}

void Person::setAddress(string a) {
  address = a;
}

//actions
string Person::toString() {
  string output = firstName + " " + lastName + " resides at " + address;
  return output;
}
