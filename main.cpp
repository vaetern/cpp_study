#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <chrono>


int internal_types() {
    int x = 5;
    double pi = 3.1415;
    bool val = false;
    char symbol = 'Z';
    std::string str = "Hello World!";

    std::cout << str << std::endl;

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << numbers.size() << std::endl;

    std::map<std::string, int> name_to_val;
    name_to_val["on"] = 1;
    name_to_val["tw"] = 2;

    std::cout << name_to_val["tw"] << std::endl;

    return 0;
}

struct Person {
    std::string name;
    std::string surname;
    int age;
};

void how_structs_work() {

    std::vector<Person> adventurers;
    adventurers.push_back({"I", "Bettik", 249});
    adventurers.push_back({"R", "Endimion", 24});

    if (adventurers[0].surname == adventurers[1].surname) {
        std::cout << "adventurers are the same" << std::endl;
    } else {
        std::cout << "adventurers are not the same" << std::endl;
    }

    std::cout << adventurers[0].surname << std::endl;
    std::cout << adventurers[1].surname << std::endl;

}

void iterate_containers() {
    std::string s = "abcde";
    for (char c : s) {
        std::cout << c << ",";
    }
    std::cout << std::endl;

    for (int c : s) {
        std::cout << c << ",";
    }
    std::cout << std::endl;

    std::vector<int> nums = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    sort(begin(nums), end(nums));
    for (int n:nums) {
        std::cout << n << ",";
    }
    std::cout << std::endl;
    int quantity_fives = count(begin(nums), end(nums), 5);

    std::cout << "There are " << quantity_fives << " fives";
    std::cout << std::endl;

    //use 'auto' instead of specifying type
    std::vector<std::string> strs = {"a", "ab", "abc"};
    for (auto n:strs) {
        std::cout << n << ",";
    }
    std::cout << std::endl;
}

void cin_cout() {
    int x, y;
    std::cout << "Enter x, y:";
    std::cin >> x >> y;
    std::cout << "sum: " << x + y;

}

void cond_cycles() {
    int x = 2;
    int y = 9;

    if (x == y) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }

    int sum = 0;
    for (int i = x; i <= y; ++i) {
        sum += i;
    }
    std::cout << "sum:" << sum << std::endl;

    sum = 0;
    int i = x;
    while (i <= y) {
        sum += i;
        i += 1;
    }
    std::cout << "sum:" << sum << std::endl;

}

void iterate_map() {
    std::map<std::string, int> a = {{"a", 1},
                                    {"b", 2}};

    std::string concat;
    int sum;
    for (auto i:a) {
        concat += i.first;
        sum += i.second;
    }

    std::cout << concat << std::endl;
    std::cout << sum;

}

void quadratic_equation(double a, double b, double c) {
    double discriminant = sqrt((b * b - 4 * a * c));
    if (a != 0) {
        std::cout << (-b + discriminant) / (2 * a) << std::endl;
        std::cout << (-b - discriminant) / (2 * a) << std::endl;
    } else {
        std::cout << -c / b << std::endl;
    }
    std::cout << std::endl;
}

void for_i() {
    std::string a = "abcdabcdabcd";

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 'a') {
            std::cout << i << std::endl;
        }
    }
}

void division(int a, int b) {
    if (b == 0) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << a / b << std::endl;
    }
}

void test_division() {

    division(10, 2);
    division(3, 5);
    division(11, 0);

}

double calc_price(double cost, double threshold_1, double threshold_2, double disc_1, double disc_2) {

    if (cost < threshold_1) {
        return cost;
    }

    if (cost >= threshold_1 && cost < threshold_2) {
        return cost * (100 - disc_1) / 100;
    }

    return cost * (100 - disc_2) / 100;
}

void test_calc_price() {

    std::map<double, std::vector<double>> test_map = {
            {100,    std::vector<double>{100, 110, 120, 5, 10}},
            {109.25, std::vector<double>{115, 110, 120, 5, 10}},
            {131.25, std::vector<double>{150, 110, 120, 5, 12.5}},
    };

    for (auto test_case:test_map) {
        std::vector<double> v = test_case.second;

        if (test_case.first == calc_price(v[0], v[1], v[2], v[3], v[4])) {
            std::cout << "passed" << std::endl;
        } else {
            std::cout << "fail" << std::endl;
        }
    }
}

