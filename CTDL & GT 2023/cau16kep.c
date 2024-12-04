#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void printList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%s %d %.2f %d %d %.2f\n", temp->info.hoten, temp->info.manv, temp->info.hsl, temp->info.pc, temp->info.maphongban, temp->info.luong);
        temp = temp->next;
    }
}

void SearchByName(Node *head, char name[]){
    Node *temp = head;
    while(temp != NULL){
        if(strcmp(temp->info.hoten, name) == 0){
            printf("%s %d %.2f %d %d %.2f\n", temp->info.hoten, temp->info.manv, temp->info.hsl, temp->info.pc, temp->info.maphongban, temp->info.luong);
            return;
        }
        temp = temp->next;
    }
    printf("NOT FOUND\n");
}

int main(){
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    Node *head = NULL;
    for(int i = 0; i < n; ++i){
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
        x.luong = x.hsl * 2000 + x.pc;
        append(&head, x);
    }
    printList(head);
    char name[30];
    printf("Nhap ten nhan vien can tim: ");
    fflush(stdin);
    gets(name);
    SearchByName(head, name);
    return 0;
}