#ifndef UNTITLED_LOGDURATION_H
#define UNTITLED_LOGDURATION_H
#pragma once

#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

class LogDuration {
public:

    explicit LogDuration(const string& message = "");

    ~LogDuration();

private:
    string message;
    steady_clock::time_point start;
};


#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
  LogDuration UNIQ_ID(__LINE__){message};

#endif //UNTITLED_LOGDURATION_H
