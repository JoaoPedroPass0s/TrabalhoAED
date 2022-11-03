
#include "../Include/UCClass.h"
#include "../Include/GestaoHorario.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>

void GestaoHorario::readFileStudents(){
    std::ifstream classes;
    classes.open("/home/pedropassos/TrabalhoAED/Code/schedule/students_classes.csv");
    string id="";
    string name="";
    string line;
    vector<UCClass> classesStu;
    while(getline(classes,line)){
        stringstream inputString(line);
        string ucCode;
        string classCode;
        string nameStu;
        string idStu;
        getline(inputString,idStu,',');
        getline(inputString,nameStu,',');
        getline(inputString,ucCode,',');
        getline(inputString,classCode,',');
        if(id==""){
            id=idStu;
            name=nameStu;
        }
        if(id!=idStu){
            Student student(id,name,classesStu);
            students_.push_back(student);
            id=idStu;
            name=nameStu;
            classesStu.clear();
        }
        UCClass ucClass(ucCode,classCode);
        classesStu.push_back(ucClass);
    }
    Student student(id,name,classesStu);
    students_.push_back(student);
}

void GestaoHorario::readFileClasses(){
    std::ifstream classes;
    classes.open("/home/pedropassos/TrabalhoAED/Code/schedule/classes.csv");
    string line;
    list<Slot> classUChour;
    while(getline(classes,line)){
        bool b=true;
        stringstream inputString(line);
        string ucCode_;
        string classCode_;
        string weekDay;
        string startHour;
        string duration;
        string classType;
        getline(inputString,classCode_,',');
        getline(inputString,ucCode_,',');
        getline(inputString,weekDay,',');
        getline(inputString,startHour,',');
        double start =atof(startHour.c_str());
        getline(inputString,duration,',');
        double endHour = start + atof(duration.c_str());
        getline(inputString,classType,',');
        for(HClass h:horarioC_){
            if(h.getUc()==ucCode_ && h.getClass()==classCode_){
                b=false;
                Slot s(weekDay,start,endHour,classType);
                h.InsertClassUCHour(s);
                break;
            }
        }
        if(b){
            HClass h(ucCode_,classCode_);
            Slot s(weekDay,start,endHour,classType);
            h.InsertClassUCHour(s);
            horarioC_.push_back(h);
        }

    }
}

void GestaoHorario::saveRequest(Request request){
    requests_.push_back(request);
}

void GestaoHorario::processRequest(){
    for(Request r:requests_){

    }
}

void GestaoHorario::listAllStudents(){
    string wait;
    for(Student s:students_){
        cout << s.getName() << " " << s.getId()<< endl;
    }
    cout << "Number of Students:" << students_.size() << endl;
    cout << "Press Enter to return..." << endl;
    cin.ignore();
    cout << "Returning..." << endl;
}

void GestaoHorario::AddStudentsToClasses() {
    for(Student s:students_){
        for(UCClass u:s.getClasses()){
            for(HClass h:horarioC_){
                if(h.getUc()==u.getUc() and h.getClass()==u.getClass()){
                    h.InsertStudent(s);
                }
            }
        }
    }
}

unsigned long GestaoHorario::binarySearchHorario(const UCClass &ucclass) const {
    /*
    unsigned long left = 0;
    unsigned long right =
     */
}