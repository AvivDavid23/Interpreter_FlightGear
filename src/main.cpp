
#include "State.h"
#include "MatrixMaze.h"
#include "DFS.h"
#include "BFS.h"
#include "A_star.h"
int main(int argc, char **argv) {
    MatrixMaze matrixMaze(50,50);
    string start = "0,0";
    matrixMaze.setStart(start);
    string end = "49,49";
    matrixMaze.setGoal(end);
    cout << matrixMaze.to_string();
    DFS<Position> dfs;
    BFS<Position> bfs;
    A_star<Position> a_star;
    BestFirstSearch<Position> bestFirstSearch;

    bestFirstSearch.search(&matrixMaze);
    cout << to_string(bestFirstSearch.getEvaluatedNodes()) + "," + to_string(matrixMaze.getShortestPathCost()) + "\n";
    dfs.search(&matrixMaze);
    cout << to_string(dfs.getEvaluatedNodes()) + "," + to_string(matrixMaze.getShortestPathCost()) + "\n";
    bfs.search(&matrixMaze);
    cout << to_string(bfs.getEvaluatedNodes()) + "," + to_string(matrixMaze.getShortestPathCost()) + "\n";
    a_star.search(&matrixMaze);
    cout << to_string(a_star.getEvaluatedNodes()) + "," + to_string(matrixMaze.getShortestPathCost()) + "\n";
    return 0;
}