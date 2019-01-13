//
// Created by aviv on 1/10/19.
//

#ifndef SECONDYEARPROJECT_BIU_A_H
#define SECONDYEARPROJECT_BIU_A_H

#include <set>
#include "State.h"
#include "queue"
#include "CustomPriorityQueue.h"
#include "Searcher.h"
#include "string"
#include "map"
#include "Comparators.h"

/**
 * A* algorithm which uses Manhattan Distance heuristic
 * @tparam T type
 */
template<class T>
class A_star : public Searcher<T, std::string> {
    CustomPriorityQueue<State<T>, manhattanHeuristicOfStates<T>> priorityQueue;
public:
    inline A_star() {}

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
            closed.emplace(n);
            // goal state -> finish
            if (searchable->isGoalState(n)) {
                cout << "PRICE: " + to_string(n.getCost()) << '\n';
                return searchable->backtrace(n);
            }
            // all the nodes we can visit from n
            std::vector<State<T>> neighbors = searchable->getAllPossibleStates(n);
            // no solution
            if (neighbors.empty() && this->priorityQueue.empty()) {
                return "No Solution! \n";
            }
            for (State<T> &item : neighbors) {
                bool inOpen = priorityQueue.atQueue(item);
                bool inClosed = std::find(closed.begin(), closed.end(), item) != closed.end();
                // add to out queue
                if (!inOpen && !inClosed) {
                    priorityQueue.push(item);
                } else {
                    // if item in close, skip
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
};
#endif //SECONDYEARPROJECT_BIU_A_H