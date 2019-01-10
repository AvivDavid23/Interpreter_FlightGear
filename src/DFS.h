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
        std::map<T, bool> visited;
        // initialize all nodes to not visited
        for (auto type : searchable->getAllNodes()) visited[type] = false;
        // push initial state
        stateStack.push(searchable->getInitialState());
        State<T> node;
        while (openListSize() > 0) {
            node = popOpenList();
            // if node is goal, we will break
            goalReached = searchable->isGoalState(node);
            if (goalReached) break;
            // if not visited, mark visited
            if (!visited[node.getState()]) visited[node.getState()] = true;
            // push all unvisited neighbors
            for (auto neighbor : searchable->getAllPossibleStates(node)) {
                if (!visited[neighbor.getState()]) stateStack.push(neighbor);
            }
        }
        if (goalReached) {
            return searchable->backtrace(node);
        } else {
            return "No Solution! \n";
        }

    }
};

#endif //SECONDYEARPROJECT_BIU_DFS_H
