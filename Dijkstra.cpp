#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

void Dijkstra(int graph[][10], int n, int src) {
    int dist[n];  // Array to store shortest distances
    bool visited[n];  // To track visited vertices

    // Initialize distances and visited array
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Find the minimum distance vertex from the set of vertices not yet processed
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;

        // Update the distance of the adjacent vertices of the selected vertex
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distance from the source vertex to all other vertices
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
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

    // Run Dijkstra's algorithm
    Dijkstra(graph, n, src);

    return 0;
}
