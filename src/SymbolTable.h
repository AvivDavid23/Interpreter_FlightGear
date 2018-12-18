//
// Created by aviv on 12/18/18.
//

#ifndef SECONDYEARPROJECT_BIU_SYMBOLTABLE_H
#define SECONDYEARPROJECT_BIU_SYMBOLTABLE_H


#include "map"

/**
 * A tables which hold our vars values
 */


class SymbolTable {
    std::map<std::string, double> symTable;
    static SymbolTable *s_instance;
public:
    static inline SymbolTable *instance() {
        if (!s_instance) s_instance = new SymbolTable;
        return s_instance;
    }

    /**
     * Set a value in the table
     * @param key key
     * @param val val
     */
    inline void setValue(const std::string &key, double val) {
        symTable[key] = val;
    }

    /**
     *
     * @param key key
     * @return table[key]
     */
    inline double getValue(const std::string &key) {
        return symTable[key];
    }

    /**
     * @param key key
     * @return true if table[key] exists, else false
     */
    inline bool atTable(const std::string &key) {
        return symTable.find(key) != symTable.end();
    }

    inline std::map<std::string, double> getTable() {
        return symTable;
    }
};
#endif //SECONDYEARPROJECT_BIU_SYMBOLTABLE_H