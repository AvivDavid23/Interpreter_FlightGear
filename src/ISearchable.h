//
// Created by aviv on 1/3/19.
//

#ifndef SECONDYEARPROJECT_BIU_ISEARCHABLE_H
#define SECONDYEARPROJECT_BIU_ISEARCHABLE_H

#include "State.h"
#include "vector"
#include "list"

/**
 * Searchable interface
 */

template<class T, class Solution>
class ISearchable {
public:
    // get start point
    virtual State<T> getInitialState() = 0;

    // return if state is the goal point
    virtual bool isGoalState(State<T> state) = 0;

    // return vector of all the 'neighbors' of state
    virtual std::vector<State<T>> getAllPossibleStates(State<T> state) = 0;

    // get all the 'nodes' of the problem
    virtual std::list<T> getAllNodes() = 0;

    // backtrace from goal to start, returns solution
    virtual Solution backtrace(const State<T>& goal) = 0;

    virtual int getShortestPathCost() = 0;

    virtual void markClosed(T closed) = 0;

    virtual void clear() = 0;

};

#endif //SECONDYEARPROJECT_BIU_ISEARCHABLE_H
