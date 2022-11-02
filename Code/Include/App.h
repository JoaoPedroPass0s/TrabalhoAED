//
// Created by pedropassos on 01-11-2022.
//

#ifndef TRABALHOAED_APP_H
#define TRABALHOAED_APP_H
#include "GestaoHorario.h"


class App {
public:
    void start();
    bool printUserMenu();
    void printStudentSchedule();
    void printMakeRequest();
    void printRequestList();
private:
    GestaoHorario horario;
};


#endif //TRABALHOAED_APP_H
