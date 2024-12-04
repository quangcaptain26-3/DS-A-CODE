#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char hoten[30];
    int msv;
    float toan, triet, ltC;
}SV;

//xây dựng thuật toán đếm và in ra các sinh viên phải học lại, vớI điểm dưới 4.0
void nhap(SV *sv){
    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(sv->hoten);
    printf("Nhap ma sinh vien: ");
    scanf("%d", &sv->msv);
    printf("Nhap diem toan: ");
    scanf("%f", &sv->toan);
    printf("Nhap diem triet: ");
    scanf("%f", &sv->triet);
    printf("Nhap diem lap trinh C: ");
    scanf("%f", &sv->ltC);
}

void xuat(SV sv){
    printf("%s %d %.2f %.2f %.2f\n", sv.hoten, sv.msv, sv.toan, sv.triet, sv.ltC);
}

int main(){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    SV *sv = (SV*)malloc(n*sizeof(SV));
    for(int i = 0; i < n; i++){
        printf("Nhap thong tin sinh vien thu %d:\n", i+1);
        nhap(&sv[i]);
    }
    int dem = 0;
    printf("Danh sach sinh vien phai hoc lai:\n");
    for(int i = 0; i < n; i++){
        if(sv[i].toan < 4.0 || sv[i].triet < 4.0 || sv[i].ltC < 4.0){
            xuat(sv[i]);
            dem++;
        }
    }
    printf("So sinh vien phai hoc lai la: %d\n", dem);
    return 0;
}
