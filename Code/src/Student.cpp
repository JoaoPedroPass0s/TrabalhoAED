#include "../Include/Student.h"
#include <string>
#include <vector>

Student::Student(string id, string name): id_(id), name_(name) {}

bool Student::operator==(const Student &s) const { return ("x" == s."x"); }
bool Student::operator>(const Student &s) const {return ("x" > s."x"); }
bool Student::operator<(const Student &s) const {return ("x" < s."x"); }

string Student::getName() const {return name_; }
string Student::getId() const {return id_; }
vector<UCClass> Student::getClasses() const {return classes_; }