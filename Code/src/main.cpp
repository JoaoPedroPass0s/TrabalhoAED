#include <iostream>
#include "../Include/GestaoHorario.h"

int main() {
    std::cout << "Hello, World!123456" << std::endl;
    GestaoHorario horario;
    horario.readFileStudents();
    horario.saveRequest();
    horario.processRequest();
    return 0;
}