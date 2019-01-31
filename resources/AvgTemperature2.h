#ifndef UNTITLED_AVGTEMPERATURE2_H
#define UNTITLED_AVGTEMPERATURE2_H

#include <iostream>
#include <vector>

using namespace std;

void RunAvgTemperature2() {

    int count = 0;
    cout << ":" << endl;
    cin >> count;

    vector<double> numbers;
    double sum = 0;
    for (int i = 0; i < count; ++i) {
        double in = 0;
        cin >> in;
        numbers.push_back(in);
        sum += in;
    }
    double avg = sum / count;

    vector<int> position;
    for (int j = 0; j < numbers.size(); ++j) {
        if (numbers[j] > avg) {
            position.push_back(j);
        }
    }

    cout << position.size() << endl;
    for (auto pos:position) {
        cout << pos << " ";
    }

}


#endif //UNTITLED_AVGTEMPERATURE2_H
