
#include "../Include/UCClass.h"
#include "../Include/GestaoHorario.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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
    string classCode="";
    string ucCode="";
    string line;
    list<Slot> classUChour;
    while(getline(classes,line)){
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
        double start =atoi(startHour.c_str());
        getline(inputString,duration,',');
        double endHour = start + atoi(duration.c_str());
        getline(inputString,classType,',');
        if(ucCode==""){
            ucCode=ucCode_;
            classCode=classCode_;
        }
        if(ucCode!=ucCode_){
            HClass classH(ucCode,classCode,classUChour);
            horarioC_.push_back(classH);
            ucCode=ucCode_;
            classCode=classCode_;
            classUChour.clear();
        }
        Slot slot(weekDay,start,endHour,classType);
        classUChour.push_back(slot);
    }
    HClass classH(ucCode,classCode,classUChour);
    horarioC_.push_back(classH);
}

void GestaoHorario::saveRequest(){

}

void GestaoHorario::processRequest(){

}

void GestaoHorario::listAllStudents(){
    for(Student s:students_){
        cout << s.getName() << " " << s.getId()<< endl;
    }
}


