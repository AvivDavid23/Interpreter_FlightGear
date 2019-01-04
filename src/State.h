//
// Created by aviv on 1/1/19.
//

#ifndef SECONDYEARPROJECT_BIU_STATE_H
#define SECONDYEARPROJECT_BIU_STATE_H
namespace server_side {
    namespace problem {
        template<class T>
        class State {
            T state;
            double cost = 0;
            State<T> *cameFrom = nullptr;
        public:
            State(T state);

            ~State();

            void setCost(double cost) const;

            void setCameFrom(State<T> cameFrom);

            bool operator==(const State<T> &other) const;

            bool operator>(const State<T> &other) const;

            bool operator<(const State<T> &other) const;

            T getState() const;

            double getCost() const;
        };
    }
}


#endif //SECONDYEARPROJECT_BIU_STATE_H
