#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100; 


int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}


int optimalBST(int keys[], int freq[], int n) {
    int cost[MAX][MAX] = {0}; 

    
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);

                
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    
    return cost[0][n - 1];
}

int main() {
    int keys[MAX], freq[MAX], n;

    cout << "Enter the number of keys: ";
    cin >> n;

    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cout << "Enter the frequencies: ";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    cout << "Minimum cost of Optimal Binary Search Tree: " << optimalBST(keys, freq, n) << endl;

    return 0;
}
