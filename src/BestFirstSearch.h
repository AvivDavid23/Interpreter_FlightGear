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

template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>, greater<T>> {
public:
    const T &remove(const T &value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return *it;
        }
    }

    bool atQueue(const T &value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        return it != this->c.end();
    }
};

template<class T>
class BestFirstSearch : public Searcher<T> {
    custom_priority_queue<State<T>> priorityQueue;
public:
    inline BestFirstSearch() {}

    int openListSize() { return (int) this->priorityQueue.size(); }

    State<T> popOpenList() {
        //TODO :: Check top()
        ++this->nodesEvaluated;
        State<T> state = priorityQueue.top();
        priorityQueue.pop();
        return state;
    }

    server_side::problem::Solution search(ISearchable<T> *searchable) {
        priorityQueue.push(searchable->getInitialState());
        std::set<State<T>> closed;
        while (openListSize() > 0) {
            State<T> n = popOpenList();
            closed.insert(n);
            if (searchable->isGoalState(n)) {
                std::cout << "done!!!\n";
                exit(1);
                // TODO: backtrace
            }
            std::vector<State<T>> neighbors = searchable->getAllPossibleStates(n);
            for (State<T> &item : neighbors) {
                if (!priorityQueue.atQueue(item) && std::find(closed.begin(), closed.end(), item) == closed.end()) {
                    priorityQueue.push(item);
                } else {
                    if (closed.find(item) != closed.end()) {
                        continue;
                    }
                    State<T> tmp = priorityQueue.remove(item);
                    if (item < tmp) {
                        tmp.setCameFrom(item.getCameFrom());
                        tmp.setCost(item.getCost());
                    }
                    priorityQueue.push(tmp);

                }
            }
        }
    }
};

#endif //SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H
