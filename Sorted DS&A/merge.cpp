#include<bits/stdc++.h>

using namespace std;

void merge(int arr[], int const left, int const mid, int const right) {
    int subArr1 = mid - left + 1;
    int subArr2 = right - mid;
    int *leftArr = new int[subArr1],
            *rightArr = new int[subArr2];
    for (int i = 0; i < subArr1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < subArr2; j++)
        rightArr[j] = arr[mid + 1 + j];
    int indexOfSubArr1 = 0,
            indexOfSubArr2 = 0;
    int indexOfMergedArr = left;
    while (indexOfSubArr1 < subArr1 && indexOfSubArr2 < subArr2) {
        if (leftArr[indexOfSubArr1] <= rightArr[indexOfSubArr2]) {
            arr[indexOfMergedArr] = leftArr[indexOfSubArr1];
            indexOfSubArr1++;
        } else {
            arr[indexOfMergedArr] = rightArr[indexOfSubArr2];
            indexOfSubArr2++;
        }
        indexOfMergedArr++;
    }
    while (indexOfSubArr1 < subArr1) {
        arr[indexOfMergedArr] = leftArr[indexOfSubArr1];
        indexOfSubArr1++;
        indexOfMergedArr++;
    }
    while (indexOfSubArr2 < subArr2) {
        arr[indexOfMergedArr] = rightArr[indexOfSubArr2];
        indexOfSubArr2++;
        indexOfMergedArr++;
    }
}

void mergeSort(int arr[], int const begin, int const end) {
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    //insert 10
    int arr[10];
    for (int i = 0; i < 10; i++)
        arr[i] = rand() % 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array: " << endl;
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: " << endl;
    printArray(arr, n);
    return 0;
}