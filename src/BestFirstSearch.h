//
// Created by aviv on 1/3/19.
//

#ifndef SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H
#define SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H

#include <queue>
#include <algorithm>
#include "Searcher.h"
template<typename T>
class custom_priority_queue : public std::priority_queue<T, std::vector<T>, greater<T>>
{
public:
    const T& remove(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return *it;
        }
    }
    bool atQueue(const T& value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        return it != this->c.end();
    }
};
namespace server_side {
    namespace algorithm {
        template<class T>
        class BestFirstSearch : public Searcher<T> {
            custom_priority_queue<problem::State<T>> priorityQueue;
        public:
            inline BestFirstSearch() {}

            int openListSize();

            problem::State<T> popOpenList();

            problem::Solution search(problem::ISearchable<T> *searchable);

        };
    }
}

#endif //SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H
