#include "../Include/HClass.h"
#include <string>

string HClass::getClass() const {return class_; }
string HClass::getUc() const {return uc_; }
list<Slot> HClass::getClassUcHour() const {return classUcHour_; }
list<Student> HClass::getStudentList() const {return liststudents_;}

HClass::HClass(string uc, string classes): uc_(uc), class_(classes){}

void HClass::InsertStudent(Student s) {liststudents_.push_back(s);}
void HClass::InsertClassUCHour(Slot s) {classUcHour_.push_back(s);}