#include "../Include/UCClass.h"
#include <string>

UCClass::UCClass(string uc, string classes): uc_(uc), class_(classes) {}
string UCClass::getUc() const {return uc_; }
string UCClass::getClass() const {return class_; }