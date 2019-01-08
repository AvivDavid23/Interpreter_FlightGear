
#include "State.h"
#include "MatrixMaze.h"
#include "BestFirstSearch.h"
int main(int argc, char **argv) {
    MatrixMaze<3> matrixMaze;
    BestFirstSearch<Position> bestFirstSearch;
    bestFirstSearch.search(&matrixMaze);
    return 0;
}