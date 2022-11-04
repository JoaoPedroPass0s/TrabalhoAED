#include "../Include/Student.h"
#include <string>
#include <vector>

Student::Student(string id, string name,vector<UCClass> classes): id_(id), name_(name),classes_(classes) {}
/*
bool Student::operator==(const Student &s) const { return ("x" == s."x"); }
bool Student::operator>(const Student &s) const {return ("x" > s."x"); }
bool Student::operator<(const Student &s) const {return ("x" < s."x"); }
*/
Student::Student(){}
string Student::getName() const {return name_; }
string Student::getId() const {return id_; }
vector<UCClass> Student::getClasses() const {return classes_; }

void Student::RemoveClass(Request r) {
    vector<UCClass>::iterator i;
    i=classes_.begin();
    for(UCClass u:classes_){
        if(u.getUc()==r.getUc() && u.getClass()==r.getClassIn()){
            classes_.erase(i);
        }
        i++;
    }
}