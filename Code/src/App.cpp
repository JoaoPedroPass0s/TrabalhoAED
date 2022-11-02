//
// Created by pedropassos on 01-11-2022.
//
#include <iostream>
#include "../Include/Student.h"
#include "../Include/App.h"
#include "../Include/Request.h"


using namespace std;

void App::start(){
    std::cout << "Hello, World!" << std::endl;
    horario.readFileStudents();
    horario.readFileClasses();
    while (true) {
        if(!printUserMenu()){
            break;
        }
    }
    if(!horario.requests_.empty()){
        cout << "Processing Requests..." << endl;
    }
    horario.processRequest();
    cout << "Closing App..." << endl;
}

bool App::printUserMenu() {
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
    cin.ignore();
    switch(operation){
        case 11:
            printMakeRequest();
            break;
        case 12:
            cancelRequest();
            break;
        case 13:
            printRequestList();
            break;
        case 21:
            printStudentSchedule();
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

void App::printStudentSchedule(){
    int code;
    cout <<    "╒═════════════════════════════════════════════╕\n"
               "│             Student Classes                 │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Write the student code to see Classes      │\n"
               "╞═════════════════════════════════════════════╡\n"
               "│  Return                                [1]  │\n"
               "╘═════════════════════════════════════════════╛\n"
               "                                               \n";
    cin >> code;
    cin.ignore();
    if(code!=1) {
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
        cin.ignore();
        cout << "Returning..." << endl;
    }
}

void App::printMakeRequest(){
    string stucode,uc,classe;
    cout <<    "╒═════════════════════════════════════════════════════════╕\n"
               "│                      Make Request                       │\n"
               "╞═════════════════════════════════════════════════════════╡\n"
               "│      To make a request write Student Code, Uc Code      │\n"
               "│          and the Class you want to change to.           │\n"
               "╞═════════════════════════════════════════════════════════╡\n"
               "│  Return                                            [1]  │\n"
               "╘═════════════════════════════════════════════════════════╛\n"
               "                                               \n";
    cout << "Write the Student Code:" << endl;
    cin >> stucode;
    cout << "Write the Uc Code:" << endl;
    cin >> uc;
    cout << "Write the Class Code:" << endl;
    cin >> classe;
    Request request(uc,classe,stucode);
    horario.saveRequest(request);
    cout << "Your request has been added to the queue and will be processed by the program. " << endl;
    cout << "Press Enter to return..." << endl;
    cin.ignore();
    cin.ignore();
    cout << "Returning..." << endl;
}

void App::printRequestList(){
    cout << "╒═════════════════════════════════════════════════════════════════╕\n";
    for(Request r:horario.requests_){
        cout << "  Student Code: " << r.getStudentCode() << " | Uc Code: " << r.getUc() << " | Class Code: " << r.getClass() << endl;
    }
    cout <<"╘═════════════════════════════════════════════════════════════════╛\n"
           "                                               \n";
    cout << "Press Enter to return..." << endl;
    cin.ignore();
    cout << "Returning..." << endl;
}

void App::cancelRequest(){
    string stucode,uc,classe,wait;
    cout <<    "╒═════════════════════════════════════════════════════════╕\n"
               "│                      Cancel Request                     │\n"
               "╞═════════════════════════════════════════════════════════╡\n"
               "│  To cancel a request write the Student Code, Uc Code    │\n"
               "│  and the Class Code of the request you want to cancel.  │\n"
               "╞═════════════════════════════════════════════════════════╡\n"
               "│  Return                                            [1]  │\n"
               "╘═════════════════════════════════════════════════════════╛\n"
               "                                               \n";
    cout << "Write the Student Code:" << endl;
    cin >> stucode;
    cout << "Write the Uc Code:" << endl;
    cin >> uc;
    cout << "Write the Class Code:" << endl;
    cin >> classe;
    vector<Request>::iterator i=horario.requests_.begin();
    bool b=false;
    for(Request r :horario.requests_){
        if(r.getUc()==uc && r.getStudentCode()==stucode && r.getClass()==classe){
            horario.requests_.erase(i);
            b=true;
        }
        i++;
    }
    if(b==true){
        cout << "Request Canceled..." << endl;
    }else{
        cout << "Error Request not found please insert valid request..." << endl;
    }
    cout << "Press Enter to return..." << endl;
    cin.ignore();
    cin.ignore();
    cout << "Returning..." << endl;
}