

#ifndef TRABALHOAED_HCLASS_H
#define TRABALHOAED_HCLASS_H

#include <list>
#include "../Include/Slot.h"
#include "Student.h"

using namespace std;


class HClass {
public:
    HClass(string uc, string classes);
    HClass();
    string getUc() const;
    string getClass() const;
    list<Slot> getClassUcHour() const;
    vector<Student> getStudentList() const;
    void InsertStudent(Student);
    void InsertClassUCHour(Slot);
private:
    list<Slot> classUcHour_;
    vector<Student> liststudents_;
    string uc_;
    string class_;
};


#endif //TRABALHOAED_HCLASS_H
