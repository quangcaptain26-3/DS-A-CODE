#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void BubbleSort(int a[], int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        for(j = n - 1; j > i; j--){
            if(a[j] < a[j - 1]){
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;	
            }
        }
    }
}

