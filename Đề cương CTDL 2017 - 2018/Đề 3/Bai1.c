#include<stdio.h>
#include<stdlib.h>

//cài đặt thuật toán QuickSort trên một mảng gồm n phần tử
void QuickSort(int a[], int left, int right){
    int i, j, x;
    x = a[(left + right) / 2];
    i = left;
    j = right;
    do{
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++; j--;
        }
    }while(i <= j);
    if(left < j) QuickSort(a, left, j);
    if(i < right) QuickSort(a, i, right);
}

