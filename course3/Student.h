#pragma once

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>
#include <map>
#include <cmath>

using namespace std;

struct Student {
    string first_name;
    string last_name;
    map<string, double> marks;
    double rating;

    bool operator < (const Student& other) const {
        return GetName() < other.GetName();
    }

    bool Less(const Student& other) const {
        return rating > other.rating;
    }

    string GetName() const {
        return first_name + " " + last_name;
    }
};

bool Compare(const Student& first, const Student& second) {
    return first.rating - second.rating > 0;
}

#endif //UNTITLED_STUDENT_H
