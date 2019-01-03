//
// Created by aviv on 1/3/19.
//

#ifndef SECONDYEARPROJECT_BIU_ISEARCHER_H
#define SECONDYEARPROJECT_BIU_ISEARCHER_H

#include "ISearchable.h"
#include "Solution.h"
/**
 * Searcher interface
 */
namespace server_side {
    namespace algorithm {
        template<class T>
        class ISearcher {
            virtual problem::Solution search(problem::ISearchable<T> *searchable) = 0;
        };
    }
}
#endif //SECONDYEARPROJECT_BIU_ISEARCHER_H
