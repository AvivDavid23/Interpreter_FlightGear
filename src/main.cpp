
#include "State.h"
#include "MatrixMaze.h"
#include "DFS.h"
#include "BFS.h"
int main(int argc, char **argv) {
    MatrixMaze<4> matrixMaze;
    cout << matrixMaze.to_string();
    BestFirstSearch<Position> bfs;
    cout << bfs.search(&matrixMaze);
    return 0;
}