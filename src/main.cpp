
#include "State.h"
#include "MatrixMaze.h"
#include "DFS.h"
#include "BFS.h"
int main(int argc, char **argv) {
    MatrixMaze<15> matrixMaze;
    cout << matrixMaze.to_string();
    BestFirstSearch<Position> bfs;
    bfs.search(&matrixMaze);
    return 0;
}