void even(int a, int b) {

    if (a % 2 != 0) {
        a++;
    }

    for (int i = a; i <= b; i = i + 2) {
        std::cout << i << " ";
    }
}

void test_even() {
    even(9, 11);
}

int charpos2(char needle, std::string haystack) {

    bool hit = false;
    int pos = 0;
    for (char c : haystack) {
        if (c == needle) {
            if (hit) {
                return pos;
            } else {
                hit = true;
            }
        }
        pos++;
    }

    if (hit) {
        return -1;
    }

    return -2;

}

void test_charpos2() {

    std::map<int, std::string> test_map = {
            {-1, "comfort"},
            {3,  "coffee"},
            {-2, "car"},
    };

    for (auto test_case:test_map) {
        if (test_case.first == charpos2('f', test_case.second)) {
            std::cout << "passed" << std::endl;
        } else {
            std::cout << "failed" << std::endl;
        }
    }
}

int biggest_common_div(int a, int b) {
    int lower = __min(a, b);
    int common_divisor = 1;
    for (int i = 2; i <= lower; i++) {
        if (a % i == 0 && b % i == 0) {
            common_divisor = i;
        }
    }

    return common_divisor;
}

void test_biggest_common_div() {

    std::map<int, std::vector<int>> test_map = {
            {1,   std::vector<int>{25, 27}},
            {4,   std::vector<int>{12, 16}},
            {13,  std::vector<int>{13, 13}},
            {11,  std::vector<int>{11, 121}},
            {106, std::vector<int>{4558, 212}},
    };

    for (auto test_case:test_map) {
        if (test_case.first == biggest_common_div(test_case.second[0], test_case.second[1])) {
            std::cout << "passed" << std::endl;
        } else {
            std::cout << "failed" << std::endl;
        }
    }
}

std::string dec2bin(int number) {
    std::vector<int> representation;

    while (true) {
        representation.push_back(number % 2);
        number /= 2;
        if (number == 0) break;
    }

    std::reverse(representation.begin(), representation.end());

    std::string ret = "";
    for (auto a:representation) {
        if (a == 1) {
            ret += "1";
        } else {
            ret += "0";
        }
    }

    return ret;
}

void test_dec2bin() {
    std::map<int, std::string> test_map = {
            {1,   "1"},
            {4,   "100"},
            {13,  "1101"},
            {37,  "100101"},
            {133, "10000101"},
    };

    for (auto test_case:test_map) {
        std::string expected = test_case.second;
        std::string actual = dec2bin(test_case.first);
        if (expected == actual) {
            std::cout << "passed" << std::endl;
        } else {
            std::cout << "failed: " << expected << " != " << actual << std::endl;
        }
    }
}

int Factorial(int a) {

    if (a == 0) return 0;
    if (a <= 1) return 1;

    int result = 1;
    for (int i = 2; i <= a; i++) {
        result *= i;
    }

    return result;
}

void test_Factorial() {
    std::map<int, int> test_map = {
            {1,  1},
            {2,  2},
            {3,  6},
            {4,  24},
            {-4, 1},
    };

    for (auto test_case:test_map) {
        int expected = test_case.second;
        int actual = Factorial(test_case.first);
        if (expected == actual) {
            std::cout << "passed: " << expected << " == " << actual << std::endl;
        } else {
            std::cout << "failed: " << expected << " != " << actual << std::endl;
        }
    }
}

bool IsPalindrom(std::string in) {
    std::string copy = in;
    std::reverse(copy.begin(), copy.end());

    return in == copy;
}

void test_IsPalindrom() {
    std::map<std::string, bool> test_map = {
            {"madam",               true},
            {"gentleman",           false},
            {"X",                   true},
            {"poiuytrewqwertyuiop", true},
            {"",                    true},
    };

    for (auto test_case:test_map) {
        bool expected = test_case.second;
        bool actual = IsPalindrom(test_case.first);
        if (expected == actual) {
            std::cout << "passed: " << expected << " == " << actual << std::endl;
        } else {
            std::cout << "failed: " << expected << " != " << actual << std::endl;
        }
    }
}

