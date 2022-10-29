

#ifndef TRABALHOAED_GESTAOHORARIO_H
#define TRABALHOAED_GESTAOHORARIO_H
#include "../Include/Student.h"
#include "../Include/HClass.h"
#include "../Include/Request.h"



class GestaoHorario {
    public:
        void readFileStudents();
        void saveRequest();
        void processRequest();
    private:
        set <Student> students;
        vector <HClass> horario;
        queue <Request> requests;
};


#endif //TRABALHOAED_GESTAOHORARIO_H
