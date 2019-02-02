#ifndef UNTITLED_BENCHMARK_H
#define UNTITLED_BENCHMARK_H
#pragma once

#include <chrono>
#include <string>
#include <iostream>

using namespace std;


class Benchmark {
public:


    template<typename Func>
    void DoBenchmark(Func function, const uint32_t &num_iterations, const string &tag) {
        uint32_t threshold = num_iterations;
        int accumulatedTime = 0;
        for (int i = 0; i < threshold; i++) {
            auto start = std::chrono::steady_clock::now();
            ///---------- bench
            function();
            ///--end
            auto finish = std::chrono::steady_clock::now();
            accumulatedTime += std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();
        }


        std::cerr << "Benchmark '" << tag << "'" << std::endl;
        std::cerr << "----------:" << std::endl;
        std::cerr << threshold << " iterations" << std::endl;
        std::cerr << accumulatedTime / threshold << "ms mean" << std::endl;
        std::cerr << "----------------------:" << std::endl;
    }

private:

};


#endif //UNTITLED_BENCHMARK_H
