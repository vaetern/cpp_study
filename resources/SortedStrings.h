#ifndef UNTITLED_SORTEDSTRINGS_H
#define UNTITLED_SORTEDSTRINGS_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class SortedStrings {
public:
    void AddString(const string &s) {
        collection.push_back(s);
    }

    vector<string> GetSortedStrings() {
        return GetSorted();
    }


private:
    vector<string> collection;

    vector<string> GetSorted() {
        vector<string> v = collection;
        sort(begin(v), end(v), [](string a, string b) -> bool {
            transform(a.begin(), a.end(), a.begin(), ::tolower);
            transform(b.begin(), b.end(), b.begin(), ::tolower);
            return a < b;
        });

        return v;
    }
};


#endif //UNTITLED_SORTEDSTRINGS_H
