

#ifndef TRABALHOAED_HCLASS_H
#define TRABALHOAED_HCLASS_H

#include <list>
#include "../Include/Slot.h"
using namespace std;


class HClass {
public:
    HClass(string uc, string classes, list<Slot> classUcHour);
    string getUc() const;
    string getClass() const;
    list<Slot> getClassUcHour() const;

private:
    list<Slot> classUcHour_;
    string uc_;
    string class_;
};


#endif //TRABALHOAED_HCLASS_H
