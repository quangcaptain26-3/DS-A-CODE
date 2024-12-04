#include<stdio.h>

//cài đặt thuật toán sắp xếp đổi chỗ trực tiếp trên một mảng gồm n phần tử
void InterchangeSort(int a[], int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}



