#include "StringSplit.h"
#include "UnitTest.h"

void StringSplit_TestSuite() {
    //object , expected
    map<pair<string, char>, vector<string>> test_table = {
            {{"a b c d e", ' '}, {"a", "b", "c", "d", "e"}},
            {{"a,b,c,d,e", ','}, {"a", "b", "c", "d", "e"}},
            {{ "abcde", ' ' }, { "abcde" }},
            {{ "abc de", ' ' }, { "abc", "de" }},
            {{ "a,b", ',' }, { "a","b" }},
            {{ "", ',' }, { ""}},
    };

    auto split = StringSplit();

    int test_number = 0;
    for (auto const&[object, expected]:test_table) {
        auto actual = split.Split(object.first, object.second);
        AssertEqual(expected, actual, "#" + to_string(test_number));
        test_number++;
    }
}


void StringSplit_test(){
    TestRunner tr;
    tr.RunTest(StringSplit_TestSuite, "StringSplit_test");
}

