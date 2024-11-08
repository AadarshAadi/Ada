#include <iostream>

using namespace std;

struct Job {
    int id;       
    int deadline; 
    int profit;  
};

void swap(Job &a, Job &b) {
    Job temp = a;
    a = b;
    b = temp;
}


void JobsByProfit(Job arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].profit < arr[j].profit) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int jobSeq(Job arr[], int n) {
    
    JobsByProfit(arr, n);

    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > maxDeadline) {
            maxDeadline = arr[i].deadline;
        }
    }
    int slots[maxDeadline + 1]; 
    for (int i = 0; i <= maxDeadline; i++) {
        slots[i] = -1; 
    }

    int totalProfit = 0;

    
    for (int i = 0; i < n; i++) {
        
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slots[j] == -1) { 
                slots[j] = arr[i].id; 
                totalProfit += arr[i].profit; 
                break; 
            }
        }
    }

    return totalProfit;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    cout << "Enter the job details (ID, Deadline, Profit) for each job:\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> arr[i].id;
        cout << "Deadline: ";
        cin >> arr[i].deadline;
        cout << "Profit: ";
        cin >> arr[i].profit;
    }

    int maxProfit = jobSeq(arr, n);
    cout << "\nThe maximum profit is " << maxProfit << endl;

    return 0;
}