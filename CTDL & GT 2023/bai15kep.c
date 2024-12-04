#include<stdio.h>
#include<stdlib.h>

typedef struct NhanVien{
    char hoten[30];
    int manv;
    float hsl;
    int pc;
    int maphongban;
    float luong;
    struct NhanVien *next;
    struct NhanVien *prev;
}NhanVien;

typedef struct tagNode{
    NhanVien info;
    struct tagNode *next;
    struct tagNode *prev;
}Node;

void push(Node **head, NhanVien x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    if(*head == NULL){
        *head = p;
    }
    else{
        p->next = *head;
        (*head)->prev = p;
        *head = p;
    }
}

void append(Node **head, NhanVien x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    if(*head == NULL){
        *head = p;
    }
    else{
        Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}

void tinhLuong(Node *head){
    Node *temp = head;
    while(temp != NULL){
        temp->info.luong = temp->info.hsl * 2000 + temp->info.pc;
        temp = temp->next;
    }
}

void tinhTrungBinhLuong(Node *head, int maphongban){
    Node *temp = head;
    int dem = 0;
    float tong = 0;
    while(temp != NULL){
        if(temp->info.maphongban == maphongban){
            tong += temp->info.luong;
            dem++;
        }
        temp = temp->next;
    }
    printf("Trung binh luong cua phong ban %d la: %.2f\n", maphongban, tong/dem);
}

int main(){
    Node *head = NULL;
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        NhanVien x;
        printf("Nhap thong tin nhan vien thu %d:\n", i+1);
        printf("Nhap ho ten: ");
        fflush(stdin);
        gets(x.hoten);
        printf("Nhap ma nhan vien: ");
        scanf("%d", &x.manv);
        printf("Nhap he so luong: ");
        scanf("%f", &x.hsl);
        printf("Nhap phu cap: ");
        scanf("%d", &x.pc);
        printf("Nhap ma phong ban: ");
        scanf("%d", &x.maphongban);
        push(&head, x);
    }
    tinhLuong(head);
    int maphongban;
    printf("Nhap ma phong ban can tinh trung binh luong: ");
    scanf("%d", &maphongban);
    tinhTrungBinhLuong(head, maphongban);
    return 0;
}

