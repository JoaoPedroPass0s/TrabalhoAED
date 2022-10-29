<<<<<<< HEAD
//
// Created by pedropassos on 29-10-2022.
//

#ifndef TRABALHOAED_GESTAOHORARIO_H
#define TRABALHOAED_GESTAOHORARIO_H
=======


#ifndef TRABALHOAED_GESTAOHORARIO_H
#define TRABALHOAED_GESTAOHORARIO_H
#include "../Include/Student.h"
#include "../Include/HTurma.h"
#include "../Include/Request.h"
>>>>>>> ebd37eb (classesStudent_Hturma_Request)


class GestaoHorario {
    public:
        void readFileStudents();
        void saveRequest();
        void processRequest();
<<<<<<< HEAD

=======
    private:
        set <Student> estudantes;
        vector <HTurma> horario;
        queue <Request> pedidos;
>>>>>>> ebd37eb (classesStudent_Hturma_Request)
};


#endif //TRABALHOAED_GESTAOHORARIO_H
