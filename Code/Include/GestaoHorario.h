

#ifndef TRABALHOAED_GESTAOHORARIO_H
#define TRABALHOAED_GESTAOHORARIO_H

#include <set>
#include <queue>
#include "../Include/Student.h"
#include "../Include/HClass.h"
#include "../Include/Request.h"



class GestaoHorario {
    public:
        void readFileStudents();
        void saveRequest();
        void processRequest();
    private:
        std::set <Student> students_;
        std::vector <HClass> horario_;
        std::queue <Request> requests_;
};


#endif //TRABALHOAED_GESTAOHORARIO_H
