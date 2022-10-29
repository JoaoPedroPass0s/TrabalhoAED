

#ifndef TRABALHOAED_STUDENT_H
#define TRABALHOAED_STUDENT_H
#include "../Include/UCClass.h"
#include <iostream>
#include <list>


class Student {
public:

private:
    int stuCode_;
    char stuName_;
    std::list<UCClass> classes_;
};


#endif //TRABALHOAED_STUDENT_H
