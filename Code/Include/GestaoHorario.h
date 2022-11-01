

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
        void saveRequest();
        void processRequest();
        void listAllStudents();
    private:
        vector <HClass> horario_;
        queue <Request> requests_;
        vector <Student> students_;
};


#endif //TRABALHOAED_GESTAOHORARIO_H


