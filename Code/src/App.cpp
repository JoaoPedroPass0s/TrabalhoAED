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
            while (true) {
                if(!printMakeRequest()){
                    break;
                }
            }
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

bool App::printMakeRequest(){
    string stucode,uc,classein,classeout;
    int chose;
    cout <<    "╒═════════════════════════════════════════════════════════╕\n"
               "│          Make Request - Chose the type of Request       │\n"
               "╞═════════════════════════════════════════════════════════╡\n"
               "│  Remove Student from Class                         [1]  │\n"
               "│  Add a Student to a Class                          [2]  │\n"
               "│  Change the Class of a Student                     [3]  │\n"
               "│  Change multiple Classes of a Student              [4]  │\n"
               "╞═════════════════════════════════════════════════════════╡\n"
               "│  Return                                            [5]  │\n"
               "╘═════════════════════════════════════════════════════════╛\n"
               "                                               \n";
    cin >> chose;
    if(chose==5){
        return false;
    }
    cout << "Write the Student Code:" << endl;
    cin >> stucode;
    cout << "Write the Uc Code:" << endl;
    cin >> uc;
    if(chose>=1 and chose<=5){
        switch(chose){
            case 1: {
                cout << "Write the Code of the Class you want to remove the student of:" << endl;
                cin >> classein;
                Request r(uc, classein, "", stucode, "Remove");
                horario.requests_.push_back(r);
                break;
            }
            case 2: {
                cout << "Write the Class Code you want to change the student too:" << endl;
                cin >> classeout;
                Request i(uc, "", classeout, stucode, "Add");
                horario.requests_.push_back(i);
                break;
            }
            case 3: {
                cout << "Write the Current Class Code:" << endl;
                cin >> classein;
                cout << "Write the Class Code you want to change too:" << endl;
                cin >> classeout;
                Request o(uc, classein, classeout, stucode, "Change");
                horario.requests_.push_back(o);
                break;
            }
            case 4: {
                while (true) {
                    cout << "Write the Current Class Code:" << endl;
                    cin >> classein;
                    cout << "Write the Class Code you want to change too:" << endl;
                    cin >> classeout;
                    Request o(uc, classein, classeout, stucode, "Change");
                    horario.requests_.push_back(o);
                    cout << "To Stop write 1 to continue write 2..." << endl;
                    cin >> chose;
                    if (chose == 1) {
                        break;
                    }
                }
                break;
            }
        }
        cout << "Your request has been added to the queue and will be processed by the program. " << endl;
        cout << "Press Enter to return..." << endl;
        cin.ignore();
        cin.ignore();
        cout << "Returning..." << endl;
    }else{
        cout << "Error chose a valid option..." << endl;
    }
    return true;
}

void App::printRequestList(){
    cout << "╒════════════════════════════════════════════════════════════════════════════════════════════════════════════╕\n";
    if(horario.requests_.empty()){
        cout << "                                There are no requests in queue..." << endl;
    }
    for(Request r:horario.requests_){
        cout << "  Student Code: " << r.getStudentCode() << " | Uc Code: " << r.getUc()
        << " | Current Class Code: " << r.getClassIn() << " | Target Class Code: "<< r.getClassOut() << " | Request Type: " << r.getRequestType() << endl;
    }
    cout <<"╘════════════════════════════════════════════════════════════════════════════════════════════════════════════╛\n"
           "                                               \n";
    cout << "Press Enter to return..." << endl;
    cin.ignore();
    cout << "Returning..." << endl;
}

void App::cancelRequest(){
    int i=0,o;
    cout << "╒════════════════════════════════════════════════════════════════════════════════════════════════════════════╕\n"
            "│                           Cancel Request - Chose the Request you want to Cancel                            │\n"
            "╞════════════════════════════════════════════════════════════════════════════════════════════════════════════╡\n";
    for(Request r:horario.requests_){
        i++;
        cout << "  Student Code: " << r.getStudentCode() << " | Uc Code: " << r.getUc()
             << " | Current Class Code: " << r.getClassIn() << " | Target Class Code: "<< r.getClassOut() << " | Request Type: "
             << r.getRequestType() << " ["<< i <<"]" << endl;
    }
    cout << "╞════════════════════════════════════════════════════════════════════════════════════════════════════════════╡\n"
            "│  Return                                                                                               ["<< i+1 << "]  │\n"
            "╘════════════════════════════════════════════════════════════════════════════════════════════════════════════╛\n";
    cin >> o;
    if(!i+1==o) {
        vector<Request>::iterator ite = horario.requests_.begin();
        while (o != 0) {
            ite++;
            o--;
        }
        horario.requests_.erase(ite);
        cout << "Request Canceled..." << endl;
    }
    cout << "Press Enter to return..." << endl;
    cin.ignore();
    cin.ignore();
    cout << "Returning..." << endl;
}