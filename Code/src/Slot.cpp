//
// Created by pedropassos on 29-10-2022.
//

#include "../Include/Slot.h"
#include <string>

Slot::Slot(string weekDay, double startHour, double endHour, string classType: weekDay_(weekDay), startHour_(startHour), endHour_(endHour), classType_(classType) {}

string Slot::getWeekDay() const {return weekDay_; }
string Slot::getClassType() const {return classType_; }
double Slot::getStartHour() const {return startHour_; }
double Slot::getEndHour() const {return endHour_; }
