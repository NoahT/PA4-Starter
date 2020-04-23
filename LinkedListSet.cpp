#include "Set.h"

/**
 * Implement the LinkedListSet methods correctly
 */
unsigned int LinkedListSet::size() {
    return this->linked.size();
}

void LinkedListSet::insert(string s) {
    if(!this->find(s)) {
        this->linked.push_back(s);
    }
}

void LinkedListSet::remove(const string & s) {
    list<string>::iterator iter = this->linked.begin();

    while(iter != this->linked.end()) {
        if(*iter == s) {
            this->linked.erase(iter);
            break;
        }

        iter++;
    }
}

bool LinkedListSet::find(const string & s) {
    list<string>::iterator iter = this->linked.begin();

    while(iter != this->linked.end()) {
        if(*iter == s) {
            return true;
        }

        iter++;
    }

    return false;
}
