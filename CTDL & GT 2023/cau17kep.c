#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct NhanVien{
    char hoTen[30];
    int maNV;
    float hsl;
    int pc;
    int maphongban;
    struct NhanVien *next;
    struct NhanVien *prev;
}NV;

typedef struct tagNode{
    NV *info;
    struct tagNode *next;
    struct tagNode *prev;
}Node;

void push(Node **head, NV *x){
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

void append(Node **head, NV *x){
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

void SearchName(Node *head, char name[]){
    Node *temp = head;
    while(temp != NULL){
        if(strcmp(temp->info->hoTen, name) == 0){
            printf("%d %s %.2f %d %d\n", temp->info->maNV, temp->info->hoTen, temp->info->hsl, temp->info->pc, temp->info->maphongban);
        }
        temp = temp->next;
    }
}


void printfList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d %s %.2f %d %d\n", temp->info->maNV, temp->info->hoTen, temp->info->hsl, temp->info->pc, temp->info->maphongban);
        temp = temp->next;
    }
}

int main(){
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    Node *head = NULL;
    for(int i = 0; i < n; i++){
        NV *x = (NV*)malloc(sizeof(NV));
        printf("Nhap thong tin nhan vien thu %d:\n", i+1);
        printf("Nhap ho ten: ");
        fflush(stdin);
        gets(x->hoTen);
        printf("Nhap ma nhan vien: ");
        scanf("%d", &x->maNV);
        printf("Nhap he so luong: ");
        scanf("%f", &x->hsl);
        printf("Nhap phu cap: ");
        scanf("%d", &x->pc);
        printf("Nhap ma phong ban: ");
        scanf("%d", &x->maphongban);
        append(&head, x);
    }
    printf("------------------\n");
    printf("Danh sach nhan vien:\n");
    printfList(head);
    printf("------------------\n");
    printf("Nhap ten nhan vien can tim: ");
    char name[30];
    fflush(stdin);
    gets(name);
    printf("Thong tin nhan vien can tim:\n");
    SearchName(head, name);
    return 0;
}