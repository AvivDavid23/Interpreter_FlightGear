//
// Created by aviv on 1/3/19.
//

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
Solution BestFirstSearch<T>::solve(ISearchable<T> *searchable) {
    priorityQueue.push(searchable->getInitialState());
    
}
