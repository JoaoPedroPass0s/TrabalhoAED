

#ifndef TRABALHOAED_REQUEST_H
#define TRABALHOAED_REQUEST_H
#include <string>
#include <vector>

using namespace std;


class Request {
public:
    Request(string uc,string classin,string classout,string studentCode,string requesttype);
    string getUc() const;
    string getClassIn() const;
    string getClassOut() const;
    string getStudentCode() const;
    string getRequestType() const;
private:
    string uc_;
    string classin_=" ";
    string classout_=" ";
    string studentCode_;
    string requesttype_;
};


#endif //TRABALHOAED_REQUEST_H
