#include "UsingIterators_test.h"
#include "UsingIterators.h"
#include "UnitTest.h"
#include "UnitTest.h"



void TestSuite(){
    //expected , object
    map<vector<int>, vector<int>> test_table = {
            {{0,1,2,3}, {0,1,2,3,-4,5,6}},
            {{0}, {0,-1,2,3,-4,5,6}},
            {{5,6}, {5,6,-1,7}},
            {{},{-4,-5,2}},
    };

    int test_number = 0;
    for(auto const& [expected , test_case]:test_table){
        auto actual = PrintVectorPart(test_case);
        AssertEqual(expected, actual, "#"+ to_string(test_number));
        test_number++;
    }
}

void UsingIterators_test(){
    TestRunner tr;
    tr.RunTest(TestSuite, "TestSuite");

}