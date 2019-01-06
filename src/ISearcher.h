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

template<class T>
class ISearcher {
    virtual server_side::problem::Solution search(ISearchable<T> *searchable) = 0;
};

#endif //SECONDYEARPROJECT_BIU_ISEARCHER_H
