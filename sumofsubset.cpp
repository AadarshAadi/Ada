#include <iostream>
using namespace std;

// Function to find all subsets that sum to the target value using backtracking
void findSubsetSum(int arr[], int n, int target, int subset[], int currentSum, int index) {
    // Base case: if current sum is equal to the target
    if (currentSum == target) {
        // Print the subset
        cout << "{ ";
        for (int i = 0; i < index; i++) {
            cout << subset[i] << " ";
        }
        cout << "}\n";
        return;
    }

    // If we have considered all elements, return
    if (index == n) {
        return;
    }

    // Include the current element and check for the next elements
    subset[index] = arr[index];
    findSubsetSum(arr, n, target, subset, currentSum + arr[index], index + 1);

    // Backtrack: remove the last element and check without including it
    findSubsetSum(arr, n, target, subset, currentSum, index + 1);
}

int main() {
    int n, target;

    // Take user input for the size of the array and the target sum
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    
    // Take user input for the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Take user input for the target sum
    cout << "Enter the target sum: ";
    cin >> target;

    int subset[n]; // Array to store the current subset

    cout << "Subsets whose sum is " << target << " are: \n";
    findSubsetSum(arr, n, target, subset, 0, 0);

    return 0;
}
