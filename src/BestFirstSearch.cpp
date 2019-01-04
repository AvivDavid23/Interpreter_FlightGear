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

template<class T>
Solution BestFirstSearch<T>::search(ISearchable<T> *searchable) {
    priorityQueue.push(searchable->getInitialState());
    std::set<State<T>> open;
    std::set<State<T>> closed;
    while(openListSize() > 0) {
        State<T> n = popOpenList();
        open.insert(n);
        closed.insert(n);
        if (n == searchable->isGoalState()){
            // TODO: backtrace
        }
        vector<State<T>> neighbors = searchable->getAllPossibleStates();
        for (State<T> const& item : neighbors) {
            if(open.find(item) == open.end() && closed.find(item) == closed.end()){
                item.setCameFrom(n);
                priorityQueue.push(item);
                open.push(item);
            } /*else if(//TODO: Check if new path is cheaper){

            }*/
        }
    }
}
