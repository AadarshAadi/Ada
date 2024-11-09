#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r){

    int n1 = mid - l +1;
    int n2 = r - mid;

    int a[n1];
    int b[n2]; //temp arrays

        for(int i=0;i<n1;i++){
            a[i]=arr[l+i];
        }

        for(int i=0;i<n2;i++){
            b[i]=arr[mid + 1 +i];
        }

        int i=0;
        int j=0;
        int k=l;

        while(i<n1 && j<n2){
            if(a[i] < b[j]){
                arr[k]=a[i];
                k++; i++;
            }
            else {
                arr[k]=b[j];
                k++; j++;

            }
    }

    while(i<n1){
       arr[k]=a[i];
        k++; i++; 

    }

     while(j<n2){
       arr[k]=b[j];
        k++; j++; 

    }
             
}

void mergeSort(int arr[], int l, int r) {

if (l < r){

    int mid = (l + r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);

    merge (arr,l,mid,r);

}


}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j]=temp;
}

int partition(int arr[], int l, int r){

    int pivot=arr[r];
    int i=l-1;

    for(int j=1;j<r;j++){

        if (arr[j]<pivot){
        i++;
        swap(i,j);
    }
    swap (arr,i+1,r);
    return i+1;
    }
}

void quickSort(int arr[], int l, int r){

    if (l < r){

        int pi = partition(arr,l,r);

        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }

}



int main(){

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
    cout << "1. Merge Sort\n";
    cout << "2. Quick Sort\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
    case 1:
    quickSort(arr, 0, n-1);
    cout << "\nArray after Quick Sort:\n";
    break;

    case 2:
    mergeSort(arr, 0, n-1);
    cout << "\nArray after Merge Sort:\n";
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