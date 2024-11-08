#include<iostream>
using namespace std;

void bubbleSort(int *arr,int n){
    int x = 1;
    while (x < n) {
        for (int i = 0; i < n - x; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                
            }
        }
        x++;
    }
}

void insertionSort(int *arr,int n){
                for (int i = 1; i < n; i++) {
                int key = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
}

void selectionSort(int *arr,int n){

for(int i=0; i<n-1; i++) {
    int mininx= i;
        for (int j= i+1; j<n; j++) {
            if (arr[j]< arr[mininx]){
                mininx = j;

            }
        }

        swap(arr[i],arr[mininx]);
}

}

int main() {
    int n;
    cout << "Enter the Size of Array: ";
    cin >> n;

    cout << "\nEnter the Number to be Sorted:\n";
    int *arr =new int[n];

    for (int i = 0; i < n; i++) {    
        cin >> arr[i];
    }

    int choice;
    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "Enter choice (1,2 or 3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            cout << "\nArray after Bubble Sort:\n";
            break;
        case 2:
            insertionSort(arr, n);
            cout << "\nArray after Insertion Sort:\n";
            break;
        case 3:
            selectionSort(arr, n);
            cout << "\nArray after Selection Sort:\n";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}