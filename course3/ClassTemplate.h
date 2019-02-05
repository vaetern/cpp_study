#ifndef UNTITLED_CLASSTEMPLATE_H
#define UNTITLED_CLASSTEMPLATE_H
#pragma once


template<typename T>
struct PairSame {
    PairSame(T f, T s) : first(f), second(s) {}

    T first;
    T second;

    T Sum() const {
        return first + second;
    }

    T Mul() const {
        return first * second;
    }
};


void HowTo() {
    PairSame<double> a(.01, 50);

    a.Sum();

    a.Mul();

}


#endif //UNTITLED_CLASSTEMPLATE_H
