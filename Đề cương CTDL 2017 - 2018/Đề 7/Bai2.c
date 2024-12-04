// .	Khai báo cấu trúc dữ liệu cây tìm kiếm nhị phân chứa các thông tin về nhân sự gồm có các trường thông tin: Họ và tên; Mã nhân sự; Hệ số lương; Lương cơ bản. Trường khóa là mã nhân sự.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NhanSu{
    char ten[30];
    int namcongtac;
    float hsl;
    int luongcoban;
    struct NhanSu *left;
    struct NhanSu *right;
}NS;

NS *root;

void init(){
    root = NULL;
}

NS *makeNode(NS x){
    NS *p = (NS*)malloc(sizeof(NS));
    if(p == NULL){
        printf("Khong du bo nho");
        exit(0);
    }
    *p = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

//Viết hàm tính tổng lương của n nhân viên. Biết lương của một nhân viên được tính theo công thức: lương = lương có bản*hệ số lương
int TongLuong(NS *root){
    if(root == NULL){
        return 0;
    }
    return root->luongcoban * root->hsl + TongLuong(root->left) + TongLuong(root->right);
}