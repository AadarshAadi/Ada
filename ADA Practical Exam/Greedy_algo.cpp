#include <iostream>
using namespace std;

struct Item {
    int value;
    int weight;
};


double fractionalKnapsack(int capacity, Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio1 = (double)items[i].value / items[i].weight;
            double ratio2 = (double)items[j].value / items[j].weight;
            if (ratio1 < ratio2) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    double totalValue = 0.0; 

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break; 
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;

    
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    
    double maxValue = fractionalKnapsack(capacity, items, n);

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
