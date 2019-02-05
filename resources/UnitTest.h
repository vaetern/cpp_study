#pragma once

#ifndef UNTITLED_UNITTEST_H
#define UNTITLED_UNITTEST_H

#include "PrintContainers.h"
#include <exception>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

#define ASSERT_EQUAL(x, y){             \
    ostringstream os;                   \
    os << __FILE__ <<":"<<__LINE__;     \
    AssertEqual(x ,y, os.str());        \
}

#define RUN_TEST(tr, func) \
  tr.RunTest(func, #func)

template<class T, class U>
void AssertEqual(const T &expected, const U &actual, const string &hint) {
    if (expected != actual) {
        ostringstream os;
        os << "   [X]AssertEqual: (" << expected << " == " << actual << ") , in '" << hint << "'";
        throw runtime_error(os.str());
    }
}

template<class T, class U>
void AssertNotEqual(const T &expected, const U &actual, const string &hint) {
    if (expected == actual) {
        ostringstream os;
        os << "   [X]AssertNotEqual: (" << expected << " != " << actual << ") , in '" << hint << "'";
        throw runtime_error(os.str());
    }
}

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string &test_name);

    TestRunner();

    ~TestRunner();

private:
    int fail_count = 0;
};

template<class TestFunc>
void TestRunner::RunTest(TestFunc func, const string &test_name) {
    try {
        func();
        cerr << "'" << test_name << "'" << " OK" << endl;
    } catch (runtime_error &error) {
        cerr << "'" << test_name << "'" << " failed: " << endl
             << error.what() << endl;
        fail_count++;
    }

}


#endif //UNTITLED_UNITTEST_H
