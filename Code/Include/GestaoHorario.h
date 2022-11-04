

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
    void readFileRequests();
    void readFileClasses();
    void saveRequest(Request request);
    void processRequest();
    void listAllStudents();
    void addStudentsToClasses();
    bool canClassesBeTogether(UCClass,UCClass);
    unsigned long binarySearchHorario(const UCClass &ucclass) const;
    vector<Student> students_;
    vector<HClass> horarioC_;
    vector<Request> requests_;
};


#endif //TRABALHOAED_GESTAOHORARIO_H


