//
// Created by aviv on 12/18/18.
//

#ifndef SECONDYEARPROJECT_BIU_SYMBOLTABLE_H
#define SECONDYEARPROJECT_BIU_SYMBOLTABLE_H

#endif //SECONDYEARPROJECT_BIU_SYMBOLTABLE_H

#include "map"

static std::map<std::string, double> table;

class SymbolTable {
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

    /**
     * @param key key
     * @return true if table[key] exists, else false
     */
    static inline bool atTable(const std::string &key) {
        return table.find(key) != table.end();
    }
};