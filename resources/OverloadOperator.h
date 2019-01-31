#ifndef UNTITLED_OVERLOADOPERATOR_H
#define UNTITLED_OVERLOADOPERATOR_H

#include <ostream>
#include <iomanip>

using namespace std;

struct Interval {
    int hours;
    int minutes;
    int seconds;
};

ostream &operator<<(ostream &stream, const Interval &interval) {
    stream << setfill('0');
    stream << setw(2) << interval.hours << ":"
           << setw(2) << interval.minutes << ":"
           << setw(2) << interval.seconds;

    return stream;
}

Interval operator+(const Interval &left, const Interval &right) {
    int sec_to_min = (left.seconds + right.seconds) / 60;
    int min_to_hours = (left.minutes + right.minutes) / 60;

    int new_hours = left.hours + right.hours + min_to_hours;
    int new_minutes = (left.minutes + right.minutes) % 60 + sec_to_min;
    int new_seconds = (left.seconds + right.seconds) % 60;

    Interval new_interval = Interval{new_hours, new_minutes, new_seconds};

    return new_interval;
}

bool operator<(const Interval &left, const Interval &right){
    return left.hours*3600 + left.minutes*60 + left.seconds <=
           right.hours*3600 + right.minutes*60 + right.seconds;
}

istream &operator>>(istream &stream, Interval &interval) {
    stream >> interval.hours;
    stream.ignore(1);
    stream >> interval.minutes;
    stream.ignore(1);
    stream >> interval.seconds;
    stream.ignore(1);

    return stream;
}


#endif //UNTITLED_OVERLOADOPERATOR_H
