#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

void Prims(int graph[][10], int n) {
    int parent[n];  // To store the constructed MST
    int key[n];     // To store the minimum weight edge
    bool mstSet[n]; // To check if a vertex is included in MST

    // Initialize all key values to infinity and mstSet[] as false
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // First vertex is selected as the root
    key[0] = 0;
    parent[0] = -1;

    // Find the MST
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        mstSet[u] = true;

        // Update the key value and parent index of the adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int n;

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

    // Run Prim's algorithm
    Prims(graph, n);

    return 0;
}
