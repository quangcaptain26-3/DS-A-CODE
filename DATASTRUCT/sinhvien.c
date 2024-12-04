#include<stdio.h>
#include<string.h>

struct SV{
    char ten[30];
    int msv;
    float dtb;
};

void nhap(struct SV ds[], int n){
    for(int i = 0; i < n; i++){
        printf("Nhap thong tin sih vien thu %d: \n", i+1);
        printf("Nhap ten: \n");

        scanf("%s", ds[i].ten);
        
        
        printf("Nhap ma sinh vien: \n");
        scanf("%d", &ds[i].msv);
        printf("Nhap diem trung binh: \n");
        scanf("%f", &ds[i].dtb);
    }
}

void in(struct SV ds[], int n){
    for(int i = 0; i < n; i++){
        printf("Thong tin sinh vien thu %d: \n", i+1);
        printf("Ten: %s", ds[i].ten);
        printf("Ma sinh vien: %d\n", ds[i].msv);
        printf("Diem trung binh: %f\n", ds[i].dtb);
    }
}

struct SV findSV(struct SV ds[], int n, char *ten){
    for(int i = 0; i < n; i++){
        if(strcmp(ds[i].ten, ten) == 0){
            return ds[i];
        }
    }

    struct SV sv;
    strcpy(sv.ten, "Khong tim thay");
    strcpy(sv.msv, "Khong tim thay");
    sv.dtb = 0.0;
    return sv;
}

int main(){
    int n;
    struct SV ds[100];
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    nhap(ds, n);
    in(ds, n);

    //find
    char ten[30];
    printf("Nhap ten sinh vien can tim: ");
    fgets(ten, 30, stdin);
    ten[strlen(ten)-1] = '\0';

    struct SV sv = findSV(ds, n, ten);
    if(strcmp(sv.ten, "Khong tim thay") == 0){
        printf("Khong tim thay sinh vien %s\n", ten);
    }else{
        printf("Thong tin sinh vien %s: \n", ten);
        printf("Ten: %s", sv.ten);
        printf("Ma sinh vien: %d\n", sv.msv);
        printf("Diem trung binh: %f\n", sv.dtb);
    }

    return 0;
}