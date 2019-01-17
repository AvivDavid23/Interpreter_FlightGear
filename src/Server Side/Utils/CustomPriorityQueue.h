//
// Created by aviv on 1/10/19.
//

#ifndef SECONDYEARPROJECT_BIU_CUSTOM_PRIORITY_QUEUE_H
#define SECONDYEARPROJECT_BIU_CUSTOM_PRIORITY_QUEUE_H

#include <algorithm>
#include <vector>
#include "queue"

/**
 * A priority queue with additional functions and a given comparator
 * @tparam T type of object
 * @tparam Compare comparator
 */
template<class T, class Compare>
class CustomPriorityQueue : public std::priority_queue<T, std::vector<T>, Compare> {
public:
    /**
     * @param value
     * @return element with the value of 'value'
     */
    T remove(const T &value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            T st = *it;
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return st;
        }
    }

/**
 * @param value
 * @return true if value is in queue, else false
 */
    bool atQueue(const T &value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        return it != this->c.end();
    }
};

#endif //SECONDYEARPROJECT_BIU_CUSTOM_PRIORITY_QUEUE_H
