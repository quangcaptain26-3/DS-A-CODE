#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct SV {
    char ten[30];
    int msv;
    float dtb;
};

void nhap(struct SV *sv){
    printf("Nhap ten: \n");
    scanf("%s", sv->ten);
    printf("Nhap ma sinh vien: \n");
    scanf("%d", &sv->msv);
    printf("Nhap diem trung binh: \n");
    scanf("%f", &sv->dtb);
}

void xuat(struct SV *sv){
    printf("Ten: %s\n", sv->ten);
    printf("Ma sinh vien: %d\n", sv->msv);
    printf("Diem trung binh: %f\n", sv->dtb);
}

int sequentialSearch(struct SV *ds, int n, char *ten){

    for(int i = 0; i < n; i++){
         if(strcmp(ds[i].ten, ten) == 0){
              return i;
         }
    }
    return -1;

}

int main(){
    int n;
    struct SV ds[100];
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Nhap thong tin sih vien thu %d: \n", i+1);
        nhap(&ds[i]);
    }
    for(int i = 0; i < n; i++){
        printf("Thong tin sinh vien thu %d: \n", i+1);
        xuat(&ds[i]);
    }

    //find
    char ten[30];
    printf("Nhap ten sinh vien can tim: ");
    fflush(stdin);
    gets(ten);
    if(sequentialSearch(ds, n, ten) != -1){
        printf("Tim thay sinh vien %s\n", ten);
    }else{
        printf("Khong tim thay sinh vien %s\n", ten);
    }

    return 0;
}