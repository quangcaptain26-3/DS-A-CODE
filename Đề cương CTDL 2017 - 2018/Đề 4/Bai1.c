#include<stdio.h>
#include<stdlib.h>

//cài đặt thuật toán sắp xếp chèn trên một mảng gồm n phần tử
void InsertionSort(int a[], int n){
    int i, j, x;
    for(i = 1; i < n; i++){
        x = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > x){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}