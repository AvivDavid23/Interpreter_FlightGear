//
// Created by aviv on 1/1/19.
//

#ifndef SECONDYEARPROJECT_BIU_STATE_H
#define SECONDYEARPROJECT_BIU_STATE_H


#include <vector>

template<class T>
class State {
    T state;
    double cost = 0;
    State<T> *cameFrom = nullptr;
public:
    State() {}

    State(T state) : state(state) {}

    State(const State<T> &other) {
        state = other.state;
        cost = other.cost;
        if (other.cameFrom != nullptr) {
            cameFrom = new State<T>();
            *cameFrom = *other.cameFrom;
        }
    }

    /*~State() {
        State<T> *current = this;
        State<T> *next = current;
        current = current->getCameFrom();
        if (next->cameFrom)
            free (next->cameFrom);
        if (current != nullptr)
            delete current;
    }*/


    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State<T> *cameFrom) {
        this->cameFrom = cameFrom;
    }

    bool operator==(const State<T> &other) const {
        if (this == nullptr || &other == nullptr) return false;
        return this->state == other.state;
    }

    State<T> *getCameFrom() const {
        return cameFrom;
    }

    bool operator>(const State<T> &other) const {
        return this->cost > other.cost;
    }

    bool operator<(const State<T> &other) const {
        return this->cost < other.cost;
    }

    bool operator!=(const State<T> &other) const {
        return !(*this == other);
    }

    T getState() const {
        return state;
    }

    double getCost() const {
        return cost;
    }

    void setManDist(const T &goal) {
        state.setManhattanDist(goal);
    }
};


#endif //SECONDYEARPROJECT_BIU_STATE_H