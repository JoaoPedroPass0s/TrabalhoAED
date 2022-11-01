//
// Created by pedropassos on 01-11-2022.
//
#include <iostream>
#include "../Include/Student.h"
#include "../Include/App.h"


using namespace std;

void App::start(){
    std::cout << "Hello, World!" << std::endl;
    GestaoHorario horario;
    horario.readFileStudents();
    horario.readFileClasses();
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
               "│  Make Request                          [11] │  View Student Classes                  [21] │\n"
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

        case 12:

        case 13:

        case 21:
            printStudentSchedule(horario);
            break;
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

void App::printStudentSchedule(GestaoHorario horario){
    string code;
    cout <<    "╒═════════════════════════════════════════════╕\n"
               "│             Student Classes                 │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Write the student code to see Classes      │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Return                                [1]  │\n"
               "╘═════════════════════════════════════════════╛\n"
               "                                               \n";
    cin >> code;
    if(code!="1") {
        Student student;
        for (Student s: horario.students_) {
            if (s.getId() == code) {
                student=s;
                break;
            }
        }
        cout <<    "╒═════════════════════════════════════════════╕\n"
                   "                Name: "<< student.getName() << endl <<
                   "╞═════════════════════════════════════════════╡\n";
        for(UCClass uc:student.getClasses()){
            cout <<    "                 "<< uc.getUc() << endl <<
                       "                 "<< uc.getClass() << endl <<
                       "╞═════════════════════════════════════════════╡\n";
        }
        cout << "│  Return                                [1]  │\n"
                "╘═════════════════════════════════════════════╛\n"
                "                                               \n";
        cin >> code;
    }
}