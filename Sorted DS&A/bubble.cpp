#include<bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for(i = 0; i < n-1; i++){
        swapped = false;
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){

    int arr[10000];
    for(int i = 0; i < 10000; i++)
        arr[i] = rand() % 10000;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Unsorted array: " << endl;
    printArray(arr, n);
    bubbleSort(arr, n);
    cout << "Sorted array: " << endl;
    printArray(arr, n);
    return 0;

}