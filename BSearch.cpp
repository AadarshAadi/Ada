#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key){
    for (int i=0;i<n;i++){
       if(arr[i]==key){
            return i;
        }
    }
    return 0;
}


int binarySearch(int arr[], int n, int key){
    int s=0;
    int e=n;
    while(s<=e){
        int mid=(s+e)/2;

        if (arr[mid]==key){
            return mid;
        }
        else if (arr[mid]>key){
            e=mid-1;

        }
        else{
            s=mid+1;
        }
    }
 return 0;
}



int main(){

    int n;
    cout<<"Enter the Size of array:\n";
    cin>>n;

    int arr[n];
    cout<<"\nEnter the Number in the array:\n";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"\nEnter the number to be Searched:\n";
    cin>>key;

    int choice;
    cout << "\nChoose Searching Algorithm:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    switch (choice) {


        case 1:
        linearSearch(arr,n,key);
        cout<<"\nKey of the Number:";
        cout<<linearSearch(arr,n,key)<<endl;
        break;

        case 2:
        binarySearch(arr,n,key);
        cout<<"\nKey of the Number:";
        cout<<binarySearch(arr,n,key)<<endl;
        break;

        default:
        cout << "Invalid choice!" << endl;
        return 0;

    }   



    return 0;
}