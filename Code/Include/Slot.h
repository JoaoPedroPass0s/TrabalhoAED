//
// Created by pedropassos on 29-10-2022.
//

#ifndef TRABALHOAED_SLOT_H
#define TRABALHOAED_SLOT_H

#include <string>
using namespace std;


class Slot {
public:
    Slot(string weekDay, double startHour, double endHour, string classType);
    string getWeekDay() const;
    string getClassType() const;
    double getStartHour() const;
    double getEndHour() const;


private:
    string weekDay_;
    double startHour_;
    double endHour_;
    string classType_;
};


#endif //TRABALHOAED_SLOT_H
