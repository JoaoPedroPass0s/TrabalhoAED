//
// Created by pedropassos on 29-10-2022.
//

#ifndef TRABALHOAED_SLOT_H
#define TRABALHOAED_SLOT_H

#include <string>
using namespace std;


class Slot {
public:
    Slot(string weekDay, float startHour, float endHour, string classType);
    string getWeekDay() const;
    string getClassType() const;
    float getStartHour() const;
    float getDuration() const;
    float getEndHour() const;


private:
    string weekDay_;
    float startHour_;
    float duration_;
    float endHour_;
    string classType_;
};


#endif //TRABALHOAED_SLOT_H
