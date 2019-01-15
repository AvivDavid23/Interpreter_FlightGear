//
// Created by aviv on 1/9/19.
//

#ifndef SECONDYEARPROJECT_BIU_DFS_H
#define SECONDYEARPROJECT_BIU_DFS_H

#include <algorithm>
#include <iostream>
#include <stack>
#include <map>
#include "Searcher.h"
#include "set"
#include "BestFirstSearch.h"

/**
 * DFS algorithm
 * @tparam T type
 */
template<class T>
class DFS : public Searcher<T, std::string> {
    stack<State<T>> stateStack;
public:
    inline DFS() {}

    int openListSize() { return (int) this->stateStack.size(); }

    State<T> popOpenList() {
        ++this->nodesEvaluated;
        State<T> state = stateStack.top();
        stateStack.pop();
        return state;
    }

    std::string search(ISearchable<T, std::string> *searchable) {
        bool goalReached = false;
        std::set<T> visited;
        // push initial state
        stateStack.push(searchable->getInitialState());
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
                    stateStack.push(neighbor);
                }
            }
        }
        searchable->clear();
        if (goalReached) {
            return searchable->backtrace(node);
        } else {
            return "No Solution! \n";
        }

    }
    void clear(){
        this->nodesEvaluated = 0;
        while (!stateStack.empty()) stateStack.pop();
    }
};

#endif //SECONDYEARPROJECT_BIU_DFS_H
