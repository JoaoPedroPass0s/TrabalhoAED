//
// Created by pedropassos on 01-11-2022.
//

#ifndef TRABALHOAED_APP_H
#define TRABALHOAED_APP_H
#include "GestaoHorario.h"


class App {
public:
    void start();
    bool printUserMenu(GestaoHorario);
    void printStudentSchedule(GestaoHorario);
    void printMakeRequest(GestaoHorario horario);
};


#endif //TRABALHOAED_APP_H
