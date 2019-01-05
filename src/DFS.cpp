//
// Created by aviv on 1/5/19.
//

#include "DFS.h"

template<class T>
int DFS<T>::openListSize() { return (int) stack1.size(); }

template<class T>
State<T> DFS<T>::popOpenList() {
    ++this->nodesEvaluated;
    State<T> state = stack1.top();
    stack1.pop();
    return state;
}

template<class T>
Solution DFS<T>::search(ISearchable<T> *searchable) {
    map<State<T>, bool> visited;
    stack1.push(searchable->getInitialState());
    while (!stack1.empty()){
        State<T> current = stack1.top();
        stack1.pop();
    }
}