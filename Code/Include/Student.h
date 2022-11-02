#ifndef TRABALHOAED_STUDENT_H
#define TRABALHOAED_STUDENT_H
#include "../Include/UCClass.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
    Student(int id, string name,vector<UCClass> classes);

    int getId() const;
    string getName() const;
    vector<UCClass> getClasses() const;

    bool operator== (const Student &s) const;
    bool operator< (const Student &s) const;
    bool operator> (const Student &s) const;

private:
    int id_;
    string name_;
    vector<UCClass> classes_;
};

#endif //TRABALHOAED_STUDENT_H
