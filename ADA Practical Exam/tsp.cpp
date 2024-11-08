#include <iostream>
using namespace std;

const int INF = 99999;  // A large number to represent infinity

// Function to implement the greedy TSP algorithm
void tspGreedy(int graph[][4], int n) {
    bool visited[4] = {false};  // Array to track visited cities
    int totalCost = 0;

    int currentCity = 0;  // Start from the first city
    visited[currentCity] = true;
    cout << "Tour: " << currentCity;

    // Loop to visit all the cities
    for (int i = 0; i < n - 1; i++) {
        int nearestCity = -1;
        int minDistance = INF;

        // Find the nearest unvisited city
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[currentCity][j] < minDistance) {
                minDistance = graph[currentCity][j];
                nearestCity = j;
            }
        }

        // Move to the nearest city
        visited[nearestCity] = true;
        totalCost += minDistance;
        currentCity = nearestCity;
        cout << " -> " << currentCity;
    }

    // Return to the starting city to complete the tour
    totalCost += graph[currentCity][0];
    cout << " -> " << 0 << endl;

    cout << "Total Cost of the tour: " << totalCost << endl;
}

int main() {
    int n = 4;  // Number of cities

    // Adjacency matrix for the graph (distances between cities)
    int graph[4][4];

    // User input for the distance matrix
    cout << "Enter the distances between the cities (4x4 matrix):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Distance from city " << i << " to city " << j << ": ";
            cin >> graph[i][j];
        }
    }

    // Call the TSP function
    tspGreedy(graph, n);

    return 0;
}
