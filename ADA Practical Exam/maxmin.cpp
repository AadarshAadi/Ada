#include<iostream>
using namespace std;

void MaxMin(int arr[], int j, int i, int &max, int &min){
    if(i == j){

        max=min=arr[i];
    }
    else if(i==j - 1){
        if(arr[i] < arr[j]){
            max = arr[j];
            min = arr[i];
        }
        else{
            max = arr[i];
            min = arr[j];
        }

    }
    else {
        int mid = (i+j)/2;
        int max1; 
        int min1;
        MaxMin(arr,i,mid,max,min);
        MaxMin(arr,mid+1,j,max1,min1);
        if(max<max1)max = max1;
        if(min>min1)min = min1;

    }

    }
    

int main(){

    int n;
    cout << "Enter the Size of Array: ";
    cin >> n;

    cout << "\nEnter the Array for Max and Min \n";
    int *arr =new int[n];

    for (int i = 0; i < n; i++) {    
        cin >> arr[i];
    }

    int max, min;
    MaxMin(arr, 0, n - 1, max, min);

    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;


    return 0;
}