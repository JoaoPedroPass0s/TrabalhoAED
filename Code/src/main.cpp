#include <iostream>
#include "../Include/GestaoHorario.h"
#include "../Include/App.h"
#include "C:\Users\User\Desktop\TrabalhoAED\Code\Include\Student.h"
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
using namespace std;

struct StudentNode {
    StudentNode(int i, Student student) {
    }
    int id;
    Student s;
    StudentNode* left;
    StudentNode* right;
};

StudentNode* GetNewNode(int id, Student student) {
    StudentNode* newNode = new StudentNode(id, student);
    newNode->left = newNode->right = nullptr;
    return newNode;
}

StudentNode* Insert (StudentNode* root, int id, Student student) {
    if(root == nullptr) { // empty tree
        root = GetNewNode(id, student);
    }
        // if data to be inserted is lesser, insert in left subtree.
    else if(id <= root->id) {
        root->left = Insert(root->left, id, student);
    }
        // else, insert in right subtree.
    else {
        root->right = Insert(root->right, id, student);
    }
    return root;
}

int main() {
    App a;
    a.start();

    fstream fs;
    fs.open("students_classes.csv", ios::in);
    string line;
    while(getline(fs, line)) {
        stringstream str(line);
        string word;
        vector<string> lista;
        while(getline(str, word, ',')) {
            lista.push_back(word);
        }
        vector<UCClass> classes;
        UCClass ucclass = *new UCClass(lista[2], lista[3]);
        classes.push_back(ucclass);
        Student s = *new Student(stoi(lista[0]), lista[1], classes);
        Insert(new StudentNode(stoi(lista[0]), s), stoi(lista[0]), s);
    }
}