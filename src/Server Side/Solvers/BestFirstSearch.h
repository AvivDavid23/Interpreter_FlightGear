//
// Created by aviv on 1/3/19.
//

#ifndef SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H
#define SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H

#include <queue>
#include <algorithm>
#include <iostream>
#include "Searcher.h"
#include "set"
#include "../Utils/CustomPriorityQueue.h"
#include "../Utils/Comparators.h"
/**
 * Best First Search algorithm
 * @tparam T type
 */
template<class T>
class BestFirstSearch : public Searcher<T, std::string> {
    CustomPriorityQueue<State<T>, stateComparator<T>> priorityQueue;
public:
    inline BestFirstSearch() {}

    int openListSize() { return (int) this->priorityQueue.size(); }

    State<T> popOpenList() {
        ++this->nodesEvaluated;
        State<T> state = priorityQueue.top();
        priorityQueue.pop();
        return state;
    }

    std::string search(ISearchable<T, std::string> *searchable) {
        // initialize queue with first state
        priorityQueue.push(searchable->getInitialState());
        // set for nodes that we finished to deal with
        std::set<State<T>> closed;
        // while we have untreated nodes
        while (openListSize() > 0) {
            // pop the min of all odes
            State<T> n = popOpenList();
            searchable->markClosed(n.getState());
            closed.emplace(n);
            // goal state -> finish
            if (searchable->isGoalState(n)) {
                searchable->clear();
                return searchable->backtrace(n);
            }
            // all the nodes we can visit from n
            std::vector<State<T>> neighbors = searchable->getAllPossibleStates(n);
            // no solution
            if (neighbors.empty() && this->priorityQueue.empty()) {
                searchable->clear();
                return "No Solution! \n";
            }
            for (State<T> &item : neighbors) {
                bool inOpen = priorityQueue.atQueue(item);
                bool inClosed = std::find(closed.begin(), closed.end(), item) != closed.end();
                // add to out queue
                if (!inOpen && !inClosed) {
                    priorityQueue.push(item);
                } else {
                    // if item in stop, skip
                    if (inClosed) continue;
                    State<T> tmp = priorityQueue.remove(item);
                    // if item is better, means better path, update tmp
                    if (item < tmp) {
                        tmp.setCameFrom(item.getCameFrom());
                        tmp.setCost(item.getCost());
                    }
                    // reenter temp to queue
                    priorityQueue.push(tmp);

                }
            }
        }
    }
    void clear(){
        this->nodesEvaluated = 0;
        while (!priorityQueue.empty()) priorityQueue.pop();
    }
};

#endif //SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H
