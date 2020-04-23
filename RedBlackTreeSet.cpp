#include "Set.h"

/**
 * Implement the RedBlackTreeSet methods correctly
 */
unsigned int RedBlackTreeSet::size() {
    return this->rbt.size();
}

void RedBlackTreeSet::insert(string s) {
    if(!this->find(s)) {
        this->rbt.insert(s);
    }
}

void RedBlackTreeSet::remove(const string & s) {
    set<string>::iterator iter = this->rbt.begin();

    while(iter != this->rbt.end()) {
        if(*iter == s) {
            this->rbt.erase(iter);
            break;
        }

        iter++;
    }
}

bool RedBlackTreeSet::find(const string & s) {
    set<string>::iterator iter = this->rbt.begin();

    while(iter != this->rbt.end()) {
        if(*iter == s) {
            return true;
        }

        iter++;
    }
    
    return false;
}
