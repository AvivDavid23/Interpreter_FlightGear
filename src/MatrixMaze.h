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
    inline Point() : i(0), j(0){}

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
            MatrixMaze(){
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < N; ++j) {
                        std::mt19937 rng;
                        rng.seed(std::random_device()());
                        std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 150);
                        auto randNum = (unsigned int) dist6(rng);
                        if (randNum >= 140) randNum = UINT_MAX;
                        matrix[i][j] = randNum;
                    }
                }
            }

            State<Point> getInitialState(){
                State<Point> state(Point(0, 0));
                state.setCost(matrix[0][0]);
                return state;
            }

            bool isGoalState(State<Point> state){
                return state.getState() == Point(N - 1, N - 1);
            }

            std::vector<State<Point>> getAllPossibleStates(State<Point> state){
                // TODO :: check pointers and destructor!
                using StateP = State<Point>;
                std::vector<StateP> statesVec;
                Point currentPoint = state.getState();
                auto fatherCost = state.getCost();
                auto i = currentPoint.getI();
                auto j = currentPoint.getJ();
                StateP up(Point(i - 1, j));
                StateP down(Point(i + 1, j));
                StateP left(Point(i, j - 1));
                StateP right(Point(i, j + 1));
                if (j != 0) {
                    left.setCost(fatherCost + matrix[i][j - 1]);
                    if (matrix[i][j - 1] != UINT_MAX && *state.getCameFrom() != left) {
                        left.setCameFrom(&state);
                        statesVec.emplace_back(left);
                    }
                }
                if (j != N - 1) {
                    right.setCost(fatherCost + matrix[i][j + 1]);
                    if (matrix[i][j + 1] != UINT_MAX && *state.getCameFrom() != right) {
                        right.setCameFrom(&state);
                        statesVec.emplace_back(right);
                    }
                }
                if (i != N - 1) {
                    down.setCost(fatherCost + matrix[i + 1][j]);
                    if (matrix[i + 1][j] != UINT_MAX && *state.getCameFrom() != down) {
                        down.setCameFrom(&state);
                        statesVec.emplace_back(down);
                    }
                }
                if (i != 0) {
                    up.setCost(fatherCost + matrix[i - 1][j]);
                    if (matrix[i - 1][j] != UINT_MAX && *state.getCameFrom() != up) {
                        up.setCameFrom(&state);
                        statesVec.emplace_back(up);
                    }
                }
                return statesVec;
            }
        };
    }
}

#endif //SECONDYEARPROJECT_BIU_MATRIXMAZE_H
