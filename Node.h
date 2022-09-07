#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <unordered_map>

using namespace std;

class Node
{
private:
    string word;
    unordered_map<string, Node*> neighbors;
public:
    Node(string word);
    ~Node();
    string getWord() const;
    unordered_map<string, Node*> getNeighbors() const;
    bool operator==(const Node& other) const;
    bool operator!=(const Node& other) const;
    bool operator<(const Node& other) const;
    bool operator>(const Node& other) const;
    bool addNeighbor(Node* other, bool mirror = true);
};

#endif