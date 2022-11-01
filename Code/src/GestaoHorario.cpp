
#include "../Include/UCClass.h"
#include "../Include/GestaoHorario.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void GestaoHorario::readFileStudents(){
    std::ifstream classes;
    classes.open("/home/pedropassos/TrabalhoAED/Code/schedule/students_classes.csv");
    int i=0;
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
            vector<UCClass> classesStu;
        }
        UCClass ucClass(ucCode,classCode);
        classesStu.push_back(ucClass);
    }
    Student student(id,name,classesStu);
    students_.push_back(student);
}

void GestaoHorario::saveRequest(){

}

void GestaoHorario::processRequest(){

}

void GestaoHorario::listAllStudents(){
    for(Student s:students_){
        cout << s.getName() << " " << s.getId() << endl;
    }
}


