#include "Set.h"

void deleteNodes(MultiwayTrieSet::Node* current) {
    if(current != NULL) {
        // visit children before deleting self!
        for(pair<char, MultiwayTrieSet::Node*> child : current->children) {
            deleteNodes(child.second);
        }
        delete current;
    }
}

/**
 * Implement the MultiwayTrieSet constructor
 */
MultiwayTrieSet::MultiwayTrieSet() {
    this->root = new MultiwayTrieSet::Node();
}

/**
 * Implement the MultiwayTrieSet destructor
 */
MultiwayTrieSet::~MultiwayTrieSet() {
    deleteNodes(this->root);
}

/**
 * Implement the MultiwayTrieSet methods correctly
 */
unsigned int MultiwayTrieSet::size() {
    return this->numElements;
}

void MultiwayTrieSet::insert(string s) {
    Node* curr = this->root;
    string currString = s;
    char letter;

    // go through all characters until we successfully
    // complete the path defined by the given string
    while(currString.length() > 0) {
        letter = currString.at(0);

        auto iter = curr->children.find(letter);

        // edge DNE, we must create a new node
        if(iter == curr->children.end()) {
            curr->children[letter] = new Node();
        }

        curr = curr->children[letter];
        currString = currString.substr(1);
    }

    if(!curr->isWord) {
        curr->isWord = true;
        this->numElements++;
    }
}

void MultiwayTrieSet::remove(const string & s) {
    Node* curr = this->root;
    string currString = s;
    char letter;

    while(currString.length() > 0) {
        letter = currString.at(0);
        auto iter = curr->children.find(letter);

        if(iter == curr->children.end()) {
            break;
        }

        curr = curr->children[letter];
        currString = currString.substr(1);
    }

    if(currString.length() == 0 && curr->isWord) {
        curr->isWord = false;
        this->numElements--;
    }
}

bool MultiwayTrieSet::find(const string & s) {
    Node* curr = this->root;
    string currString = s;

    char letter;

    // check that we can traverse through MWT for each letter
    while(currString.length() > 0) {
        letter = currString.at(0);
        auto iter = curr->children.find(letter);
        //check if MWT has path for letter
        if(iter == curr->children.end()) {
            return false;
        }

        // follow edge to next node
        curr = curr->children[letter];
        // remove checked letter
        currString = currString.substr(1);
    }

    // we finished traversing the entire string. if the current node
    // is a word node then we are successful.
    return (curr->isWord);
}
