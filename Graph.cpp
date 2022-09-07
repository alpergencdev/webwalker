#include "Graph.h"
#include <string>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;
Graph::Graph(vector<string>& wordList) {
    this->nodes = unordered_map<string, Node*>();
    generateNodes(wordList);
    generateNeighborLinks();
}


void Graph::generateNodes(vector<string>& wordList) {
    for(auto iterator = wordList.begin(); iterator != wordList.end(); iterator++) {
        string curWord = (*iterator);
        Node* curNode = new Node(curWord);
        nodes.insert(std::make_pair(curWord, curNode));
    }
}

void Graph::generateNeighborLinks() {
    for(auto iterator = nodes.begin(); iterator != nodes.end(); iterator++) {
        Node* curNode = (*iterator).second;
        string curWord = (*iterator).first;

        // for each letter in the string, check all possible letter that might come
        // in its place, check if it forms a word in the wordlist, and if so,
        // add them as neighbors.
        for(int i = 0; i < curWord.length(); i++) {
            for(char ch = 'a'; ch <= 'z'; ch++) {
                if( ch != curWord[i]) {
                    string newWord = curWord;
                    newWord[i] = ch;
                    auto node_it = nodes.find(newWord);
                    if( node_it != nodes.end()) {
                        Node* neighborNode = (*node_it).second;
                        curNode->addNeighbor(neighborNode);
                    }
                }
                
            }
        }
    }
}

Graph::~Graph() {}

string Graph::printStatus() {
    string result = "";
    for( auto it = nodes.begin(); it != nodes.end(); it++) {
        Node* curNode = (*it).second;
        string curWord = (*it).first;
        result += "Node with word " + curWord + '\n';
        unordered_map<string, Node*> neighbors = curNode->getNeighbors();
        std::cout << "neighbors size for " << curNode->getWord() << ": " << neighbors.size() << std::endl;
        if( neighbors.size() > 0) {
            result += "Neighbors:\n";
            for(auto it2 = neighbors.begin(); it2 != neighbors.end(); it2++) {
                result += "- " + (*it2).first + '\n'; 
            }
        }
        result += "---------------\n";
    }
    return result;
}



vector<string> Graph::shortestPath(string src, string dst) const {
    struct QueueItem {
        vector<string> path;
        Node* current;
        QueueItem(vector<string> path, Node* current) {
            this->path = path;
            this->current = current;
        }
    };
    queue<QueueItem> q;
    unordered_set<string> visited;
    q.push(QueueItem(vector<string>(), (nodes.find(src))->second));

    while(!q.empty()) {
        QueueItem curItem = q.front();
        q.pop();
        Node* curNode = curItem.current;

        if( curNode->getWord() == dst) {
            vector<string> result = curItem.path;
            result.push_back(curNode->getWord());
            return result;
        }

        if( visited.find(curNode->getWord()) != visited.end()) {
            continue;
        }

        visited.insert(curNode->getWord());

        unordered_map<string, Node*> neighbours = curNode->getNeighbors();

        for( auto it = neighbours.begin(); it != neighbours.end(); it++) {
            Node* curNeighbor = (*it).second;
            if( visited.find((*it).first) == visited.end()) {
                vector<string> newVec = curItem.path;
                newVec.push_back(curNode->getWord());
                q.push(QueueItem(newVec, curNeighbor));
            }
        }
    }

    return vector<string>();
}