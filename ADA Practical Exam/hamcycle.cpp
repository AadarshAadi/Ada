#include <iostream>
using namespace std;

// Define the number of vertices in the graph
const int V = 5; // You can modify this based on your graph size

// Function to check if the current vertex can be added to the Hamiltonian cycle
bool isSafe(int v, int graph[V][V], int path[], int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }

    // Check if the vertex has already been included in the cycle
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

// Utility function to solve the Hamiltonian Cycle problem using backtracking
bool hamiltonianCycleUtil(int graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the cycle
    if (pos == V) {
        // Check if there is an edge from the last vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        }
        return false;
    }

    // Try different vertices as the next candidate in the Hamiltonian cycle
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamiltonianCycleUtil(graph, path, pos + 1)) {
                return true;
            }

            // If adding vertex v doesn't lead to a solution, backtrack
            path[pos] = -1;
        }
    }

    return false;
}

// Function to solve the Hamiltonian Cycle problem
bool hamiltonianCycle(int graph[V][V]) {
    int path[V];

    // Initialize the path with -1 (no vertices are visited)
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }

    // Start with the first vertex
    path[0] = 0;

    // Call the recursive function to solve the problem
    if (hamiltonianCycleUtil(graph, path, 1)) {
        // If a Hamiltonian cycle exists, print the cycle
        cout << "Hamiltonian Cycle found: ";
        for (int i = 0; i < V; i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << endl; // Close the cycle by returning to the starting vertex
        return true;
    }

    cout << "No Hamiltonian Cycle exists." << endl;
    return false;
}

int main() {
    // Define the graph using an adjacency matrix
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    // Call the function to check if a Hamiltonian cycle exists
    hamiltonianCycle(graph);

    return 0;
}
