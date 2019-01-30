#ifndef UNTITLED_LIBRARY_1_H
#define UNTITLED_LIBRARY_1_H

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

struct PersonStruct {
    std::string name;
    std::string surname;
    int age;
};

void how_structs_work() {

    std::vector<PersonStruct> adventurers;
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
    long int quantity_fives = count(begin(nums), end(nums), 5);

    std::cout << "There are " << quantity_fives << " fives";
    std::cout << std::endl;

    //use 'auto' instead of specifying type
    std::vector<std::string> strs = {"a", "ab", "abc"};
    for (const auto &n:strs) {
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
    int sum = 0;
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

    std::string ret;
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

bool IsPalindrom(const std::string &in) {
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

void MoveStrings(std::vector<std::string> &source, std::vector<std::string> &destination) {

    for (const auto &c:source) {
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
            {0, {"a0", "b0", "c0",}},
            {1, {"old"}}
    };

    std::map<int, std::vector<std::string>> expected = {
            {0, {"z0",  "a0", "b0", "c0",}},
            {1, {"new", "old"}}
    };

    for (auto test_case:expected) {
        int index = test_case.first;
        auto expected_result = test_case.second;
        auto source_vector = source[index];
        auto destination_vector = destination[index];
        MoveStrings(source_vector, destination_vector);
        if (destination_vector == expected[index] && source_vector.empty()) {
            std::cout << "passed: " << expected[index][0] << " == " << destination_vector[0] << std::endl;
        } else {
            std::cout << "failed: size " << source_vector.size() << ", got " << destination_vector[0] << " expecting "
                      << expected[index][0] << std::endl;
        }
    }
}

void Reverse(std::vector<int> &a) {
    std::vector<int> b;

    for (const auto &el: a) {
        b.insert(b.begin(), el);
    }

    a = b;
}

void test_Reverse() {
    std::map<std::vector<int>, std::vector<int>> test_map = {
            {{1, 2, 3},       {3, 2, 1}},
            {{1, 0, 0, 1, 0}, {0, 1, 0, 0, 1}},
    };

    for (const auto&[key, value]: test_map) {
        std::vector<int> expected = value;
        std::vector<int> actual = key;
        Reverse(actual);
        if (expected == actual) {
            std::cout << "passed:" << std::endl;
        } else {
            std::cout << "failed:" << std::endl;
        }
    }
}

void benchmark_Reverse() {

    int threshold = 1000;
    int accumulatedTime = 0;
    std::vector<int> initial_a(1000, 9);
    for (int i = 0; i < threshold; i++) {
        auto start = std::chrono::steady_clock::now();
        ///---------- bench
        std::vector<int> a = initial_a;
        Reverse(a);
        ///--end
        auto finish = std::chrono::steady_clock::now();
        accumulatedTime += std::chrono::duration_cast<std::chrono::microseconds>(finish - start).count();
    }


    std::cout << threshold << " iterations" << std::endl;
    std::cout << accumulatedTime / threshold << " micros mean" << std::endl;
}

// -- more about vectora

void vector_for_reference() {
    std::vector<std::string> v(10, "a");
    for (std::string &s:v) {
        s = "u";
    }

    std::cout << v[0];
}

void more_vector_functions() {
    vector<int> v(10, 1);
    cout << v.size() << endl;

    v.clear();
    cout << v.size() << endl;

    v.assign(5, 0);
    cout << v.size() << endl;

    v.push_back(0);
    cout << v.size() << endl;

    v.resize(1);
    cout << v.size() << endl;
}

vector<int> AboveMeanTemperature(const vector<int> temperatures) {

    int sum = 0;
    for (auto t:temperatures) {
        sum += t;
    }
    int mean = sum / temperatures.size();

    vector<int> above_average;

    for (auto t:temperatures) {
        if (t > mean) {
            above_average.push_back(t);
        }
    }
    return above_average;
}

void PrintVectorInt(vector<int> v) {
    for (auto i:v) {
        cout << i << ", ";
    }
    cout << endl;
}

void PrintVectorString(vector<string> v) {
    for (auto i:v) {
        cout << i << ", ";
    }
    cout << endl;
}

void test_AboveMeanTemperature() {
    auto res = AboveMeanTemperature({10, 5, 6, 7, 8, 3, 2, 1, 6, 5, 7, 8, 9, 0, 7, 6, 5, -6});

    PrintVectorInt(res);
}

struct WQueue {
    map<int, int> queue;
    int pointer;

    WQueue() : pointer(0) {}

    void addToQueue(int count) {
        for (int i = 0; i < count; ++i) {
            queue[pointer + i] = 0;
        }
        pointer += count;
    }

    void removeFromQueue(int count) {
        count *= -1;
        for (int i = pointer; i > pointer - count; --i) {
            queue.erase(pointer - i);
        }
        pointer -= count;
    }

    void setWorried(int offset) {
        queue[offset - 1] = 1;
    }

    int howManyWorried() {
        int worried_count = 0;
        for (auto q:this->queue) {
            if (q.second == 1) {
                worried_count++;
            }
        }
        return worried_count;
    }

    void print() {
        for (auto q:this->queue) {
            cout << q.second << " ";
        }
        cout << endl;
    }

};

void WorryQueue() {

    WQueue worry_queue;

    string command_word;
    int command_digit;
    while (true) {
        cout << ":";
        cin >> command_word >> command_digit;
        if (command_word == "worry") {
            worry_queue.setWorried(command_digit);
            worry_queue.print();

            command_word = "";
            command_digit = 0;
            continue;
        }

        if (command_word == "come") {
            if (command_digit > 0) {
                worry_queue.addToQueue(command_digit);
            } else {
                worry_queue.removeFromQueue(command_digit);
            }
            worry_queue.print();

            command_word = "";
            command_digit = 0;
            continue;
        }

        if (command_word == "worry_count") {
            int count_worried = worry_queue.howManyWorried();
            cout << count_worried;

            command_word = "";
            command_digit = 0;
            continue;
        }

        if (command_word == "exit") {
            break;
        } else {
            continue;
        }
    }

}

map<char, int> WordMap(string &word) {
    map<char, int> word_map;

    for (const char &ch:word) {
        word_map[ch]++;
    }
    return word_map;
}

bool IsAnagram(string s1, string s2) {
    return WordMap(s1) == WordMap(s2);
}

void test_IsAnagram() {

    map<map<string, string>, bool> test_map = {
            {{{"anna",      "nana"}},     true},
            {{{"anapurna",  "nanapura"}}, true},
            {{{"anapurnad", "nanapuda"}}, false},
    };

    for (const auto&[pair, expected]: test_map) {
        for (const auto&[w1, w2]:pair) {
            if (IsAnagram(w1, w2) == expected) {
                cout << "passed" << endl;
            } else {
                cout << "failed: " << w1 << " " << w2 << endl;
            }
        }
    }
}


void PrintBuses(const map<int, vector<string>> &buses) {
    for (const auto&[bus, stops]: buses) {
        cout << "#" << bus << ": ";
        for (auto &s: stops) {
            cout << s << ", ";
        }
        cout << endl;
    }
}

/*
 * NEW_BUS 30 5 14Line 11Line 7Line Dzerelo Park
 * NEW_BUS 12 5 14Line 11Line 7Line Park Plosha
 * NEW_BUS 719 5 7Line 1Line Horodskaya Ashan Nivky
 * BUSES_FOR_STOP 14Line
 * BUSES_FOR_STOP 7Line
 * STOPS_FOR_BUS 12
 * */
void BusStops() {

    map<int, vector<string>> buses;

    string command;
    while (true) {
        cin >> command;
        if (command == "NEW_BUS") {
            string value;
            int bus, stops_count = 0;
            cin >> bus;
            buses[bus] = {};
            cin >> stops_count;
            for (int i = 0; i < stops_count; i++) {
                cin >> value;
                buses[bus].push_back(value);
            }

            PrintBuses(buses);
            command = "";
            continue;
        }

        if (command == "BUSES_FOR_STOP") {
            string value;
            cin >> value;
            for (const auto&[bus, stops]: buses) {
                if (std::find(stops.begin(), stops.end(), value) != stops.end()) {
                    cout << bus << ", ";
                }
                cout << endl;
            }
            cout << endl;
            command = "";
            continue;
        }

        if (command == "STOPS_FOR_BUS") {
            int value;
            cin >> value;
            for (const auto &stop_given_bus: buses[value]) {
                cout << "(" << stop_given_bus << ") ";
                for (const auto&[bus_inner, stops_inner]: buses) {
                    if (std::find(stops_inner.begin(), stops_inner.end(), stop_given_bus) != stops_inner.end()) {
                        cout << "#" << bus_inner << ", ";
                    }
                }
                cout << endl;
            }
            cout << endl;
            command = "";
            continue;
        }

        if (command == "exit") {
            break;
        } else {
            command = "";
            continue;
        }
    }


}

void PrintSet(const set<string> &print_set) {

    for (const auto &p: print_set) {
        cout << p << ",";
    }
    cout << endl;

}

// -- sets
void SetsUsage() {
    set<string> famous_person;

    famous_person.insert("Jon Bonjovi");
    famous_person.insert("Bern Stroustrup");
    famous_person.insert("Yuri Gagarin");
    famous_person.insert("Me");
    famous_person.erase("Me");
    PrintSet(famous_person);

    cout << famous_person.count("Yuri Gagarin") << endl;

    vector<string> v = {"a", "b", "c", "a", "Q", "F"};
    set<string> s(v.begin(), v.end());

    PrintSet(s);

}

//10 wheels modern everyday albedo wheels modern everyday albedo omen sign
void CountUniqueStrings() {

    int command;
    set<string> unique_words;
    cin >> command;
    string in;
    for (int i = 0; i < command; ++i) {
        cin >> in;
        unique_words.insert(in);
    }

    cout << unique_words.size();
    cout << endl;

}


struct Content {
    map<int, string> content;
    int pointer;

    Content() : pointer(0) {}

    void add(const string &s) {
        if (indexOf(s) == -1) {
            content[pointer + 1] = s;
            pointer++;
        }
    }

    string getByIndex(int index) {
        return content[index];
    }

    int indexOf(const string &s) {
        for (const auto&[k, v]:content) {
            if (v == s) {
                return k;
            }
        }
        return -1;
    }

};

void PrintSynonyms(Content &content, const set<vector<int>> &many_to_many) {
    for (const auto &entry: many_to_many) {
        string entry1, entry2;
        entry1 = content.getByIndex(entry[0]);
        entry2 = content.getByIndex(entry[1]);
        cout << entry1 << " = " << entry2 << endl;
    }
}

/*
ADD agility foxiness
ADD leannes agility
ADD dexterity agility
ADD evil morbid
ADD vile evil
CHECK agility
CHECK vile
CHECK agility dexterity
 */
void Synonyms() {

    Content content;
    set<vector<int>> many_to_many;

    string command;

    while (true) {
        cin >> command;

        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            content.add(word1);
            content.add(word2);
            int index1, index2;
            index1 = content.indexOf(word1);
            index2 = content.indexOf(word2);

            many_to_many.insert({index1, index2});
            many_to_many.insert({index2, index1});

            PrintSynonyms(content, many_to_many);
            command = "";
            continue;
        }

        if (command == "CHECK") {
            string word_to_check;
            cin >> word_to_check;
            int index_of_word;
            index_of_word = content.indexOf(word_to_check);

            for (const auto &rel:many_to_many) {
                if (rel[0] == index_of_word) {
                    cout << content.getByIndex(rel[1]) << ", ";
                }
            }
            cout << endl;

            command = "";
            continue;
        }

        if (command == "exit") {
            break;
        } else {
            command = "";
            continue;
        }
    }
}

void Algorithms() {

}

void CountIfLambda() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 5, 4, 3, 4, 5};
    int threshold = 5;
    auto b = count_if(begin(a), end(a), [threshold](int i) { return i >= threshold; });
    PrintVectorInt(a);
    cout << b << endl;
}

