#pragma once

#ifndef UNTITLED_REMOVEDUPLICATES_TEST_H
#define UNTITLED_REMOVEDUPLICATES_TEST_H

#include "UnitTest.h"
#include "RemoveDuplicates.h"


void TestSuite_RemoveDuplicates(){

    map<vector<int>, vector<int>> test_table_int = {
            {{1,2,3,4,5,2,3,4,5,6},{1,2,3,4,5,6}},
            {{0,0,0},{0}},
            {{},{}},
    };

    map<vector<string>, vector<string>> test_table_string = {
            {{"one","two","one","two"},{"one","two",}},
            {{""},{""}},
            {{},{}},
    };

    for(const auto&[obj, expected]:test_table_int){
        vector<int> test_object_int = obj;
        AssertEqual(expected, RemoveDuplicates(test_object_int), " int ");
    }

    for(const auto&[obj, expected]:test_table_string){
        vector<string> test_object_str = obj;
        AssertEqual(expected, RemoveDuplicates(test_object_str), " string ");
    }

}


void RunTests_RemoveDuplicates(){
    TestRunner tr;

    tr.RunTest(TestSuite_RemoveDuplicates, "RemoveDuplicates");

}



#endif //UNTITLED_REMOVEDUPLICATES_TEST_H
