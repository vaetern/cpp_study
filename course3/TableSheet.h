#ifndef UNTITLED_TABLESHEET_H
#define UNTITLED_TABLESHEET_H
#pragma once

#include <vector>

using namespace std;

template<typename T>
class TableSheet {

public:
    TableSheet(size_t w, size_t h) : width(w), height(h) {
        for (size_t i = 0; i < height; ++i) {
            rows.push_back(vector<T>(width));
        }
    };

    void Resize(size_t w, size_t h) {
        ResizeWidth(w);
        ResizeHeight(h);
    };

    pair<size_t, size_t > Size() const{
        return make_pair(width, height);
    }

    vector<T>& operator[] (const int index){
        return rows[index];
    };

private:

    void ResizeWidth(size_t w){
        vector<vector<T>> new_rows(w);

        if (width >= w) { // shrink width
            for (auto &old_row:rows) {
                vector<T> new_row(w);
                for (size_t i = 0; i < w; ++i) {
                    new_row.push_back(old_row[i]);
                }
                old_row = new_row;
            }
        }
        else{
                for (auto& old_row:rows) {
                    vector<T> new_row;
                    for (size_t i = 0; i < w; ++i) {
                        if(i < width) {
                            new_row.push_back(old_row[i]);
                        }else{
                            T tmp;
                            new_row.push_back(tmp);
                        }
                    }
                    old_row = new_row;
                }
        };

        width = w; //rewrite width with new
    }


    void ResizeHeight(size_t h){
        vector<vector<T>> new_rows;

        if (height >= h) { // shrink height
                for (size_t i = 0; i < h; ++i) {
                    new_rows.push_back(rows[i]);
                }
                rows = new_rows;
        }
        else{ // stretch height
                for (size_t i = 0; i < h; ++i) {
                    if(i < height) {
                        new_rows.push_back(rows[i]);
                    }else{
                        vector<T> tmp (width);
                        new_rows.push_back(tmp);
                    }
                }
                rows = new_rows;
        };

        height = h; //rewrite width with new
    }

    vector<vector<T> > rows;

    size_t width;
    size_t height;
};


#endif //UNTITLED_TABLESHEET_H
