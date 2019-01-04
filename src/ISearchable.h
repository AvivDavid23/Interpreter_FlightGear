//
// Created by aviv on 1/3/19.
//

#ifndef SECONDYEARPROJECT_BIU_ISEARCHABLE_H
#define SECONDYEARPROJECT_BIU_ISEARCHABLE_H

#include "State.h"
#include "vector"

/**
 * Searchable interface
 */
namespace server_side {
    namespace problem {
        template<class T>
        class ISearchable {
        public:
            virtual State<T> getInitialState() = 0;

            virtual bool isGoalState(State<T> state) = 0;

            virtual std::vector<State<T>> getAllPossibleStates(State<T> state) = 0;

        };
    }
}


#endif //SECONDYEARPROJECT_BIU_ISEARCHABLE_H
