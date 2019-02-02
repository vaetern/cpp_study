#pragma once
#ifndef UNTITLED_FUNCTIONSTEMPLATE_H
#define UNTITLED_FUNCTIONSTEMPLATE_H


#include <utility>
#include <ostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;


template<typename Container>
string Join(const Container &cont, char delimiter) {
    stringstream ss;
    bool is_first = true;
    for (const auto &i: cont) {
        if (!is_first) {
            ss << delimiter;
        }
        is_first = false;
        ss << i;
    }
    return ss.str();
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
    return out << '[' <<Join(v, ',') << ']';
}

template<typename Key, typename Value>
ostream &operator<<(ostream &out, const map<Key, Value> &m) {
    return out << '{' << Join(m, ',') << '}';
}

template<typename First, typename Second>
ostream &operator<<(ostream &out, const pair<First, Second> &arg) {
    return out << '(' <<arg.first << ":" << arg.second << ')';
}


template<typename T>
T Squared(T x) {
    return x * x;
}

template<typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second> &p1, const pair<First, Second> &p2) {
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;

    return make_pair(f, s);
}

template <typename T>
T MaxOf(T arg1, T arg2){
    if(arg1 > arg2){
        return arg1;
    }
    return arg2;
}


#endif //UNTITLED_FUNCTIONSTEMPLATE_H
