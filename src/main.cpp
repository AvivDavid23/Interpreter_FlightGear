
#include "State.h"
#include "MatrixMaze.h"
#include "DFS.h"
#include "BFS.h"
#include "A_star.h"

int main(int argc, char **argv) {
    MatrixMaze matrixMaze(50, 50);
    string start = "0,0";
    matrixMaze.setStart(start);
    string end = "39,39";
    matrixMaze.setGoal(end);
    cout << matrixMaze.to_string();
    DFS<Position> dfs;
    BFS<Position> bfs;
    A_star<Position> a_star;
    BestFirstSearch<Position> bestFirstSearch;

    cout << bestFirstSearch.search(&matrixMaze) << endl;
    cout << to_string(bestFirstSearch.getEvaluatedNodes()) + "," + to_string(matrixMaze.getShortestPathCost()) + "\n";
    cout << dfs.search(&matrixMaze) << endl;
    cout << to_string(dfs.getEvaluatedNodes()) + "," + to_string(matrixMaze.getShortestPathCost()) + "\n";
    cout << bfs.search(&matrixMaze) << endl;
    cout << to_string(bfs.getEvaluatedNodes()) + "," + to_string(matrixMaze.getShortestPathCost()) + "\n";
    cout << a_star.search(&matrixMaze) << endl;
    cout << to_string(a_star.getEvaluatedNodes()) + "," + to_string(matrixMaze.getShortestPathCost()) + "\n";
    return 0;
}