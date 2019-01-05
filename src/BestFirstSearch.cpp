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
    std::set<State<T>> closed;
    while (openListSize() > 0) {
        State<T> n = popOpenList();
        closed.insert(n);
        if (n == searchable->isGoalState()) {
            // TODO: backtrace
        }
        vector<State<T>> neighbors = searchable->getAllPossibleStates();
        for (State<T> const &item : neighbors) {
            if (priorityQueue.atQueue(item) && closed.find(item) == closed.end()) {
                item.setCameFrom(n);
                priorityQueue.push(item);
            } else {
                State<T> tmp;
                if (closed.find(item) != closed.end()) {
                    continue;
                } else {
                    tmp = priorityQueue.remove(item);
                }
                if (tmp > item) {
                    priorityQueue.push(tmp);
                } else{
                    priorityQueue.push(item);
                }
            }
        }
    }
}
