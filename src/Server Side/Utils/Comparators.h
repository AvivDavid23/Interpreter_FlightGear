//
// Created by aviv on 1/10/19.
//

#ifndef SECONDYEARPROJECT_BIU_COMPARATORS_H
#define SECONDYEARPROJECT_BIU_COMPARATORS_H

#include "../Problems/State.h"
/**
 * The file contains several comparators we can use(for example, with priority queue)
 */
/**
 * Comparator of two generic States
 * @tparam T type
 */
template <class T>
struct stateComparator{
public:
    bool operator() (const State<T>& a, const State<T>& b)
    {
        return a.getCost() > b.getCost();
    }
};

/**
 * heuristic comparator which used for a_star algorithm
 * @tparam T type of state, note that each T must implement getManhattanDist + setManhattanDist
 */
template <class T>
struct manhattanHeuristicOfStates{
    bool operator() (const State<T>& a, const State<T>& b)
    {
        return a.getCost() + a.getState().getManhattanDist() > b.getCost() + b.getState().getManhattanDist();
    }
};
#endif //SECONDYEARPROJECT_BIU_COMPARATORS_H
