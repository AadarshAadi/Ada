#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to implement Bellman-Ford algorithm
void BellmanFord(int graph[], int n, int m, int source) {
    // Array to store the shortest path from the source
    int dist[n];
    
    // Initialize distances from source to all vertices as infinite
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[source] = 0; // Distance from source to itself is 0

    // Relax edges repeatedly
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            // Extract edge from graph
            int u = graph[j * 3];     // start vertex of edge
            int v = graph[j * 3 + 1]; // end vertex of edge
            int weight = graph[j * 3 + 2]; // weight of edge

            // If the path from u to v through this edge is shorter, update dist[v]
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < m; i++) {
        int u = graph[i * 3];  
        int v = graph[i * 3 + 1]; 
        int weight = graph[i * 3 + 2]; 
        
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    // Print the shortest distances from the source
    cout << "Vertex Distance from Source (" << source << "):\n";
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
    int n, m;

    // Take user input for the number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    int graph[m * 3]; // Array to store the edges in the form of (u, v, weight)

    // Take user input for the edges
    cout << "Enter the edges (u v weight) for each edge:\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[i * 3] = u;
        graph[i * 3 + 1] = v;
        graph[i * 3 + 2] = weight;
    }

    int source;
    // Take user input for the source vertex
    cout << "Enter the source vertex: ";
    cin >> source;

    // Call Bellman-Ford algorithm
    BellmanFord(graph, n, m, source);

    return 0;
}
