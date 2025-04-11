#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<bool>> matrix;
    int vertices;

public:
    Graph(int vertices);

    void addEdge(int i, int j);

    void displayGraph();

    vector<vector<bool>> getMatrix();
};

#endif
