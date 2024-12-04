#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char ten[30];
    int msv;
    float diem;

} SV;

int sequential_search(SV a[], int n, char x[30]){
    int i;
    for(i=0;i<n;i++){
        if(strcmp(a[i].ten,x)==0){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,i;
    char x[30];
    printf("Nhap so luong sinh vien: ");
    scanf("%d",&n);
    SV a[n];
    for(i=0;i<n;i++){
        printf("Nhap ten sinh vien thu %d: ",i+1);
        fflush(stdin);
        gets(a[i].ten);
        printf("Nhap ma sinh vien thu %d: ",i+1);
        scanf("%d",&a[i].msv);
        printf("Nhap diem sinh vien thu %d: ",i+1);
        scanf("%f",&a[i].diem);
    }
    for(i = 0; i < n; i++){
        printf("Sinh vien thu %d: %s %d %.2f\n",i+1,a[i].ten,a[i].msv,a[i].diem);
        
    }

    printf("Nhap ten sinh vien can tim: ");
    fflush(stdin);
    gets(x);
    int kq=sequential_search(a,n,x);
    if(kq==-1){
        printf("Khong tim thay sinh vien %s",x);
    }
    else{
        printf("Tim thay sinh vien %s tai vi tri %d",x,kq);
    }
    return 0;
}