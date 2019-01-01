//
// Created by aviv on 1/1/19.
//

#ifndef SECONDYEARPROJECT_BIU_STATE_H
#define SECONDYEARPROJECT_BIU_STATE_H

template<class T>
class State {
    T state;
    double cost;
    State<T> cameFrom;
public:
    State(T state);

    void setCost(double cost);

    void setCameFrom(State<T> cameFrom);

    bool operator==(State<T> other);
};


#endif //SECONDYEARPROJECT_BIU_STATE_H
