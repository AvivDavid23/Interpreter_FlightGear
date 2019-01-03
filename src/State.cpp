//
// Created by aviv on 1/1/19.
//

#include "State.h"

template<class T>
server_side::problem::State<T>::State(T state) {
    this->state = state;
}
template<class T>
server_side::problem::State<T>::~State() {
    delete cameFrom;
}

template<class T>
void server_side::problem::State<T>::setCost(double cost) const {
    this->cost = cost;
}

template <class T>
void server_side::problem::State<T>::setCameFrom(State<T> cameFrom) {
    this->cameFrom = cameFrom;
}

template <class T>
bool server_side::problem::State<T>::operator==(const State<T>& other) const {
    return (this->cameFrom == other.cameFrom) && (this->cost == other.cost) && (this->state == other.state);
}
template <class T>
bool server_side::problem::State<T>::operator<(const State<T>& other) const {
    return this->cost < other.cost;
}
template <class T>
bool server_side::problem::State<T>::operator>(const State<T>& other) const {
    return this->cost > other.cost;
}
