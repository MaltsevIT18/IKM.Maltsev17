#ifndef TREE_H
#define TREE_H

#include <vector>
#include <unordered_map>
#include <iostream>
#include <stdexcept>
using namespace std;
class Nest {
    int number;
    int letterCount;
    vector<int> neighbors;
public:
    Nest(int num = 0, int letters = 0);
    void setLetterCount(int count);
    int getLetterCount() const;
    int getNumber() const;
    const vector<int>& getNeighbors() const;
    void addNeighbor(int neigh);
    friend ostream& operator<<(ostream& os, const Nest& nest);
};
class Tree {
    unordered_map<int, Nest> nests;
    int dfs(int current, int parent);
public:
    void addNest(const Nest& nest);
    void readFromStream(istream& is);
    int calculateExcuses();
};

#endif
