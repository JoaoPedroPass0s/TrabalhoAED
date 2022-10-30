//
// Created by pedropassos on 29-10-2022.
//

#ifndef TRABALHOAED_UCCLASS_H
#define TRABALHOAED_UCCLASS_H

#include <string>

class UCClass {
public:
    UCClass(string uc, string classes);
    string getUc() const;
    string getClass() const;

private:
    string uc_;
    string class_;
};


#endif //TRABALHOAED_UCCLASS_H
