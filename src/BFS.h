//
// Created by aviv on 1/9/19.
//

#ifndef SECONDYEARPROJECT_BIU_BFS_H
#define SECONDYEARPROJECT_BIU_BFS_H

#include <queue>
#include <map>
#include "State.h"
#include "Searcher.h"

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

    std::string search(ISearchable<T> *searchable) {
        bool goalReached = false;
        std::map<T, bool> visited;
        // initialize all nodes to not visited
        for (auto type : searchable->getAllNodes()) visited[type] = false;
        // push initial state
        stateQueue.push(searchable->getInitialState());
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
                if (!visited[neighbor.getState()]) stateQueue.push(neighbor);
            }
        }
        if (goalReached) {
            // TODO : backtrace
            exit(1);
        } else {
            // TODO : NO SOLUTION
            exit(1);
        }

    }
};

#endif //SECONDYEARPROJECT_BIU_BFS_H
