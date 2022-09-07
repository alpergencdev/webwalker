#ifndef __GRAPH_H
#define __GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Node.h"

using namespace std;
class Graph
{
private:
    unordered_map<string, Node*> nodes;
    void generateNodes(vector<string>& wordList);
    void generateNeighborLinks();
public:
    Graph(vector<string>& wordList);
    string printStatus();
    vector<string> shortestPath(string src, string dst) const;
    ~Graph();
};

#endif
