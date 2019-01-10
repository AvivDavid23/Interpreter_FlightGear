//
// Created by aviv on 1/4/19.
//

#ifndef SECONDYEARPROJECT_BIU_MATRIXMAZE_H
#define SECONDYEARPROJECT_BIU_MATRIXMAZE_H

#include "Utils.h"
#include "ISearchable.h"
#include "State.h"
#include "Position.h"
#include <random>
#include <climits>
#include <stdlib.h>
#include "algorithm"


/**
 * Searchable that uses a NxN matrix, and each State is a Position in the matrix
 */
template<unsigned int N>
class MatrixMaze : public ISearchable<Position, std::string> {
    using StateP = State<Position>;
private:
    int matrix[N][N];
    Position start;
    Position goal;
public:
    // TODO: After benchmarks, change constructor to deal with user input and create matrix
    MatrixMaze() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::mt19937 rng;
                rng.seed(std::random_device()());
                std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 11);
                auto randNum = (int) dist6(rng);
                if (randNum == 11) randNum = -1;
                matrix[i][j] = randNum;
            }
        }
    }

    void setStart(std::string &input) {
        unsigned int x, y;
        std::vector<std::string> vec = Utils::splitByChar(input, ',');
        x = (unsigned int) std::stoi(vec[0]);
        y = (unsigned int) std::stoi(vec[1]);
        start = Position(x, y);
    }

    void setGoal(std::string &input) {
        unsigned int x, y;
        std::vector<std::string> vec = Utils::splitByChar(input, ',');
        x = (unsigned int) std::stoi(vec[0]);
        y = (unsigned int) std::stoi(vec[1]);
        goal = Position(x, y);
    }

    std::list<Position> getAllNodes() {
        std::list<Position> positions;
        for (unsigned int i = 0; i < N - 1; ++i) {
            for (unsigned int j = 0; j < N - 1; ++j) {
                positions.emplace_back(Position(i, j));
            }
        }
        return positions;
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
        std::vector<StateP> statesVec;
        auto fatherCost = state.getCost();
        auto i = state.getState().getI();
        auto j = state.getState().getJ();
        // all directions. note that not all are accessible
        StateP up(Position(i - 1, j));
        StateP down(Position(i + 1, j));
        StateP left(Position(i, j - 1));
        StateP right(Position(i, j + 1));
        /**
         * check if we can access each one
         * if we can, first update new price
         * then, if the path is 'blocked' or we came from that direction, pass, else set parent and push into vector
         */
        if (j != 0) {
            left.setCost(fatherCost + matrix[i][j - 1]);
            if (matrix[i][j - 1] != -1 && *state.getCameFrom() != left) {
                left.setCameFrom(&state);
                statesVec.emplace_back(left);
            }
        }
        if (j != N - 1) {
            right.setCost(fatherCost + matrix[i][j + 1]);
            if (matrix[i][j + 1] != -1 && *state.getCameFrom() != right) {
                right.setCameFrom(&state);
                statesVec.emplace_back(right);
            }
        }
        if (i != N - 1) {
            down.setCost(fatherCost + matrix[i + 1][j]);
            if (matrix[i + 1][j] != -1 && *state.getCameFrom() != down) {
                down.setCameFrom(&state);
                statesVec.emplace_back(down);
            }
        }
        if (i != 0) {
            up.setCost(fatherCost + matrix[i - 1][j]);
            if (matrix[i - 1][j] != -1 && *state.getCameFrom() != up) {
                up.setCameFrom(&state);
                statesVec.emplace_back(up);
            }
        }
        return statesVec;
    }

    std::string to_string() {
        std::string output;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] < 10 && matrix[i][j] > -1) output += ' ';
                output += std::to_string(matrix[i][j]);
                if (j < N - 1) output += ',';
            }
            output += '\n';
        }
        return output;
    }

    std::string backtrace(const State<Position> &goal) {
        State<Position> tmp = goal;
        std::vector<std::string> vec;
        std::string path;
        while (tmp.getCameFrom() != nullptr) {
            Position myPosition = tmp.getState();
            Position fatherPosition = tmp.getCameFrom()->getState();
            if (myPosition.aboveMe(fatherPosition))  vec.emplace_back("DOWN,");
            else if (myPosition.belowMe(fatherPosition)) vec.emplace_back("UP,");
            else if (myPosition.leftToMe(fatherPosition)) vec.emplace_back("RIGHT,");
            else vec.emplace_back("LEFT,");
            tmp = *tmp.getCameFrom();
        }
        long i = vec.size() - 1;
        while (i >= 0){
            path += vec[i];
            --i;
        }
        // remove last ','
        path = path.substr(0, path.length() - 1);
        return path;

    }
};


#endif //SECONDYEARPROJECT_BIU_MATRIXMAZE_H
