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


/**
 * Searchable that uses a NxN matrix, and each State is a Position in the matrix
 */
class Position {
    unsigned int i;
    unsigned int j;
public:
    inline Position() : i(0), j(0) {}

    inline Position(unsigned int i, unsigned int j) : i(i), j(j) {}

    inline bool operator==(const Position &other) const { return this->i == other.i && this->j == other.j; }

    inline bool operator<(const Position &other) const { return !(this->i == other.i && this->j == other.j); }

    inline bool operator>(const Position &other) const { return !(this->i == other.i && this->j == other.j); }

    inline unsigned int getI() { return i; }

    inline unsigned int getJ() { return j; }
};

template<unsigned int N>
class MatrixMaze : public ISearchable<Position> {
    using StateP = State<Position>;
private:
    unsigned int matrix[N][N];
public:
    MatrixMaze() {
        matrix[0][0] = 1;
        matrix[0][1] = 23;
        matrix[0][2] = 1;
        matrix[1][0] = 0;
        matrix[1][1] = 30;
        matrix[1][2] = 2;
        matrix[2][0] = 2;
        matrix[2][1] = 5;
        matrix[2][2] = 7;


                  /*{{1, 23, 3},
                  { 0, 30, 2 },
                  { 2, 5, 7 }};*/
        return;
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

    State<Position> getInitialState() {
        StateP state(Position(0, 0));
        state.setCost(matrix[0][0]);
        return state;
    }

    bool isGoalState(State<Position> state) {
        return state == StateP(Position(N - 1, N - 1));
    }

    std::vector<State<Position>> getAllPossibleStates(State<Position> state) {
        // TODO :: check pointers and destructor!
        std::vector<StateP> statesVec;
        auto fatherCost = state.getCost();
        auto i = state.getState().getI();
        auto j = state.getState().getJ();
        StateP up(Position(i - 1, j));
        StateP down(Position(i + 1, j));
        StateP left(Position(i, j - 1));
        StateP right(Position(i, j + 1));
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
                /*{{1, 23, 3},
                { 0, 30, 2 },
                { 2, 5, 7 }};*/
        return statesVec;
    }
};


#endif //SECONDYEARPROJECT_BIU_MATRIXMAZE_H
