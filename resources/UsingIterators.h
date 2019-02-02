#pragma once

#include <iostream>
#include <vector>

#ifndef UNTITLED_USINGITERATORS_H
#define UNTITLED_USINGITERATORS_H

using namespace std;

void UseIterator();

vector<int> PrintVectorPart(const vector<int>& numbers);

template<typename Iter>
void PrintContainerByIterators(Iter range_begin, Iter range_end) {
    for (auto i = range_begin; i != range_end; ++i) {
        std::cout << *i << " ";
    }

}

template<typename Iter>
vector<int> GetSubcontainerByIterators(Iter range_begin, Iter range_end) {
    vector<int> v;
    for (auto i = range_begin; i != range_end; ++i) {
        v.push_back(*i);
    }
return v;
}

#endif //UNTITLED_USINGITERATORS_H
