//
// Created by aviv on 1/1/19.
//

#include "State.h"

template<class T>
State<T>::State(T state) {
    this->state = state;
}

template<class T>
void State<T>::setCost(double cost) {
    this->cost = cost;
}

template <class T>
void State<T>::setCameFrom(State<T> cameFrom) {
    this->cameFrom = cameFrom;
}

template <class T>
bool State<T>::operator==(State<T> other) {
    return (this->cameFrom == other.cameFrom) && (this->cost == other.cost) && (this->state == other.state);
}