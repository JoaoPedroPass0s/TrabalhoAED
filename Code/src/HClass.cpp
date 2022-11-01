#include "../Include/HClass.h"
#include <string>

string HClass::getClass() const {return class_; }
string HClass::getUc() const {return uc_; }
list<Slot> HClass::getClassUcHour() const {return classUcHour_; }

HClass::HClass(string uc, string classes, list<Slot> classUcHour): uc_(uc), class_(classes), classUcHour_(classUcHour) {}