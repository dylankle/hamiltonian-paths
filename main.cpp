// HAMILTONIAN PATH LOGIC FOUND IN THIS FILE

#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

//algorithm for finding hamiltonian paths. we take the matrix data, temp path, temp visited list, current vertex, and graph size
void findHamiltonianPaths(Graph& graph, vector<vector<bool>>& matrix, vector<int>& path, vector<bool>& visited, int current, int totalVertices) {
    if (path.size() == totalVertices) { //if the temp path is the length of graph size, then the algorithm function ends
        for (int subPath : path)
            cout << subPath << " ";
        cout << endl;
        return;
    }

    for (int next = 0; next < totalVertices; next++) {
        if (!visited[next] && matrix[current][next]) { //if it hasn't been visited and an edge exists, then start a subpath based on the vertex of focus
            visited[next] = true; //current vertex visited
            path.push_back(next); //push the vertex into the list
            findHamiltonianPaths(graph, matrix, path, visited, next, totalVertices); //function with algorithm call with current vertex
            visited[next] = false; //after it ultimately finishes without reaching the graph size, current vertex is not visited for future paths
            path.pop_back(); //remove the vertex from the list, so it can check new paths
        }
    }
}

int main() {
    const int VERTICES = 5; //number of vertices in the graph
    Graph g(VERTICES); //initialize graph size

    //adding edges
    g.addEdge(0, 1); //vertex 0 is connected to 1
    g.addEdge(0, 3); //vertex 0 is connected to 3
    g.addEdge(1, 2); //vertex 1 is connected to 2
    g.addEdge(1, 3); //vertex 1 is connected to 3
    g.addEdge(2, 4); //vertex 2 is connected to 4
    g.addEdge(3, 4); //vertex 3 is connected to 4

    g.displayGraph();

    vector<vector<bool>> matrix = g.getMatrix(); //stores g matrix attribute in safe copy
    for (int start = 0; start < VERTICES; start++) { //checks Hamiltonian paths from each every vertex
        vector<bool> visited(VERTICES, false); //temporary list of all vertices, and if they've been vistied yet
        vector<int> path = {start}; //temporary list of the current Hamiltonian path being built
        visited[start] = true; //vertex we're starting on has been visited of course

        cout << "Hamiltonian paths starting at vertex " << start << ":\n";
        findHamiltonianPaths(g, matrix, path, visited, start, VERTICES); //function with algorithm call
        cout << endl;
    }

    return 0;
}
