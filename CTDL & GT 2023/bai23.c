#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct SinhVien{
    char name[30];
    int id;
    float dtb;
};

void FindByName(struct SinhVien a[], int n, char name[]){
    int i, j, min;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(strcmp(a[j].name, a[min].name) < 0){
                min = j;
            }
        }
        struct SinhVien temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    for(i = 0; i < n; i++){
        if(strcmp(a[i].name, name) == 0){
            printf("%s %d %.2f\n", a[i].name, a[i].id, a[i].dtb);
        }
    }
}

int main(){
    int n;
    struct SinhVien a[100];
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
    char name[30];
    printf("Nhap ten hoc sinh can tim: ");
    fflush(stdin);
    gets(name);
    FindByName(a, n, name);
    return 0;
}