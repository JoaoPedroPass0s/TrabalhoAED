
#include "../Include/UCClass.h"
#include "../Include/GestaoHorario.h"
#include <fstream>
#include <string>
#include <vector>

void GestaoHorario::readFileStudents(){
    std::ifstream classes;
    classes.open("schedule/students_classes.csv");
    int i=0;
    string id="";
    string name="";
    vector<UCClass> classesstu;
    while(classes.good()){
        string line;
        getline(classes,line,',');
        switch(i){
            case 0:
                if(id==""){
                    id=line;
                }else if(id!=line){
                    Student student(id,name,classesstu);
                    students_.push_back(student);
                    id=line;
                    name="";
                    vector<UCClass> classesstu;
                    i=0;
                }
                i++;
                break;
            case 1:
                if(name==""){
                    name=line;
                }
                i++;
                break;
            case 2:
                string uc=line;
                getline(classes,line,',');
                UCClass ucClass(uc,line);
                classesstu.push_back(ucClass);
                i=0;
                break;
        }
    }
    cout << students_.size();
}

void GestaoHorario::saveRequest(){

}

void GestaoHorario::processRequest(){

}


