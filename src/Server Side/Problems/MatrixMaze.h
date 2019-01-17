//
// Created by aviv on 1/4/19.
//

#ifndef SECONDYEARPROJECT_BIU_MATRIXMAZE_H
#define SECONDYEARPROJECT_BIU_MATRIXMAZE_H

#include "../Utils/Utils.h"
#include "ISearchable.h"
#include "State.h"
#include "../Utils/Position.h"
#include <random>
#include <climits>
#include <stdlib.h>
#include <map>
#include "algorithm"


/**
 * Searchable that uses a NxN matrix, and each State is a Position in the matrix
 */
class MatrixMaze : public ISearchable<Position, std::string> {
    using StateP = State<Position>;
private:
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> originalValues;
    int N;
    int M;
    double shortestPathCost = -1;
    Position start;
    Position goal;
public:
    MatrixMaze(unsigned int n, unsigned int m) {
        N = n;
        M = m;
        for (int i = 0; i < N; ++i) {
            std::vector<int> inner;
            for (int j = 0; j < M; ++j) {
                std::mt19937 rng;
                rng.seed(std::random_device()());
                std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 11);
                auto randNum = (int) dist6(rng);
                if (randNum == 11 && (i != 0 && j != 0) && (i != N - 1 && j != M - 1)) randNum = -1;
                inner.push_back(randNum);
            }
            matrix.push_back(inner);
        }
        originalValues = matrix;
    }

    MatrixMaze(std::vector<std::string> &vector) {
        int length = (int)vector.size();
        N = length - 2;
        M = (int)std::count(vector[0].begin(), vector[0].end(), ',') + 1;
        for (int i = 0; i < N; ++i) {
            std::vector<int> inner;
            std::string withoutNewLine = vector[i].substr(0, vector[i].length());
            std::vector<std::string> tmp = Utils::split(withoutNewLine, ',');
            for (int j = 0; j < M; ++j) {
             if(tmp[j] != " ")
                inner.push_back(stoi(tmp[j]));
            }
            matrix.push_back(inner);
            inner.clear();
        }
        vector[length - 2] = vector[length - 2].substr(0, vector[length - 2].length());
        vector[length - 1] = vector[length - 1].substr(0, vector[length - 1].length());
        setStart(vector[length - 2]);
        setGoal(vector[length - 1]);
        originalValues = matrix;
    }

    void setStart(std::string &input) {
        unsigned int x, y;
        std::vector<std::string> vec = Utils::split(input, ',');
        x = (unsigned int) std::stoi(vec[0]);
        y = (unsigned int) std::stoi(vec[1]);
        start = Position(x, y);
    }

    void setGoal(std::string &input) {
        unsigned int x, y;
        std::vector<std::string> vec = Utils::split(input, ',');
        x = (unsigned int) std::stoi(vec[0]);
        y = (unsigned int) std::stoi(vec[1]);
        goal = Position(x, y);
    }

    std::list<Position> getAllNodes() {
        std::list<Position> positions;
        for (unsigned int i = 0; i < N; ++i) {
            for (unsigned int j = 0; j < M; ++j) {
                positions.emplace_back(Position(i, j));
            }
        }
        return positions;
    }

    State<Position> getInitialState() {
        State<Position> p(start);
        p.setCost(matrix[start.getI()][start.getJ()]);
        p.setManDist(goal);
        return p;
    }

    bool isGoalState(State<Position> state) {
        return state.getState() == goal;
    }

    std::vector<State<Position>> getAllPossibleStates(State<Position> state) {
        std::vector<StateP> statesVec;
        auto fatherCost = state.getCost();
        auto i = state.getState().getI();
        auto j = state.getState().getJ();
        // all directions. note that not all are accessible
        StateP up(Position(i - 1, j));
        up.setManDist(goal);
        StateP down(Position(i + 1, j));
        down.setManDist(goal);
        StateP left(Position(i, j - 1));
        left.setManDist(goal);
        StateP right(Position(i, j + 1));
        right.setManDist(goal);
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
        if (j != M - 1) {
            right.setCost(fatherCost + matrix[i][j + 1]);
            if (matrix[i][j + 1] != -1 && *state.getCameFrom() != right) {
                right.setCameFrom(&state);
                statesVec.emplace_back(right);
            }
        }
        if (i != N - 1) {
            down.setCost(fatherCost + matrix[i + 1][j]);
            if (matrix[i + 1][j] != -1 && *state.getCameFrom() != down ) {
                down.setCameFrom(&state);
                statesVec.emplace_back(down);
            }
        }
        if (i != 0) {
            up.setCost(fatherCost + matrix[i - 1][j]);
            if (matrix[i - 1][j] != -1 && *state.getCameFrom() != up ) {
                up.setCameFrom(&state);
                statesVec.emplace_back(up);
            }
        }
        return statesVec;
    }
    std::string to_string() {
        std::string output;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (matrix[i][j] < 10 && matrix[i][j] > -1) output += ' ';
                output += std::to_string(matrix[i][j]);
                if (j < M - 1) output += ',';
            }
            output += '\n';
        }
        output += std::to_string(this->start.getI()) + " ," + std::to_string(this->start.getJ()) + "\n";
        output += std::to_string(this->goal.getI()) + " ," + std::to_string(this->goal.getJ()) + "\n";
        return output;
    }

    std::string backtrace(const State<Position> &goal) {
        shortestPathCost = goal.getCost();
        State<Position> tmp = goal;
        std::vector<std::string> vec;
        std::string path;
        while (tmp.getCameFrom() != nullptr) {
            Position myPosition = tmp.getState();
            Position fatherPosition = tmp.getCameFrom()->getState();
            if (myPosition.aboveMe(fatherPosition)) vec.emplace_back("Down,");
            else if (myPosition.belowMe(fatherPosition)) vec.emplace_back("Up,");
            else if (myPosition.leftToMe(fatherPosition)) vec.emplace_back("Right,");
            else vec.emplace_back("Left,");
            tmp = *tmp.getCameFrom();
        }
        long i = vec.size() - 1;
        while (i >= 0) {
            path += vec[i];
            --i;
        }
        // remove last ','
        path = path.substr(0, path.length() - 1);
        return path;

    }

    int getShortestPathCost() { return (int) shortestPathCost; }

    void markClosed(Position closed) { matrix[closed.getI()][closed.getJ()] = -1; }

    void clear() {
        matrix = originalValues;
    }
};



#endif //SECONDYEARPROJECT_BIU_MATRIXMAZE_H
