// GRAPH OBJECT STRUCTURE, OMIT THIS IS NOT A CS COURSE

#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int vertices) : vertices(vertices) {
    matrix.resize(vertices, vector<bool>(vertices, false));
}

void Graph::addEdge(int i, int j) {
    matrix[i][j] = true;
    matrix[j][i] = true;
}

void Graph::displayGraph() {
    cout << "Graph displayed as matrix" << endl;

    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (bool val : matrix[i]) {
            cout << (val ? 1 : 0) << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

vector<vector<bool>> Graph::getMatrix() {
    return matrix;
}