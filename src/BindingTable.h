//
// Created by aviv on 12/18/18.
//

#ifndef SECONDYEARPROJECT_BIU_BINDINGTABLE_H
#define SECONDYEARPROJECT_BIU_BINDINGTABLE_H

#include <map>

/**
 * A table which hold a string which maps to its path in the simulator
 */
 static std::map<std::string, std::string> Bindtable;
 class BindingTable{
 public:
     /**
     * Set a value in the table
     * @param key key
     * @param val val
     */
     static inline void setValue(const std::string &key, const std::string& val) {
         Bindtable[key] = val;
     }

     /**
      *
      * @param key key
      * @return table[key]
      */
     static inline std::string getValue(const std::string &key) {
         return Bindtable[key];
     }

     /**
      * @param key key
      * @return true if table[key] exists, else false
      */
     static inline bool atTable(const std::string &key) {
         return Bindtable.find(key) != Bindtable.end();
     }
 };
#endif //SECONDYEARPROJECT_BIU_BINDINGTABLE_H
