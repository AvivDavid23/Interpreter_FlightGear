//
// Created by aviv on 1/1/19.
//

#ifndef SECONDYEARPROJECT_BIU_STATE_H
#define SECONDYEARPROJECT_BIU_STATE_H



template<class T>
class State {
    T state;
    double cost = 0;
    State<T> *cameFrom = nullptr;
public:
    State() {}

    State(T state) : state(state) {}

    State(const State<T>& other){
        state = other.state;
        cost = other.cost;
        if (other.cameFrom != nullptr){
            cameFrom = new State<T>();
            *cameFrom = *other.cameFrom;
        }
    }

    ~State() {
        //delete cameFrom;
    }

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
};


#endif //SECONDYEARPROJECT_BIU_STATE_H
