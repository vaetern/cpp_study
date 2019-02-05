#pragma once

#ifndef UNTITLED_INHERITANCEUSAGE_H
#define UNTITLED_INHERITANCEUSAGE_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Parent {
public:

    double a;
    double b;
    const double c;
    const std::string name;


    Parent(const double a_, const double b_, const double c_, const std::string name_) : c(c_), name(name_) {
        std::cout << "Parent [o]" << std::endl;
        a = a_ * 1.25;
        b = b_ * 1.3334;

        density = a * b * c / 10.75;
    }

    int GetDensity() const {
        return density;
    }

    const std::string GetName() const {
        return name;
    }

    virtual int GetWeight() const { return density * a * b * c; }

    ~Parent() {
        std::cout << "Parent [X]" << std::endl;
    }

protected:
    double density;

private:

};

class Child : public Parent {
public:
    Child(const double a_, const double b_, const double c_, const std::string name_) : Parent(a_, b_, c_, name_) {
        std::cout << "Child [o]" << std::endl;
        density = density / 1.22;
    }

    int GetWeight() const {
        return density * a * b * c;
    }

    ~Child() {
        std::cout << "Child [X]" << std::endl;
    }
};


//////////////////////////

void PrintStats(const Parent &obj) {
    cout << obj.GetName() << " density: " << obj.GetDensity() << endl;
    cout << obj.GetName() << " weight: " << obj.GetWeight() << endl;
}

void InheritanceUsage() {
    vector<shared_ptr<Parent>> v = {
            make_shared<Parent>(0.99, 8.22, 17, " Parent # 1"),
            make_shared<Parent>(1.99, 8.22, 17, " Parent # 2"),
            make_shared<Child>(0.99, 8.22, 17, " Child # 2"),
            make_shared<Child>(1.99, 8.22, 17, " Child # 2"),
    };

    for (auto obj:v) {
        PrintStats(*obj);
    }
}


#endif //UNTITLED_INHERITANCEUSAGE_H
