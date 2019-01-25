#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {

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