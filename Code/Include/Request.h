

#ifndef TRABALHOAED_REQUEST_H
#define TRABALHOAED_REQUEST_H
#include <string>
using namespace std;


class Request {
public:
    Request(string uc,string classe,string studentCode);
    string getUc() const;
    string getClass() const;
    string getStudentCode() const;
private:
    string uc_;
    string class_;
    string studentCode_;
};


#endif //TRABALHOAED_REQUEST_H
