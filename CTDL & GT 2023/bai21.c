#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[30];
    int id;
    float dtb;
}HS;

void swap(HS *a, HS *b){
    HS temp = *a;
    *a = *b;
    *b = temp;
}

void selection_Sort(HS a[], int n){
    int i, j, min;

    for(i = 0; i < n - 1; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j].name < a[min].name){
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }

    for(i = 0; i < n - 1; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j].id < a[min].id){
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}

void print(HS a[], int n){
    for(int i = 0; i < n; i++){
        printf("%s %d %.2f\n", a[i].name, a[i].id, a[i].dtb);
    }
}

int main(){
    int n;
    HS a[100];
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Nhap ten hoc sinh thu %d: ", i + 1);
        fflush(stdin);
        gets(a[i].name);
        printf("Nhap ma hoc sinh thu %d: ", i + 1);
        scanf("%d", &a[i].id);
        printf("Nhap diem trung binh hoc sinh thu %d: ", i + 1);
        scanf("%f", &a[i].dtb);
    }
    printf("--------------------------------\n");
    printf("Danh sach hoc sinh truoc khi sap xep: \n");
    print(a, n);

    printf("--------------------------------\n");
    printf("Danh sach hoc sinh sau khi sap xep: \n");
    selection_Sort(a, n);
    print(a, n);
    return 0;
}