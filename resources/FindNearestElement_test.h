#pragma once

#ifndef UNTITLED_FINDNEARESTELEMENT_TEST_H
#define UNTITLED_FINDNEARESTELEMENT_TEST_H

#include <set>
#include <map>
#include "UnitTest.h"
#include "FindNearestElements.h"

using namespace std;

void FindNearestElement_suite1() {
    map<int, pair<set<int>, int> > test_table1 = {
            {1, {{1, 4, 6}, 0}},
            {4, {{1, 4, 6}, 3}},
            {4, {{1, 4, 6}, 5}},
            {6, {{1, 4, 6}, 6}},
            {6, {{1, 4, 6}, 100}},
    };
}

void FindNearestElement_suite2() {
    set<int> empty_set;
    if(FindNearestElement(empty_set, 8) != end(empty_set)){
        AssertEqual(0,1, "empty set case");
    }
}

void FindNearestElement_test(){
    TestRunner tr;

    tr.RunTest(FindNearestElement_suite1, "suite 1");
    tr.RunTest(FindNearestElement_suite2, "suite 2");

}


#endif //UNTITLED_FINDNEARESTELEMENT_TEST_H
