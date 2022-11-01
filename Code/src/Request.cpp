

#include "../Include/Request.h"

string Request::getUc() const {return uc_;}
string Request::getClass() const {return class_;}
string Request::getStudentCode() const {return studentCode_;}

Request::Request(string uc, string classe, string studentCode): uc_(uc), class_(classe), studentCode_(studentCode) {}