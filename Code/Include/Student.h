#ifndef TRABALHOAED_STUDENT_H
#define TRABALHOAED_STUDENT_H
#include "../Include/UCClass.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>

class Student {
public:
    Student(string id, string name);
    string getId() const;
    string getName() const;
    vector<UcClass> getClasses() const;
    bool operator== (const Student &s) const;
    bool operator< (const Student &s) const;
    bool operator> (const Student &s) const;

private:
    string id_;
    string name_;
    vector<UcClass> classes_;
};

#endif //TRABALHOAED_STUDENT_H
