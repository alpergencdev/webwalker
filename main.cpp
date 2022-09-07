#include "Node.h"
#include "Graph.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

using namespace std;

std::string ltrim(const std::string &s) {
    return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}
 
std::string rtrim(const std::string &s) {
    return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}
 
std::string trim(const std::string &s) {
    return ltrim(rtrim(s));
}

int main(int argc, char** argv) {
    if( argc != 4) {
        cout << "Correct usage: " << argv[0] << " <WORD_FILE_NAME> <SOURCE_WORD> <DESTINATION_WORD>" << endl;
        exit(1);
    }
    string wordFileName = argv[1];
    string srcWord = argv[2];
    string dstWord = argv[3];
    cout << "Reading word list..." << endl;
    ifstream wordListFile(wordFileName);
    if( !wordListFile) {
        cout << "An error occured while opening wordfile. Program will now exit." << std::endl;
        exit(1);
    }
    string curLine;
    vector<string> wordList;
    int wordLength = -1;
    while(getline(wordListFile, curLine)) {
        wordList.push_back(trim(curLine));
    }
    cout << "Word list read. Length: " << wordList.size() << endl;
    if( std::find(wordList.begin(), wordList.end(), srcWord) == wordList.end()) {
        cout << "Source word does not exist in word list. Program will now exit." << std::endl;
        exit(1);
    }

    if( std::find(wordList.begin(), wordList.end(), dstWord) == wordList.end()) {
        cout << "Destination word does not exist in word list. Program will now exit." << std::endl;
        exit(1);
    }
    cout << "Generating graph..." << endl;
    Graph g(wordList);
    cout << "Graph generated." << endl;

    std::cout << "Generating result..." << std::endl;
    vector<string> result = g.shortestPath(srcWord, dstWord);
    std::cout << "Result length: " << (result.size() - 1) << std::endl;
    for(int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if( i != result.size() - 1) {
            std::cout << " -> ";
        }
        else {
            std::cout << std::endl;
        }
    }

    return 0;
}