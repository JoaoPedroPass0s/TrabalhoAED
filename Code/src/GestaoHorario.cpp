

#include "../Include/GestaoHorario.h"
#include <fstream>
#include <string>

void readFileStudents(){
    std::ifstream classes;
    classes.open("students_classes.cvs");
    int i=0;
    while(classes.good()){
        std::string line;
        getline(classes,line,',');
        switch(i){
            case 0;
                
        }
    }
}

void saveRequest(){

}

void processRequest(){

}


