#include "UnitTest.h"
#include <sstream>
using namespace std;


TestRunner::TestRunner() {
    cerr << "TestRunner init..." << endl;
    cerr << "----------------" << endl;
}

TestRunner::~TestRunner() {
    if (fail_count > 0) {
        cerr << fail_count << " tests failed. Terminate";
        exit(1);
    } else {
        cerr << "----------------" << endl;
        cerr << "All tests passed";
    }
}


