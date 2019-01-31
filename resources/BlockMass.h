#ifndef UNTITLED_BLOCKMASS_H
#define UNTITLED_BLOCKMASS_H


#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Block {
public:
    Block(uint16_t &density_, uint16_t &W_, uint16_t &H_, uint16_t &D_) {
        mass = CountMass(density_, W_, H_, D_);
    }

    uint32_t GetMass() const {
        return mass;
    }


private:

    uint32_t mass;

    double CountMass(uint16_t &density_, uint16_t &W_, uint16_t &H_, uint16_t &D_) const {
        return density_ * W_ * H_ * D_;
    }

};


void RunMassCalculator() {
    int count = 0;
    uint16_t density = 0;
    cin >> count >> density;

    uint16_t W, H, D;
    vector<Block> blocks;
    uint32_t mass = 0;
    for (int i = 0; i < count; ++i) {
        cin >> W >> H >> D;
        mass += Block(density, W, H, D).GetMass();
    }

    cout << "Total mass:" << mass;
}


#endif //UNTITLED_BLOCKMASS_H
