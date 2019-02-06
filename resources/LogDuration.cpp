#include "LogDuration.h"
#include <chrono>
#include <iostream>

using namespace std;


LogDuration::LogDuration(const string& message) : start(steady_clock::now()), message(message) {
}

LogDuration::~LogDuration() {
    auto finish = steady_clock::now();
    auto duration = finish - start;
    cerr << message <<": "<<duration_cast<milliseconds>(duration).count() << "ms" << endl;
}
