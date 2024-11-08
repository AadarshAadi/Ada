#include <iostream>
#include <climits>
using namespace std;

// Function to calculate the minimum cost of visiting all cities using DP
int tsp(int graph[10][10], int n, int mask, int pos, int dp[1025][10]) {
    // If all cities are visited, return the distance to the start city
    if (mask == (1 << n) - 1) {
        return graph[pos][0];  // Return to the starting city
    }

    // If this subproblem has been solved already, return the stored result
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    // Try to go to every other city and calculate the minimum cost
    for (int city = 0; city < n; city++) {
        // If the city is not visited yet (check the bitmask)
        if ((mask & (1 << city)) == 0) {
            // Recur to visit the next city with the updated mask
            int newAns = graph[pos][city] + tsp(graph, n, mask | (1 << city), city, dp);
            ans = min(ans, newAns);
        }
    }

    // Store the result in the dp table
    dp[mask][pos] = ans;
    return ans;
}

int main() {
    // Input number of cities
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    // Input the adjacency matrix (graph) for the distances between cities
    int graph[10][10];
    cout << "Enter the adjacency matrix (distances between cities):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Initialize DP table with -1 (indicating unvisited states)
    int dp[1025][10];
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;  // Mark all states as unvisited initially
        }
    }

    // Find the minimum cost to visit all cities
    int minCost = tsp(graph, n, 1, 0, dp);  // Start from city 0 with only city 0 visited (mask = 1)

    // Output the minimum cost of the tour
    cout << "Minimum cost of the tour: " << minCost << endl;

    return 0;
}
