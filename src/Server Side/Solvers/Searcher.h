//
// Created by aviv on 1/3/19.
//

#ifndef SECONDYEARPROJECT_BIU_SEARCHER_H
#define SECONDYEARPROJECT_BIU_SEARCHER_H

#include "../Problems/ISearchable.h"
#include "ISearcher.h"
/**
 * Abstract searcher which saves the number of nodes evaluated for the main searcher(BFS, DFS, A*...)
 */
using namespace std;

template<class T, class Solution>
class Searcher : public ISearcher<T, Solution> {
protected:
    int nodesEvaluated;
public:
    inline Searcher() : nodesEvaluated(0) {}

    virtual int openListSize() = 0;

    virtual State<T> popOpenList() = 0;

    // get number of nodes evaluated by the algorithm
    inline int getEvaluatedNodes() { return nodesEvaluated; }
};

#endif //SECONDYEARPROJECT_BIU_SEARCHER_H
