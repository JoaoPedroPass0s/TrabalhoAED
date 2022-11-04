#ifndef TRABALHOAED_STUDENT_H
#define TRABALHOAED_STUDENT_H
#include "../Include/UCClass.h"
#include "Request.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
    Student(string id, string name,vector<UCClass> classes);
    Student();
    string getId() const;
    string getName() const;
    vector<UCClass> getClasses() const;
    bool RemoveClass(Request);
    void addClass(string,string);
private:
    string id_;
    string name_;
    vector<UCClass> classes_;
};

#endif //TRABALHOAED_STUDENT_H
