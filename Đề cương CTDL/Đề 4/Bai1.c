#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NhanVien{
    char ten[30];
    int mnv;
    float hsl;
    int pc;
    struct NhanVien *next;
}NV;

typedef struct tagNode{
    NV *data;
    struct tagNode *next;
}Node;

typedef struct tagList{
    Node *head;
    Node *tail;
    int spt;
}List;

void init(List *l){
    l->head = l->tail = NULL;
    l->spt = 0;
}

int isEmpty(List *l){
    return l->head == NULL;
}

void insert_head(List *l, NV *x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if(isEmpty(l)){
        l->head = l->tail = p;
    }
    else{
        p->next = l->head;
        l->head = p;
    }
    l->spt++;
}

void insert_tail(List *l, NV *x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if(isEmpty(l)){
        l->head = l->tail = p;
    }
    else{
        l->tail->next = p;
        l->tail = p;
    }
    l->spt++;
}

void swap(NV *a, NV *b){
    NV temp = *a;
    *a = *b;
    *b = temp;
}

//selection sort theo tên, cùng tên theo mã nhân viên
void selectionSort(List *l){
    Node *p = l->head;
    Node *q;
    while(p != NULL){
        q = p->next;
        while(q != NULL){
            if(strcmp(p->data->ten, q->data->ten) > 0){
                swap(p->data, q->data);
            }
            else if(strcmp(p->data->ten, q->data->ten) == 0){
                if(p->data->mnv > q->data->mnv){
                    swap(p->data, q->data);
                }
            }
            q = q->next;
        }
        p = p->next;
    }
}

int main(){
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    List l;
    init(&l);
    for(int i = 0; i < n; i++){
        NV *x = (NV*)malloc(sizeof(NV));
        printf("Nhap ten nhan vien: ");
        fflush(stdin);
        gets(x->ten);
        printf("Nhap ma nhan vien: ");
        scanf("%d", &x->mnv);
        printf("Nhap he so luong: ");
        scanf("%f", &x->hsl);
        printf("Nhap phu cap: ");
        scanf("%d", &x->pc);
        insert_tail(&l, x);
    }
    printf("\nDanh sach nhan vien vua nhap:\n");
    Node *p = l.head;
    printf("%-30s%-15s%-15s%-15s\n", "Ten nhan vien", "Ma nhan vien", "He so luong", "Phu cap");
    while(p != NULL){
        printf("%-30s%-15d%-15.2f%-15d\n", p->data->ten, p->data->mnv, p->data->hsl, p->data->pc);
        p = p->next;
    }
    selectionSort(&l);
    printf("\nDanh sach nhan vien sau khi sap xep:\n");
    printf("%-30s%-15s%-15s%-15s\n", "Ten nhan vien", "Ma nhan vien", "He so luong", "Phu cap");
    p = l.head;
    while(p != NULL){
        printf("%-30s%-15d%-15.2f%-15d\n", p->data->ten, p->data->mnv, p->data->hsl, p->data->pc);
        p = p->next;
    }
    return 0;
}