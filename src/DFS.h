//
// Created by aviv on 1/5/19.
//

#ifndef SECONDYEARPROJECT_BIU_DFS_H
#define SECONDYEARPROJECT_BIU_DFS_H

#include "Searcher.h"
#include "stack"
#include "map"

namespace server_side {
    namespace algorithm {
        template<class T>
        class DFS : public Searcher<T> {
            stack<problem::State<T>> stack1;
        public:
            inline DFS() {}

            int openListSize();

            problem::State<T> popOpenList();

            problem::Solution search(problem::ISearchable<T> *searchable);
        };
    }
}


#endif //SECONDYEARPROJECT_BIU_DFS_H
