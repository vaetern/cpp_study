#ifndef UNTITLED_REVERSIBLESTRING_H
#define UNTITLED_REVERSIBLESTRING_H

#include<string>
#include<algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString(){};
    ReversibleString(const string &s) {
        str = s;
    }

    const string &ToString() const {
        return str;
    }

    void Reverse(){
        reverse(str.begin(), str.end());
    }

    string str;

};


#endif //UNTITLED_REVERSIBLESTRING_H
