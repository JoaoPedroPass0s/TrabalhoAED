

#ifndef TRABALHOAED_STUDENT_H
#define TRABALHOAED_STUDENT_H
#include "../Include/UCClass.h"
#include <iostream>
#include <list>


class Student {
public:
    int stuCode;
    char stuName;
    std::list<UCClass> classes;
};


#endif //TRABALHOAED_STUDENT_H
