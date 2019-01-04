//
// Created by aviv on 1/3/19.
//

#ifndef SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H
#define SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H

#include <queue>
#include "Searcher.h"

namespace server_side {
    namespace algorithm {
        template<class T>
        class BestFirstSearch : public Searcher<problem::State<T>> {
        private:
            priority_queue<problem::State<T>, problem::State<T>, greater<State<T>>> priorityQueue;
        public:
            int openListSize() override;

            problem::State<T> popOpenList() override;

            problem::Solution solve(problem::ISearchable<T> *searchable) override;

        };
    }
}

#endif //SECONDYEARPROJECT_BIU_BESTFIRSTSEARCH_H
