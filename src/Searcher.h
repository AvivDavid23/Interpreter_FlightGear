//
// Created by aviv on 1/3/19.
//

#ifndef SECONDYEARPROJECT_BIU_SEARCHER_H
#define SECONDYEARPROJECT_BIU_SEARCHER_H
/**
 * Searcher abstract class
 */
#include "Solution.h"
#include "ISearchable.h"
#include "ISearcher.h"

using namespace std;
using namespace server_side::algorithm;
using namespace server_side::problem;
namespace server_side {
    namespace algorithm {
        template<class T>
        class Searcher : public algorithm::ISearcher<T> {
        protected:
            int nodesEvaluated;
        public:
            inline Searcher() : nodesEvaluated(0) {}

            virtual int openListSize() = 0;

            virtual problem::State<T> popOpenList() = 0;

            inline int getEvaluatedNodes() { return nodesEvaluated; }
        };
    }
}
#endif //SECONDYEARPROJECT_BIU_SEARCHER_H
