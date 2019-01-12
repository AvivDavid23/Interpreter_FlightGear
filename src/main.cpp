
#include "State.h"
#include "MatrixMaze.h"
#include "DFS.h"
#include "BFS.h"
#include "A_star.h"
int main(int argc, char **argv) {
    MatrixMaze<50, 50> matrixMaze;
    string start = "0,0";
    matrixMaze.setStart(start);
    string end = "49,49";
    matrixMaze.setGoal(end);
    cout << matrixMaze.to_string();
    DFS<Position> dfs;
    BFS<Position> bfs;
    A_star<Position> a_star;
    BestFirstSearch<Position> bestFirstSearch;
    cout <<  a_star.search(&matrixMaze) + '\n';
    cout << "A_star evaluated: " + to_string(a_star.getEvaluatedNodes()) + "\n\n";
    cout <<  bestFirstSearch.search(&matrixMaze) + '\n';
    cout << "BestFirstSearch evaluated: " + to_string(bestFirstSearch.getEvaluatedNodes()) + "\n\n";
    /*c*//*out <<  bfs.search(&matrixMaze) + '\n';
    cout << "BFS evaluated: " + to_string(bfs.getEvaluatedNodes())+ "\n\n";
    cout <<  dfs.search(&matrixMaze) + '\n';
    cout << "DFS evaluated: " + to_string(dfs.getEvaluatedNodes()) + "\n\n";*/
    return 0;
}