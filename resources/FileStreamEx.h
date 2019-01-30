#ifndef UNTITLED_FILESTREAMEX_H
#define UNTITLED_FILESTREAMEX_H

#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;


class FileReaderCsv {
public:
    FileReaderCsv(string filename_in) {
        filename = filename_in;
    }

    string GetDashed() const {

        ifstream input(filename);

        if (!input.is_open()) {
            throw EEXIST;
        }

        string lines;
        string concat;
        while (getline(input, lines, ';')) {
            concat += lines + " - ";
        }

        return concat;
    }

    void CoutGlued() const {

        ifstream input(filename);

        if (!input.is_open()) {
            throw EEXIST;
        }

        string word;
        while (input) {
            input >> word;
            input.ignore(1); //ignore 1 char
            cout << word;
        }

    }

private:
    string filename;

};

class FileWriterCsv {
public:
    FileWriterCsv(string filename_new) {
        filename = filename_new;
    }

    void AddAsCsvLine(vector<string> line) const {
        ofstream output(filename, ios::app); //append
        for (auto l:line) {
            output << l << ",";
        }
        output << endl;
    }

private:
    string filename;

};

class FileWriterTable {
public:
    FileWriterTable(string filename_new, vector<string> &columns) {
        filename = filename_new;
        ofstream output(filename, ios::app);

        cout << setfill('.');
        cout << left;
        for (auto col:columns) {
            output << setw(10) << col << " ";
        }
        output << endl;
    }

    void AddTr(vector<double> line) const {
        ofstream output(filename, ios::app); //append

        cout << fixed << setprecision(4)  << left << setfill('.');

        for (auto elem:line) {
            output << setw(10) <<elem << " ";
        }
        output << endl;
    }

private:
    string filename;

};

#endif //UNTITLED_FILESTREAMEX_H
