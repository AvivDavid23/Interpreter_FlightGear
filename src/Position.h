//
// Created by aviv on 1/10/19.
//

#ifndef SECONDYEARPROJECT_BIU_POSITION_H
#define SECONDYEARPROJECT_BIU_POSITION_H

#include "math.h"
/**
 * simple Position class
 */
class Position {
    unsigned int i;
    unsigned int j;
    int manhattanDist;
public:
    inline Position() : i(0), j(0) {}

    inline Position(unsigned int i, unsigned int j) : i(i), j(j) {}

    inline bool operator==(const Position &other) const { return this->i == other.i && this->j == other.j; }

    inline bool operator<(const Position &other) const { return !(*this == other); }

    inline unsigned int getI() { return i; }

    inline unsigned int getJ() { return j; }

    inline bool aboveMe(const Position &other) const{ return other.i == this->i - 1;}

    inline bool belowMe(const Position &other) const{ return other.i - 1 == this->i;}

    inline bool rightToMe(const Position &other) const{ return other.j - 1 == this->j;}

    inline bool leftToMe(const Position &other) const{ return other.j == this->j - 1;}

    int setManhattanDist(const Position& target){
        manhattanDist = abs((int)this->i - (int)target.i) + abs((int)this->j - (int)target.j);
    }

    inline int getManhattanDist(){ return manhattanDist;}

    inline bool isNeighbor(const Position &other) const{
        return aboveMe(other) || belowMe(other) || leftToMe(other) || rightToMe(other);
    }

};
#endif //SECONDYEARPROJECT_BIU_POSITION_H
