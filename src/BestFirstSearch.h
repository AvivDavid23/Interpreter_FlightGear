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
    T remove(const T &value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            T st = *it;
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return st;
        }
    }

    bool atQueue(const T &value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        return it != this->c.end();
    }

    inline void heapify(){
        std::make_heap(this->c.begin(), this->c.end(), this->comp);
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
            if (neighbors.empty() && this->priorityQueue.empty()){
                // TODO: Return no solution
                exit(1);
            }
            for (State<T> &item : neighbors) {
                bool inOpen = priorityQueue.atQueue(item);
                bool inClosed = std::find(closed.begin(), closed.end(), item) != closed.end();
                if (!inOpen && !inClosed) {
                    priorityQueue.push(item);
                    this->priorityQueue.heapify();
                } else {
                    if (inClosed) continue;
                     State<T> tmp = priorityQueue.remove(item);
                    if (item < tmp) {
                        tmp.setCameFrom(item.getCameFrom());
                        tmp.setCost(item.getCost());
                    }
                    priorityQueue.push(tmp);
                    this->priorityQueue.heapify();

                }
            }
        }
    }
};

#endif //SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H
