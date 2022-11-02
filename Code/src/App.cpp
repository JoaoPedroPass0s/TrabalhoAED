//
// Created by pedropassos on 01-11-2022.
//
#include <iostream>
#include "App.h"


using namespace std;

void App::start(){
    std::cout << "Hello, World!" << std::endl;
    GestaoHorario horario;
    horario.readFileStudents();
    horario.saveRequest();
    horario.processRequest();
    while (true) {
        if(!printUserMenu(horario)){
            break;
        }
    }
    cout << "Closing App...";
}

bool App::printUserMenu(GestaoHorario horario) {
    int operation;
    cout <<    "╒═════════════════════════════════════════════╤═════════════════════════════════════════════╕\n"
               "│             Request Management              │             Schedule Visualization          │\n"
               "╞═════════════════════════════════════════════╪═════════════════════════════════════════════╡\n"
               "│  Make Request                          [11] │  View Student Schedule                 [21] │\n"
               "│  Cancel Request                        [12] │  View UC Classes                       [22] │\n"
               "│  Request list                          [13] │  View UC Schedule                      [23] │\n"
               "╞═════════════════════════════════════════════╡  View Student List                     [24] │\n"
               "│                Other operations             │                                             │\n"
               "╞═════════════════════════════════════════════╡                                             │\n"
               "│  Exit                                  [31] │                                             │\n"
               "╘═════════════════════════════════════════════╧═════════════════════════════════════════════╛\n"
               "                                                                                             \n";
    cin >> operation;
    switch(operation){
        case 11:
            printStudentSchedule();
        case 12:

        case 13:

        case 21:

        case 22:

        case 23:

        case 24:
            horario.listAllStudents();
            break;
        case 31:
            return false;
    }
    return true;
}

void App::printStudentSchedule(){

}