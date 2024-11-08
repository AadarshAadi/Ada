#include <iostream>
using namespace std;

struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};


float calculateBound(int level, int profit, int weight, int W, int weights[], int profits[], int n) {
    if (weight >= W) {
        return 0;
    }

    float bound = profit;
    int j = level + 1;
    int totalWeight = weight;

    
    while (j < n && totalWeight + weights[j] <= W) {
        totalWeight += weights[j];
        bound += profits[j];
        j++;
    }

    
    if (j < n) {
        bound += (W - totalWeight) * ((float)profits[j] / weights[j]);
    }

    return bound;
}


void knapsackBranchAndBound(int level, int profit, int weight, int &maxProfit, int W, int weights[], int profits[], int n) {
    
    if (level == n) {
        return;
    }

    
    float bound = calculateBound(level, profit, weight, W, weights, profits, n);

    
    if (bound <= maxProfit) {
        return;
    }

    
    if (weight + weights[level] <= W) {
        
        int newProfit = profit + profits[level];
        int newWeight = weight + weights[level];
        
        
        if (newProfit > maxProfit) {
            maxProfit = newProfit;
        }

        
        knapsackBranchAndBound(level + 1, newProfit, newWeight, maxProfit, W, weights, profits, n);
    }

    
    knapsackBranchAndBound(level + 1, profit, weight, maxProfit, W, weights, profits, n);
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    int weights[n], profits[n];

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)profits[i] / weights[i] < (float)profits[j] / weights[j]) {
                swap(profits[i], profits[j]);
                swap(weights[i], weights[j]);
            }
        }
    }

    int maxProfit = 0;
    knapsackBranchAndBound(0, 0, 0, maxProfit, W, weights, profits, n);

    cout << "Maximum profit in Knapsack = " << maxProfit << endl;
    return 0;
}