void ModForCycle() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 5, 4, 3, 4, 5};
    PrintVectorInt(a);
    for (auto &i:a) {
        i++;
    }
    PrintVectorInt(a);
}

// 12 1 -2 7 -8 -9 3 -4 10 20 -30 5 -6 6
void SortByModuleAsc() {
    int size;

    cout << "input: " << endl;
    cin >> size;
    vector<int> v(size, 0);
    for (int i = 0; i < size; ++i) {
        cin >> v[i];
    }

    PrintVectorInt(v);
    sort(begin(v), end(v), [](int a, int b) { return abs(a) < abs(b); });
    PrintVectorInt(v);


}


// 8 Alpha Charlie adler faraway Foxtrot Getsby Beta gann
void SortByLexicRegisterIndependent() {
    int size;
    cout << "input: " << endl;
    cin >> size;

    vector<string> v(size);

    for (int i = 0; i < size; ++i) {
        cin >> v[i];
    }

    PrintVectorString(v);
    sort(begin(v), end(v), [](string a, string b) -> bool {
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        return a < b;
    });
    PrintVectorString(v);


}

void TernaryOperator() {
    int x = 4;
    string even = x % 2 == 0 ? "even" : "odd";
}

string EstimateLength(const string &s) {
    return s.size() > 10 ? "long" : "short";
}

struct Lecture {
    string title;
    string duration;
    string author;
};

struct DetailedLecture {
    string topic;
    Lecture lecture;
};

void UseLecture() {
    DetailedLecture new_lecture = {
            topic: "C++ OOP",
            lecture:
                    {
                            title: "Structs",
                            duration: "540",
                            author: "Anton",
                    },
    };

    cout << new_lecture.topic << ", " << new_lecture.lecture.title << endl;

}

class Route{
private:
    string origin;
    string destination;
    int length;
    void UpdateLength(){
        length = 100;
    }

public:
    const string &getOrigin() const {
        return origin;
    }

    void setOrigin(const string &origin) {
        Route::origin = origin;
        UpdateLength();
    }

    const string &getDestination() const {
        return destination;
    }

    void setDestination(const string &destination) {
        Route::destination = destination;
        UpdateLength();
    }
};


#endif //UNTITLED_LIBRARY_1_H
