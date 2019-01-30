#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string &first_name) {
        first_name_history[year] = first_name;
    }

    void ChangeLastName(int year, const string &last_name) {
        last_name_history[year] = last_name;
    }

    const string GetFullName(int year) {
        string last_nm, first_nm;
        first_nm = GetFirstNameForYear(year);
        last_nm = GetLastNameForYear(year);

        if (first_nm == "" && last_nm == "") {
            return incognito;
        }

        if (first_nm != "" && last_nm == "") {
            return first_nm + " " + no_last_name;
        }

        if (first_nm == "" && last_nm != "") {
            return last_nm + " " + no_first_name;
        }

        return first_nm + " " + last_nm;
    }

    string GetFullNameWithHistory(int year) {
        string last_name, first_name;
        first_name = GetFirstNameHistoryForYear(year);
        last_name = GetLastNameHistoryForYear(year);

        string ret = to_string(year) + ": ";

        if (first_name == "" && last_name == "") {
            return ret + incognito;
        }

        if (first_name != "" && last_name == "") {
            return ret + first_name + " " + no_last_name;
        }

        if (first_name == "" && last_name != "") {
            return ret + last_name + " " + no_first_name;
        }

        return ret + first_name + " " + last_name;

    }


private:
    const string incognito = "incognito";
    const string no_first_name = "with unknown first name";
    const string no_last_name = "with unknown last name";
    map<int, string> first_name_history;
    map<int, string> last_name_history;

    string GetFirstNameForYear(int year) const {
        string current = "";
        for (auto[y, fn]: first_name_history) {
            if (y > year) {
                break;
            }
            current = fn;
        }

        return current;
    }

    string GetLastNameForYear(int year) const {
        string current = "";
        for (auto[y, ln]: last_name_history) {
            if (y > year) {
                break;
            }
            current = ln;
        }

        return current;
    }

    string GetFirstNameHistoryForYear(int year) const {
        vector<string> history;
        string current, previous = "";
        for (auto[y, fn]: first_name_history) {

            if (current != previous) {
                history.push_back(current);
            }

            if (y > year) {
                break;
            }
            previous = current;
            current = fn;
        }

        string additional = "";
        if (!history.empty()) {
            additional = "(";
            for (int i = 0; i < history.size(); ++i) {
                additional += history[i];
                if (i < history.size() - 1) {
                    additional += +", ";
                }
            }
            additional += ")";
        }
        return current + additional;
    }

    string GetLastNameHistoryForYear(int year) const {
        vector<string> history;
        string current, previous = "";
        for (auto[y, ln]: last_name_history) {

            if (current != previous) {
                history.push_back(current);
            }

            if (y > year) {
                break;
            }
            previous = current;
            current = ln;
        }

        string additional = "";
        if (!history.empty()) {
            additional = "(";
            for (int i = 0; i < history.size(); ++i) {
                additional += history[i];
                if (i < history.size() - 1) {
                    additional += +", ";
                }
            }
            additional += ")";
        }


        return current + additional;
    }
};

#endif //UNTITLED_PERSON_H
