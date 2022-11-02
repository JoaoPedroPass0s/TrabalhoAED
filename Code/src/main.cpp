#include <iostream>
#include "../Include/GestaoHorario.h"
#include "../Include/App.h"
#include <fstream>
#include <sstream>

int main() {
    App a;
    a.start();
    return 0;

    fstream fs;
    fs.open("students_classes.csv", ios::in);
    string line;
    while(getline(fs, line)) {
        stringstream str(line);
        string word;
        while(getline(str, word, ',')) {

        }
    }

}