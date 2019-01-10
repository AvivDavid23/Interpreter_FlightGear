//
// Created by aviv on 1/10/19.
//

#ifndef SECONDYEARPROJECT_BIU_POSITION_H
#define SECONDYEARPROJECT_BIU_POSITION_H
/**
 * simple Position class
 */
class Position {
    unsigned int i;
    unsigned int j;
public:
    inline Position() : i(0), j(0) {}

    inline Position(unsigned int i, unsigned int j) : i(i), j(j) {}

    inline bool operator==(const Position &other) const { return this->i == other.i && this->j == other.j; }

    inline bool operator<(const Position &other) const { return !(*this == other); }

    inline unsigned int getI() { return i; }

    inline unsigned int getJ() { return j; }

    inline bool aboveMe(const Position &other) const{ return other.i < this->i;}

    inline bool belowMe(const Position &other) const{ return other.i > this->i;}

    inline bool rightToMe(const Position &other) const{ return other.j > this->j;}

    inline bool leftToMe(const Position &other) const{ return other.j < this->j;}

};
#endif //SECONDYEARPROJECT_BIU_POSITION_H
