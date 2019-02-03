#include "FindNearestElements.h"
#include <algorithm>
#include <vector>

using namespace std;


set<int>::const_iterator FindNearestElement(const set<int> &numbers, int border) {
    pair<set<int>::const_iterator,set<int>::const_iterator> offsets;
    offsets = numbers.equal_range(border);


    return offsets.second;

};