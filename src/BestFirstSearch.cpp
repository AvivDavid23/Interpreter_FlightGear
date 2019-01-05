//
// Created by aviv on 1/3/19.
//

#include <set>
#include "BestFirstSearch.h"

template<class T>
int BestFirstSearch<T>::openListSize() { return (int) this->priorityQueue.size(); }

template<class T>
State<T> BestFirstSearch<T>::popOpenList() {
    ++this->nodesEvaluated;
    problem::State<T> state = priorityQueue.top();
    priorityQueue.pop();
    return state;
}
//TODO:: FINISH THIS ALG
template<class T>
Solution BestFirstSearch<T>::search(ISearchable<T> *searchable) {
    priorityQueue.push(searchable->getInitialState());
    std::set<State<T>> open;
    open.insert(searchable->getInitialState());
    std::set<State<T>> closed;
    while (openListSize() > 0) {
        State<T> n = popOpenList();
        open.erase(n);
        closed.insert(n);
        if (n == searchable->isGoalState()) {
            // TODO: backtrace
        }
        vector<State<T>> neighbors = searchable->getAllPossibleStates();
        for (State<T> const &item : neighbors) {
            if (open.find(item) == open.end() && closed.find(item) == closed.end()) {
                item.setCameFrom(n);
                priorityQueue.push(item);
                open.push(item);
            } else {
                State<T> tmp;
                if (closed.find(item) != closed.end()) {
                    continue;
                } else {
                    tmp = *open.find(item);
                }
                if (tmp < item) {
                    priorityQueue.insert(tmp);
                    open.erase(item);
                    open.insert(tmp);
                }
            }
        }
    }
}
