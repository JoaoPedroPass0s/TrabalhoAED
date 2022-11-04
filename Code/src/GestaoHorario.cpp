
#include "../Include/UCClass.h"
#include "../Include/GestaoHorario.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>

void GestaoHorario::readFileStudents(){
    std::ifstream students;
    students.open("/home/pedropassos/TrabalhoAED/Code/schedule/students_classes.csv");
    string id="";
    string name="";
    string line;
    vector<UCClass> classesStu;
    getline(students,line);
    while(getline(students,line)){
        stringstream inputString(line);
        string ucCode;
        string classCode;
        string nameStu;
        string idStu;
        getline(inputString,idStu,',');
        getline(inputString,nameStu,',');
        getline(inputString,ucCode,',');
        getline(inputString,classCode,'\r');
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
        getline(inputString,classType,'\r');
        for(unsigned i = 0; i < horarioC_.size(); i++){
            if(horarioC_[i].getUc()==ucCode_ && horarioC_[i].getClass()==classCode_){
                b=false;
                Slot s(weekDay,start,endHour,classType);
                horarioC_[i].InsertClassUCHour(s);
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

void GestaoHorario::readFileRequests(){
    std::ifstream requests;
    requests.open("/home/pedropassos/TrabalhoAED/Code/schedule/Declined_Requests.csv");
    string line;
    getline(requests,line);
    while(getline(requests,line)){
        stringstream inputString(line);
        string uc;
        string classIn;
        string classOut;
        string studentCode;
        string requestType;
        getline(inputString,uc,',');
        getline(inputString,classIn,',');
        getline(inputString,classOut,',');
        getline(inputString,studentCode,',');
        getline(inputString,requestType,',');
        Request r(uc,classIn,classOut,studentCode,requestType);
        requests_.push_back(r);
    }
}

void GestaoHorario::saveRequest(Request request){
    requests_.push_back(request);
}

void GestaoHorario::processRequest(){
    ofstream declinedRequests;
    declinedRequests.open("/home/pedropassos/TrabalhoAED/Code/schedule/Declined_Requests.csv");
    declinedRequests << "Uc" << "," << "ClassIn" << "," << "ClassOut"
                     << "," << "StudentCode" << "," << "RequestType" << endl;
    for(Request r:requests_){
        bool valid=false;
        if(r.getRequestType()=="Remove"){
            for(int i=0;i<students_.size();i++){
                if(students_[i].getId()==r.getStudentCode()){
                    valid=students_[i].RemoveClass(r);
                }
            }
        }else if(r.getRequestType()=="Add"){
            bool b=true;
            for(int i=0;i<students_.size();i++){
                if(students_[i].getId()==r.getStudentCode()){
                    for(UCClass c1:students_[i].getClasses()){
                        UCClass c2(r.getUc(),r.getClassOut());
                        if(!canClassesBeTogether(c1,c2)){
                            b=false;
                        }
                    }
                    if(b){
                        valid=true;
                        students_[i].addClass(r.getUc(),r.getClassOut());
                    }
                }
            }
        }else if(r.getRequestType()=="Change"){
            bool b=true;

            for(int i=0;i<students_.size();i++){
                if(students_[i].getId()==r.getStudentCode()){
                    students_[i].RemoveClass(r);
                    for(UCClass c1:students_[i].getClasses()){
                        UCClass c2(r.getUc(),r.getClassOut());
                        if(!canClassesBeTogether(c1,c2)){
                            b=false;
                        }
                    }
                    if(b){
                        valid=true;
                        students_[i].addClass(r.getUc(),r.getClassOut());
                    }else{
                        students_[i].addClass(r.getUc(),r.getClassIn());
                    }
                }
            }
        }
        if(!valid){
            declinedRequests << r.getUc() << "," << r.getClassIn() << "," << r.getClassOut()
            << "," << r.getStudentCode() << "," << r.getRequestType() << endl;
        }
    }
    ofstream myFile;
    myFile.open("/home/pedropassos/TrabalhoAED/Code/schedule/Modified_Students.csv");
    for(Student s:students_){
        for(UCClass u:s.getClasses()){
            myFile << s.getId() << "," << s.getName() << "," << u.getUc() << "," << u.getClass() << endl;
        }
    }
}

void GestaoHorario::listAllStudents(){
    string wait;
    for(Student s:students_){
        cout << "Name: " << s.getName() << " Id: " << s.getId()<< endl;
    }
    cout << "Number of Students: " << students_.size() << endl;
    cout << "Press Enter to return..." << endl;
    cin.ignore();
    cout << "Returning..." << endl;
}

void GestaoHorario::addStudentsToClasses() {
    for(Student s:students_){
        for(UCClass u:s.getClasses()){
            for(int i=0;i<horarioC_.size();i++){
                if(horarioC_[i].getUc()==u.getUc() and horarioC_[i].getClass()==u.getClass()){
                    horarioC_[i].InsertStudent(s);
                }
            }
        }
    }
}

bool GestaoHorario::canClassesBeTogether(UCClass c1,UCClass c2){
    HClass h1;
    HClass h2;
    for(HClass h:horarioC_){
        if(h.getUc()==c1.getUc() && h.getClass()==c1.getClass()){
            h1=h;
        }
        if(h.getUc()==c2.getUc() && h.getClass()==c2.getClass()){
            h2=h;
        }
    }
    for(Slot s1:h1.getClassUcHour()){
        for(Slot s2:h2.getClassUcHour()){
            if((h2.getStudentList().size()<26) and (!(s1.getClassType()=="T" or s2.getClassType()=="T")) and (s1.getWeekDay()==s2.getWeekDay()) and ((s1.getStartHour()==s2.getStartHour() and s1.getEndHour()==s2.getEndHour()) or (s1.getStartHour()>s2.getStartHour() and s1.getStartHour()<s2.getEndHour()) or (s1.getEndHour()>s2.getStartHour() and s1.getEndHour()<s2.getEndHour()))){
                return false;
            }
        }
    }
    return true;
}
