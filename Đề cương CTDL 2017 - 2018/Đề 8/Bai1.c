//Hãy cài đặt và đánh giá độ phức tạp của thuật toán sắp xếp chọn trực tiếp trên mảng gồm n số nguyên.

#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void Selection_Sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}