//
// Created by aviv on 1/4/19.
//

#include "MatrixMaze.h"
#include "math.h"

template<unsigned int N>
MatrixMaze<N>::MatrixMaze() {
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

template<unsigned int N>
State<Point> MatrixMaze<N>::getInitialState() {
    return State<Point>(Point(0, 0)).setCost(matrix[0][0]);
}

template<unsigned int N>
bool MatrixMaze<N>::isGoalState(State<Point> state) {
    return state == State<Point>(Point(N - 1, N - 1));
}

template<unsigned int N>
std::vector<State<Point>> MatrixMaze<N>::getAllPossibleStates(State<Point> state) {
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
        if (matrix[i][j - 1] != UINT_MAX && state.getCameFrom() != left) {
            left.setCameFrom(state);
            statesVec.emplace_back(left);
        }
    }
    if (j != N - 1) {
        right.setCost(fatherCost + matrix[i][j + 1]);
        if (matrix[i][j + 1] != UINT_MAX && state.getCameFrom() != right) {
            right.setCameFrom(state);
            statesVec.emplace_back(right);
        }
    }
    if (i != N - 1) {
        down.setCost(fatherCost + matrix[i + 1][j]);
        if (matrix[i + 1][j] != UINT_MAX && state.getCameFrom() != down) {
            down.setCameFrom(state);
            statesVec.emplace_back(down);
        }
    }
    if (i != 0) {
        up.setCost(fatherCost + matrix[i - 1][j]);
        if (matrix[i - 1][j] != UINT_MAX && state.getCameFrom() != up) {
            up.setCameFrom(state);
            statesVec.emplace_back(up);
        }
    }
    return statesVec;

}