// ---- week 02 ---

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void test_Swap() {
    int a, b;
    a = 5, b = 10;
    std::cout << "was: " << a << " " << b << std::endl;
    Swap(a, b);
    std::cout << "now: " << a << " " << b << std::endl;
}

//- benchmark
void howToBehchmark() {

    int threshold = 1000000;
    int accumulatedTime = 0;
    for (int i = 0; i < threshold; i++) {
        auto start = std::chrono::steady_clock::now();
        ///---------- bench
        Factorial(10);
        ///--end
        auto finish = std::chrono::steady_clock::now();
        accumulatedTime += std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
    }


    std::cout << threshold << " iterations" << std::endl;
    std::cout << accumulatedTime / threshold << "ns mean" << std::endl;
}


// - const reference &
std::vector<int> getVector() {
    return {1, 2, 3};
}

int countVector(const std::vector<int> &vec) {
    return vec.size();
}

void ConstReference() {
    auto vec = getVector();
    std::cout << countVector(vec) << std::endl;
    std::cout << countVector(getVector()) << std::endl;
    // no go - cannot pass function result as reference
    // but we define argument of function as const & - so it ok

    const std::string s = "Hello";
    std::string t = s;
    t += ", world";
    std::cout << t << std::endl;
}

void UpdateIfGreater(const int &a, int &b) {
    if (a > b) {
        b = a;
    }
}

void benchmark_UpdateIfGreater() {

    int threshold = 1000000;
    int accumulatedTime = 0;
    for (int i = 0; i < threshold; i++) {
        auto start = std::chrono::steady_clock::now();
        ///---------- bench
        int a = 8;
        int b = 9;
        UpdateIfGreater(a, b);
        ///--end
        auto finish = std::chrono::steady_clock::now();
        accumulatedTime += std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
    }


    std::cout << threshold << " iterations" << std::endl;
    std::cout << accumulatedTime / threshold << "ns mean" << std::endl;
}


void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination) {

    for(auto c:source){
        destination.insert(destination.end(), c);
    }
    source.clear();
}

void test_MoveStrings() {

    std::map<int, std::vector<std::string>> destination = {
            {0, {"z0"}},
            {1, {"new"}}
    };

    std::map<int, std::vector<std::string>> source = {
            {0, {"a0","b0","c0",}},
            {1, {"old"}}
    };

    std::map<int, std::vector<std::string>> expected = {
            {0, {"z0","a0","b0","c0",}},
            {1, {"new","old"}}
    };

    for (auto test_case:expected) {
        int index = test_case.first;
        auto expected_result = test_case.second;
        auto source_vector = source[index];
        auto destination_vector = destination[index];
        MoveStrings(source_vector, destination_vector);
        if (destination_vector == expected[index] && source_vector.size() == 0 ) {
            std::cout << "passed: " << expected[index][0] << " == " << destination_vector[0] << std::endl;
        } else {
            std::cout << "failed: size " << source_vector.size() << ", got "<< destination_vector[0] << " expecting "
            << expected[index][0] << std::endl;
        }
    }
}


int main() {
//    int a = internal_types();
//    how_structs_work();
//    iterate_containers();
//    cin_cout();
//    cond_cycles();
//    lexic_less();
/*    quadratic_equation(2, 5, 2);
    quadratic_equation(2, 4, 2);
    quadratic_equation(2, 1, 2);
    quadratic_equation(0, 4, 10);*/
//    iterate_map();
//    for_i();
//    test_division();
//    test_calc_price();
//    test_even();
//    test_charpos2();
//    test_biggest_common_div();
//    test_dec2bin();
//    test_Factorial();
//    test_IsPalindrom();
//    test_Swap();
//    howToBehchmark();
//    ConstReference();
//    benchmark_UpdateIfGreater();
    test_MoveStrings();


    return 0;

}


