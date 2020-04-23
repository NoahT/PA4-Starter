#include "Set.h"

/**
 * Implement the ArrayListSet methods correctly
 */
unsigned int ArrayListSet::size() {
    return this->arr.size();
}

void ArrayListSet::insert(string s) {
    if(!this->find(s)) {
        this->arr.push_back(s);
    }
}

void ArrayListSet::remove(const string & s) {
    vector<string>::iterator iter = this->arr.begin();
    
    // sets do not have duplicate elements. IF we find the
    // element we are done iterating.
    while(iter != this->arr.end()) {
        if(*iter == s) {
            this->arr.erase(iter);
            break;
        }
    }
}

bool ArrayListSet::find(const string & s) {
    vector<string>::iterator iter = this->arr.begin();

    while(iter != this->arr.end()) {
        if(*iter == s) {
            return true;
        }
        iter++;
    }

    return false;
}
