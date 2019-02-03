#ifndef UNTITLED_REMOVEDUPLICATES_H
#define UNTITLED_REMOVEDUPLICATES_H
#pragma once

#include <algorithm>
#include <vector>
#include <set>

using namespace std;

template <typename T>
vector<T> RemoveDuplicates(vector<T>& elements){

    vector<T> vec;

    set<T> s;
    unsigned size = elements.size();
    for( unsigned i = 0; i < size; ++i ) s.insert( elements[i] );
    vec.assign( s.begin(), s.end() );

    return vec;


}

#endif //UNTITLED_REMOVEDUPLICATES_H
