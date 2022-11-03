//include  for all headers and cpp files till now

#include "../src/App.cpp"
#include "../src/GestaoHorario.cpp"
#include "../src/HClass.cpp"
#include "../src/main.cpp"
#include "../src/Request.cpp"
#include "../src/Slot.cpp"
#include "../src/Student.cpp"
#include "../src/UCClass.cpp"

 /*
//test the code already written in cpp

using namespace igloo;

//testing HClass.cpp, still has errors and places needed to fill (missing )

Describe(HClassTests){
    It(correct_getClass){
        Assert::That(HClass::getClass(std::string ""), Equals(std::string ""));
    }

    It(correct_getUc){
        Assert::That(HClass::getUc(std::string ""), Equals(std::string ""));
    }

    It(correct_getClassUcHour){
        Assert::That(HClass::getClassUcHour(std::list<Slot>), Equals(std::list<Slot>));
    }
}


Describe(RequestTests){
    It(correct_getUc){
        Assert::That(Request::getUc(std::string ""), Equals(std::string ""));
    }
    It(correct_getClassIn){
        Assert::That(Request::getClassIn(std::string ""), Equals(std::string ""));
    }
    It(correct_getClassOut){
        Assert::That(Request::getClassOut(std::string ""), Equals(std::string ""));
    }
    It(correct_getStudentCode){
        Assert::That(Request::getStudentCode(std::string ""), Equals(std::string ""));
    }
    It(correct_getRequestType){
        Assert::That(Request::getRequestType(std::string ""), Equals(std::string ""));
    }
}


Describe(SlotTests){
    It(correct_getWeekDay){
        Assert::That(Slot::getWeekDay(std::string ""), Equals(std::string ""));
    }
    It(correct_getClassType){
        Assert::That(Slot::getClassType(std::string ""), Equals(std::string ""));
    }
    It(correct_getStartHour){
        Assert::That(Slot::getStartHour(double ""), Equals(double ""));
    }
    It(correct_getEndHour){
        Assert::That(Slot::getEndHour(double ""), Equals(double ""));
    }
}


Describe(StudentTests){
    It(correct_getName){
        Assert::That(Student::getName(std::string ""), Equals(std::string ""));
    }
    It(correct_getId){
        Assert::That(Student::getId(std::string ""), Equals(std::string ""));
    }
    It(correct_getClasses){
        Assert::That(Student::getClasses(std::vector<UCClass>), Equals(std::vector<UCClass));
    }
}

Describe(UCClassTests){
    It(correct_getUc){
        Assert::That(UCClass::getUc(std::string ""), Equals(std::string ""));
    }
    It(correct_getClass){
        Assert::That(UCClass::getClass(std::string ""), Equals(std::string ""));
    }
}
*/