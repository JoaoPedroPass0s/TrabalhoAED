

#ifndef TRABALHOAED_GESTAOHORARIO_H
#define TRABALHOAED_GESTAOHORARIO_H

#include <set>
#include <queue>
#include "Student.h"
#include "HClass.h"
#include "Request.h"
using namespace std;


class GestaoHorario {
public:
    void readFileStudents();
    void saveRequest(Request request);
    void processRequest();
    void listAllStudents();
    void readFileClasses();
    unsigned long binarySearchHorario(const UCClass &ucclass) const;

private:
    vector<Student> students_;
    vector<HClass> horarioC_;
    vector<Request> requests_;
};


#endif //TRABALHOAED_GESTAOHORARIO_H


