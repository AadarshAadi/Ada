#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

void FloydWarshall(int graph[][10], int n) {
    // dist[][] will hold the shortest distance between every pair of vertices
    int dist[n][n];

    // Initialize the distance matrix same as the input graph matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0 && i != j)
                dist[i][j] = INT_MAX;  // Set the initial distance to infinity for non-adjacent nodes
            else
                dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;

    // Input number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10]; // Graph can hold up to 10 vertices, you can adjust the size if needed

    // Input the adjacency matrix
    cout << "Enter the adjacency matrix (use 0 for no edge and any positive number for edge weight):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Run Floyd-Warshall algorithm
    FloydWarshall(graph, n);

    return 0;
}
