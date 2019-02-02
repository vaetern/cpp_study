#include "UsingIterators.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Lang {
    string Name;
    uint16_t age;
};

void UseIterator() {

    vector<Lang> langs = {
            {"Python", 26},
            {"C++",    34},
            {"C",      45},
    };

    for (auto iterator = begin(langs);
         iterator != end(langs);
         ++iterator
            ) {
        cout << iterator->Name << endl;
        //or
        cout << (*iterator).Name << endl;

    }
}

vector<int> PrintVectorPart(const vector<int> &numbers) {
    auto offset = find_if(begin(numbers), end(numbers),
                          [](const int i) { return i < 0; }
    );

    auto x = *offset;

    return GetSubcontainerByIterators(begin(numbers), offset);
}