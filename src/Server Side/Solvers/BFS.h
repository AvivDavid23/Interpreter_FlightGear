//
// Created by aviv on 1/9/19.
//

#ifndef SECONDYEARPROJECT_BIU_BFS_H
#define SECONDYEARPROJECT_BIU_BFS_H

#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include "../Problems/State.h"
#include "Searcher.h"
/**
 * BFS algorithm
 * @tparam T type
 */
template<class T>
class BFS : public Searcher<T, std::string> {
    queue<State<T>> stateQueue;
public:
    inline BFS() {}

    int openListSize() { return (int) this->stateQueue.size(); }

    State<T> popOpenList() {
        ++this->nodesEvaluated;
        State<T> state = stateQueue.front();
        stateQueue.pop();
        return state;
    }

    std::string search(ISearchable<T, std::string> *searchable) {
        bool goalReached = false;
        std::set<T> visited;
        // push initial state
        stateQueue.push(searchable->getInitialState());
        visited.emplace(searchable->getInitialState().getState());
        State<T> node;
        while (openListSize() > 0) {
            node = popOpenList();
            // if node is goal, we will break
            goalReached = searchable->isGoalState(node);
            if (goalReached) break;
            // push all unvisited neighbors
            for (auto neighbor : searchable->getAllPossibleStates(node)) {
                if (std::find(visited.begin(), visited.end(), neighbor.getState()) == visited.end()) {
                    visited.emplace(neighbor.getState());
                    stateQueue.push(neighbor);
                }
            }
        }
        if (goalReached) {
            searchable->clear();
            return searchable->backtrace(node);
        } else {
            searchable->clear();
            return "No Solution! \n";
        }

    }

    void clear(){
        this->nodesEvaluated = 0;
        while (!stateQueue.empty()) stateQueue.pop();
    }
};


#endif //SECONDYEARPROJECT_BIU_BFS_H
