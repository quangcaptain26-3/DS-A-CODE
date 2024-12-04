//Cài đặt thuật toán sắp xếp nổi bọt tăng dần trên mảng cấu trúc sinh viên gồm các trường thông tin sau: Mã sinh viên; Tên sinh viên; Tuổi sinh viên. Trường khóa để sắp xếp là trường tuổi, nếu cùng tuổi thì theo tên

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char ten[30];
    int msv;
    int tuoi;
}SV;

void BubbleSort(SV a[], int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        for(j = n - 1; j > i; j--){
            if(a[j].tuoi < a[j - 1].tuoi){
                SV temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
            else if(a[j].tuoi == a[j - 1].tuoi){
                if(strcmp(a[j].ten, a[j - 1].ten) < 0){
                    SV temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                }
            }
        }
    }
}