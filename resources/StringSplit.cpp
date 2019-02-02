#include "StringSplit.h"
#include <algorithm>
#include <sstream>

vector<string> StringSplit::Split(const string &subject, const char &delim) {

    vector<string> out;


    string sub_subject = subject;
    while(true){

        auto offset = find(begin(sub_subject), end(sub_subject), delim);

        string word = "";

        for(auto i = begin(sub_subject); i < offset; ++i){
            word += *i;
        }
        out.push_back(word);

        string new_sub_subject = "";
        for(auto j = next(offset); j < end(sub_subject); ++j){
            new_sub_subject += *j;
        }

        if(offset == end(sub_subject))break;
        sub_subject = new_sub_subject;
    }


    return out;
}


