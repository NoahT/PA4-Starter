#include "Set.h"

/**
 * Implement the HashTableSet methods correctly
 */
unsigned int HashTableSet::size() {
    return this->ht.size();
}

void HashTableSet::insert(string s) {
    this->ht.insert(s);
}

void HashTableSet::remove(const string & s) {
    this->ht.erase(s);
}

bool HashTableSet::find(const string & s) {
    unordered_set<string>::iterator iter = this->ht.find(s);

    return iter != (this->ht.end());
}
