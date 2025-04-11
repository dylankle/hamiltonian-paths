#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

void findHamiltonianPaths(Graph& graph, vector<vector<bool>>& matrix, vector<int>& path, vector<bool>& visited, int current, int totalVertices) {
    if (path.size() == totalVertices) {
        for (int subPath : path)
            cout << subPath << " ";
        cout << endl;
        return;
    }

    for (int next = 0; next < totalVertices; next++) {
        if (!visited[next] && matrix[current][next]) {
            visited[next] = true;
            path.push_back(next);
            findHamiltonianPaths(graph, matrix, path, visited, next, totalVertices);
            visited[next] = false;
            path.pop_back();
        }
    }
}

int main() {
    const int VERTICES = 5;
    Graph g(VERTICES);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.displayGraph();

    vector<vector<bool>> matrix = g.getMatrix();
    for (int start = 0; start < VERTICES; start++) {
        vector<bool> visited(VERTICES, false);
        vector<int> path = {start};
        visited[start] = true;

        cout << "Hamiltonian paths starting at vertex " << start << ":\n";
        findHamiltonianPaths(g, matrix, path, visited, start, VERTICES);
    }

    return 0;
}
