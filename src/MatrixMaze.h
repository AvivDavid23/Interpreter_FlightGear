//
// Created by aviv on 1/4/19.
//

#ifndef SECONDYEARPROJECT_BIU_MATRIXMAZE_H
#define SECONDYEARPROJECT_BIU_MATRIXMAZE_H

#include "ISearchable.h"
#include "State.h"
#include <random>
#include <climits>
#include <stdlib.h>

using namespace server_side::problem;

/**
 * Searchable that uses a NxN matrix, and each State is a 'Point' in the matrix
 */
class Point {
    unsigned int i;
    unsigned int j;
public:
    inline Point(unsigned int i, unsigned int j) : i(i), j(j) {}

    inline bool operator==(const Point &other) const { return this->i == other.i && this->j == other.j; }

    inline bool operator<(const Point &other) const { return !(this->i == other.i && this->j == other.j); }

    inline bool operator>(const Point &other) const { return !(this->i == other.i && this->j == other.j); }

    inline unsigned int getI() { return i; }

    inline unsigned int getJ() { return j; }
};
namespace server_side {
    namespace problem {
        template<unsigned int N>
        class MatrixMaze : public server_side::problem::ISearchable<Point> {
        private:
            unsigned int matrix[N][N];
        public:
            MatrixMaze();

            State<Point> getInitialState();

            bool isGoalState(State<Point> state);

            std::vector<State<Point>> getAllPossibleStates(State<Point> state);

        };
    }
}

#endif //SECONDYEARPROJECT_BIU_MATRIXMAZE_H
