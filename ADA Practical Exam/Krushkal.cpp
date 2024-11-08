#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

struct Edge {
    int u, v, weight;
};

// Function to find the parent of a node (for union-find)
int findParent(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return findParent(parent, parent[i]);
}

// Function to perform the union of two subsets
void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void Kruskal(int graph[][10], int n, int m) {
    Edge edges[m];

    // Convert the adjacency matrix into an edge list
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                edges[k].u = i;
                edges[k].v = j;
                edges[k].weight = graph[i][j];
                k++;
            }
        }
    }

    // Sort the edges based on their weight
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (edges[i].weight > edges[j].weight) {
                swap(edges[i], edges[j]);
            }
        }
    }

    int parent[n], rank[n];

    // Initialize parent and rank arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    cout << "Edge \tWeight\n";
    int e = 0;  // Count of edges in the MST
    int i = 0;  // Initial edge index
    while (e < n - 1) {
        Edge nextEdge = edges[i++];
        int x = findParent(parent, nextEdge.u);
        int y = findParent(parent, nextEdge.v);

        // If including this edge doesn't cause a cycle
        if (x != y) {
            cout << nextEdge.u << " - " << nextEdge.v << " \t" << nextEdge.weight << endl;
            unionSets(parent, rank, x, y);
            e++;
        }
    }
}

int main() {
    int n, m;

    // Input number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    int graph[10][10]; // Graph can hold up to 10 vertices

    // Input the adjacency matrix for the graph
    cout << "Enter the adjacency matrix (use 0 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Run Kruskal's algorithm
    Kruskal(graph, n, m);

    return 0;
}
