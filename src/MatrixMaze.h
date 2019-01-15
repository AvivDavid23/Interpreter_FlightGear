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
class MatrixMaze : public ISearchable<Position, std::string> {
    using StateP = State<Position>;
private:
    std::vector<std::vector<int>> matrix;
    int N;
    int M;
    Position start;
    Position goal;
public:
    // TODO: After benchmarks, change constructor to deal with user input and create matrix
    MatrixMaze(unsigned int n, unsigned int m) {
        for (int i = 0; i < n; ++i) {
            std::vector<int> inner;
            for (int j = 0; j < m; ++j) {
                std::mt19937 rng;
                rng.seed(std::random_device()());
                std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 11);
                auto randNum = (int) dist6(rng);
                if (randNum == 11 && (i != 0 && j != 0) && (i != N - 1 && j != M - 1)) randNum = -1;
                inner.push_back(randNum);
            }
            matrix.push_back(inner);
        }
        N = n;
        M = m;
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
            for (int j = 0; j < M; ++j) {
                if (matrix[i][j] < 10 && matrix[i][j] > -1) output += ' ';
                output += std::to_string(matrix[i][j]);
                if (j < M - 1) output += ',';
            }
            output += '\n';
        }
        std::string printStar = std::to_string(start.getI()) + "   ," + std::to_string(start.getJ()) + "\n";
        std::string printEnd = std::to_string(goal.getI()) + "   ," + std::to_string(goal.getJ()) + "\n";
        output += printStar + printEnd + '\n';
        return output;
    }

    std::string backtrace(const State<Position> &goal) {
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
        path = path.substr(0, path.length() - 1) + "\n";
        return path;

    }

    MatrixMaze(std::vector<std::string> &vector) {
       int i = 0,index;
        for(; i!=vector.size(); ++i) {
            if(vector[i] == "")
               vector.erase(vector.begin() + i);
        }
        int length = (int)vector.size();
        N = length - 2;
        M = (int)std::count(vector[0].begin(), vector[0].end(), ',') + 1;
        for (int i = 0; i < N; ++i) {
            std::vector<int> inner;
             index = 0;
            while(vector[i- index -1]== " ") index++;
            std::string withoutNewLine = vector[i].substr(0, vector[i].length() - index);
            std::vector<std::string> tmp = Utils::split(withoutNewLine, ',');
            for (int j = 0; j < M; ++j) {
                if(tmp[j]!= " ")
                    inner.push_back(stoi(tmp[j]));
            }
            matrix.push_back(inner);
            inner.clear();
        }
        index = 0;
        vector[length - 2] = vector[length - 2].substr(0, vector[length - 2].length()); //- 1);
        vector[length - 1] = vector[length - 1].substr(0, vector[length - 1].length()); //- 1);
        setStart(vector[length - 2]);
        setGoal(vector[length - 1]);
    }
};


#endif //SECONDYEARPROJECT_BIU_MATRIXMAZE_H
