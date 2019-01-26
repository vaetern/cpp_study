#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>


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
    for (auto i:a){
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

void for_i(){
    std::string a = "abcdabcdabcd";

    for(int i = 0; i < a.size(); ++i){
        if(a[i] == 'a'){
            std::cout << i <<std::endl;
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
//iterate_map();
    for_i();
    return 0;
}


