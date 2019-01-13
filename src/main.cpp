
#include "State.h"
#include "MatrixMaze.h"
#include "DFS.h"
#include "BFS.h"
#include "A_star.h"
#include "Main.h"

int main(int argc, char **argv) {
    //return boot::Main::main(argc,argv);
    string s1 = "1,2,3\n";
    string s2 = "5,6,7\n";
    string s3 = "8,9,10\n";
    string s4 = "0,0\n";
    string s5 = "2,2\n";
    std::vector<string> vector1 = {s1 ,s2 ,s3 ,s4 ,s5};
    MatrixMaze matrixMaze(vector1);
    matrixMaze.to_string();
}