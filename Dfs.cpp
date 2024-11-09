#include <iostream>
using namespace std;

void DFSUtil(int graph[][10], int n, int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    // Explore all adjacent vertices of v
    for (int i = 0; i < n; i++) {
        if (graph[v][i] != 0 && !visited[i]) {
            DFSUtil(graph, n, i, visited);
        }
    }
}

void DFS(int graph[][10], int n, int src) {
    bool visited[n];  // To track visited vertices
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    cout << "DFS starting from vertex " << src << ": ";
    DFSUtil(graph, n, src, visited);
    cout << endl;
}

int main() {
    int n, src;

    // Input number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[10][10]; // Graph can hold up to 10 vertices

    // Input the adjacency matrix for the graph
    cout << "Enter the adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Input the source vertex
    cout << "Enter the source vertex: ";
    cin >> src;

    // Run DFS
    DFS(graph, n, src);

    return 0;
}
