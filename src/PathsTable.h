//
// Created by aviv on 12/18/18.
//

#ifndef SECONDYEARPROJECT_BIU_PATHSTABLE_H
#define SECONDYEARPROJECT_BIU_PATHSTABLE_H

#include "map"
static std::map<std::string, double> table;

class PathsTable {
public:
    /**
     * Set a value in the table
     * @param key key
     * @param val val
     */
    static inline void setValue(const std::string &key, double val) {
        table[key] = val;
    }

    /**
     *
     * @param key key
     * @return table[key]
     */
    static inline double getValue(const std::string &key) {
        return table[key];
    }
};
#endif //SECONDYEARPROJECT_BIU_PATHSTABLE_H
