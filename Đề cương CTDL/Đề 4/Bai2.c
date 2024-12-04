#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    int msv;
    char ten[30];
    float d1, d2, d3;
    struct SinhVien *next;
    struct SinhVien *prev;
}SV;

typedef struct tagNode{
    SV *data;
    struct tagNode *next;
    struct tagNode *prev;
}Node;

void init(Node *l){
    l->next = l->prev = NULL;
}

int isEmpty(Node *l){
    return l->next == NULL;
}

void push(Node *l, SV *x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    p->prev = NULL;
    if(isEmpty(l)){
        l->next = l->prev = p;
    }
    else{
        p->next = l->next;
        l->next->prev = p;
        l->next = p;
    }
}

void append(Node *l, SV *x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    p->prev = NULL;
    if(isEmpty(l)){
        l->next = l->prev = p;
    }
    else{
        l->prev->next = p;
        p->prev = l->prev;
        l->prev = p;
    }
}
void LoaiSinhVien(Node *l){
    Node *p = l->next;
    while(p != NULL){
        if(p->data->d1 < 4 || p->data->d2 < 4 || p->data->d3 < 4){
            if(p == l->next){
                l->next = p->next;
                l->next->prev = NULL;
                free(p);
                p = l->next;
            }
            else if(p == l->prev){
                l->prev = p->prev;
                l->prev->next = NULL;
                free(p);
                p = NULL;
            }
            else{
                p->prev->next = p->next;
                p->next->prev = p->prev;
                Node *q = p;
                p = p->next;
                free(q);
            }
        }
        else{
            p = p->next;
        }
    }
}

void printList(Node *l){
    Node *p = l->next;
    while(p != NULL){
        printf("%d %s %.1f %.1f %.1f\n", p->data->msv, p->data->ten, p->data->d1, p->data->d2, p->data->d3);
        p = p->next;
    }
}

int main(){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    Node l;
    init(&l);
    for(int i = 0; i < n; i++){
        SV *x = (SV*)malloc(sizeof(SV));
        printf("Nhap ma sinh vien: ");
        scanf("%d", &x->msv);
        printf("Nhap ten sinh vien: ");
        fflush(stdin);
        gets(x->ten);
        printf("Nhap diem 1: ");
        scanf("%f", &x->d1);
        printf("Nhap diem 2: ");
        scanf("%f", &x->d2);
        printf("Nhap diem 3: ");
        scanf("%f", &x->d3);
        append(&l, x);
    }
    printf("Danh sach sinh vien truoc khi loai: \n");
    printList(&l);
    LoaiSinhVien(&l);
    printf("Danh sach sinh vien sau khi loai: \n");
    printList(&l);
    return 0;
}