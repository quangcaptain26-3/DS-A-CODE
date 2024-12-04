#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct HocSinh{
    char ten[30];
    int mhs;
    float d1, d2, d3;
}SV;

void nhap(SV *sv){
    printf("Nhap ten: ");
    fflush(stdin);
    gets(sv->ten);
    printf("Nhap ma hoc sinh: ");
    scanf("%d", &sv->mhs);
    printf("Nhap diem 1: ");
    scanf("%f", &sv->d1);
    printf("Nhap diem 2: ");
    scanf("%f", &sv->d2);
    printf("Nhap diem 3: ");
    scanf("%f", &sv->d3);
}

void xuat(SV sv){
    printf("%s %d %.2f %.2f %.2f\n", sv.ten, sv.mhs, sv.d1, sv.d2, sv.d3);
}

int partition(SV a[], int low, int high){
    SV pivot = a[high];
    int i = low - 1;
    SV temp;

    for(int j = low; j < high; j++){
        if(strcmp(a[j].ten, pivot.ten) < 0 || (strcmp(a[j].ten, pivot.ten) == 0 && a[j].mhs < pivot.mhs)){
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;
    return i+1;
}

void quick_sort(SV a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quick_sort(a, low, pi-1);
        quick_sort(a, pi+1, high);
    }
}

int main(){
    SV sv[] = {
        {"An", 1, 85, 90, 95},
        {"Binh", 2, 80, 85, 90},
        {"An", 3, 75, 80, 85},
        {"Dung", 4, 70, 75, 80}
    };

    int n = sizeof(sv) / sizeof(SV);
    quick_sort(sv, 0, n-1);

    for(int i = 0; i < n; i++){
        xuat(sv[i]);
    }
    return 0;
}