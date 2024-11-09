#include <iostream>
#include <queue>
using namespace std;

void BFS(int graph[][10], int n, int src) {
    bool visited[n];  // To track visited vertices
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    queue<int> q;  // Queue for BFS
    visited[src] = true;
    q.push(src);

    cout << "BFS starting from vertex " << src << ": ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        // Explore all adjacent vertices of u
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
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

    // Run BFS
    BFS(graph, n, src);

    return 0;
}
