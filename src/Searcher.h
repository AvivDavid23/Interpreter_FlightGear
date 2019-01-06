//
// Created by aviv on 1/3/19.
//

#ifndef SECONDYEARPROJECT_BIU_SEARCHER_H
#define SECONDYEARPROJECT_BIU_SEARCHER_H
/**
 * Searcher abstract class
 */
#include "Solution.h"
#include "ISearchable.h"
#include "ISearcher.h"

using namespace std;

template<class T>
class Searcher : public ISearcher<T> {
protected:
    int nodesEvaluated;
public:
    inline Searcher() : nodesEvaluated(0) {}

    virtual int openListSize() = 0;

    virtual State<T> popOpenList() = 0;

    inline int getEvaluatedNodes() { return nodesEvaluated; }
};

#endif //SECONDYEARPROJECT_BIU_SEARCHER_H
