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
}NV;

typedef struct tagNode{
    NV *info;
    struct tagNode *next;
}Node;

typedef struct tagList{
    Node *head;
    Node *tail;
    int spt;
}List;

List l;

void init(List *l){
    l->head = l->tail = NULL;
    l->spt = 0;
}

int isEmpty(List l){
    return l.spt == 0;
}

void insert_Head(List *l, NV *x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(isEmpty(*l)){
        l->head = l->tail = p;
    }
    else{
        p->next = l->head;
        l->head = p;
    }
    l->spt++;
}

void insert_Tail(List *l, NV *x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(isEmpty(*l)){
        l->head = l->tail = p;
    }
    else{
        l->tail->next = p;
        l->tail = p;
    }
    l->spt++;
}

//tìm kiếm nhân viên theo tên
Node *search(List l, char *ten){
    Node *p = l.head;
    while(p != NULL){
        if(strcmp(p->info->hoTen, ten) == 0){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void printList(List l){
    Node *p = l.head;
    while(p != NULL){
        printf("%s %d %.2f %d %d\n", p->info->hoTen, p->info->maNV, p->info->hsl, p->info->pc, p->info->maphongban);
        p = p->next;
    }
}

int main(){
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    init(&l);
    for(int i = 0; i < n; i++){
        NV *x = (NV*)malloc(sizeof(NV));
        printf("Nhap thong tin nhan vien thu %d:\n", i + 1);
        printf("Ho ten: ");
        fflush(stdin);
        gets(x->hoTen);
        printf("Ma nhan vien: ");
        scanf("%d", &x->maNV);
        printf("He so luong: ");
        scanf("%f", &x->hsl);
        printf("Phu cap: ");
        scanf("%d", &x->pc);
        printf("Ma phong ban: ");
        scanf("%d", &x->maphongban);
        insert_Tail(&l, x);
    }

    printf("------------------\n");
    printf("Danh sach nhan vien:\n");
    printList(l);
    printf("------------------\n");
    char ten[30];
    printf("Nhap ten nhan vien can tim: ");
    fflush(stdin);
    gets(ten);
    Node *p = search(l, ten);
    if(p != NULL){
        printf("%s %d %.2f %d %d\n", p->info->hoTen, p->info->maNV, p->info->hsl, p->info->pc, p->info->maphongban);
    }
    else{
        printf("Khong tim thay\n");
    }
}