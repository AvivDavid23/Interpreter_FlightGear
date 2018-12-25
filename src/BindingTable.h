//
// Created by aviv on 12/18/18.
//

#ifndef SECONDYEARPROJECT_BIU_BINDINGTABLE_H
#define SECONDYEARPROJECT_BIU_BINDINGTABLE_H

#include <map>

/**
 * A table which hold a string which maps to its path in the simulator
 */

class BindingTable {
    std::map<std::string, std::string> bindTable;
    static BindingTable *s_instance;
public:
    static inline BindingTable *instance() {
        if (!s_instance){
            s_instance = new BindingTable();
        }
        return s_instance;
    }

    /**
    * Set a value in the table
    * @param key key
    * @param val val
    */
    inline void setValue(const std::string &key, const std::string &val) {
        bindTable[key] = val;
    }

    /**
     *
     * @param key key
     * @return table[key]
     */
    inline std::string getValue(const std::string &key) {
        return bindTable[key];
    }

    inline bool atTable(const std::string &key){
        return bindTable.find(key) != bindTable.end();
    }
};


#endif //SECONDYEARPROJECT_BIU_BINDINGTABLE_H
