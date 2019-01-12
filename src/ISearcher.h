//
// Created by aviv on 1/3/19.
//

#ifndef SECONDYEARPROJECT_BIU_ISEARCHER_H
#define SECONDYEARPROJECT_BIU_ISEARCHER_H

#include "ISearchable.h"

/**
 * Searcher interface
 */

template<class T, class Solution>
class ISearcher {
    // search for a solution to the Searchable object
    virtual Solution search(ISearchable<T, Solution> *searchable) = 0;
};

#endif //SECONDYEARPROJECT_BIU_ISEARCHER_H
