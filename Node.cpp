#include "Node.h"
#include <iostream>

Node::Node(string word) {
    this->word = word;
    this->neighbors = unordered_map<string, Node*>();
}

Node::~Node() {}

string Node::getWord() const {
    return this->word;
}

unordered_map<string, Node*> Node::getNeighbors() const {
    return this->neighbors;
}

bool Node::operator==(const Node& other) const {
    return this->word == other.word;
}

bool Node::operator!=(const Node& other) const {
    return !operator==(other);
}

bool Node::operator<(const Node& other) const {
    return this->word.compare(other.word) < 0;
}

bool Node::operator>(const Node& other) const {
    return this->word.compare(other.word) > 0;
}

bool Node::addNeighbor(Node* other, bool mirror) {
    if( other == NULL || this->word == other->word || this->neighbors.find(other->word) != this->neighbors.end()) {
        return false;
    }

    neighbors.insert(std::make_pair(other->word, other));
    other->neighbors.insert(std::make_pair(this->word, this));
    return true;
}