#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NhanVien{
    char ten[30];
    int mnv;
    float hsl;
    int namsinh;
    struct NhanVien *next;
}NV;

typedef struct tagNode{
    NV data;
    struct tagNode *next;
}Node;

typedef struct tagList{
    Node *head;
    Node *tail;
    int spt;
}List;

List L;

void init(List *L){
    L->head = L->tail = NULL;
    L->spt = 0;
}

int isEmpty(List L){
    return L.spt == 0;
}

void insert_Head(List *L, NV x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if(isEmpty(*L)){
        L->head = L->tail = p;
    }
    else{
        p->next = L->head;
        L->head = p;
    }
    L->spt++;
}

void insert_Tail(List *L, NV x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if(isEmpty(*L)){
        L->head = L->tail = p;
    }
    else{
        L->tail->next = p;
        L->tail = p;
    }
    L->spt++;
}

void insert_keep_sorted_by_name(List *L, NV x){
    if(isEmpty(*L)){
        insert_Head(L, x);
        return;
    }
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    Node *current = L->head;
    while(current != NULL && strcmp(current->data.ten, x.ten) < 0){
        current = current->next;
    }
    if(current == NULL){
        insert_Tail(L, x);
    }
    else if(current == L->head){
        insert_Head(L, x);
    }
    else{
        Node *prev = L->head;
        while(prev->next != current){
            prev = prev->next;
        }
        prev->next = p;
        p->next = current;
        L->spt++;
    }
}

void print(List L){
    Node *current = L.head;
    while(current != NULL){
        printf("%s %d %.2f %d\n", current->data.ten, current->data.mnv, current->data.hsl, current->data.namsinh);
        current = current->next;
    }
}

int main(){
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    init(&L);
    for(int i = 0; i < n; i++){
        NV x;
        printf("Nhap ten: ");
        fflush(stdin);
        gets(x.ten);
        printf("Nhap ma nhan vien: ");
        scanf("%d", &x.mnv);
        printf("Nhap he so luong: ");
        scanf("%f", &x.hsl);
        printf("Nhap nam sinh: ");
        scanf("%d", &x.namsinh);
        insert_keep_sorted_by_name(&L, x);
    }
    printf("Danh sach nhan vien sau khi sap xep theo ten:\n");
    print(L);
    printf("Nhap thong tin nhan vien can them:\n");
    NV x;
    printf("Nhap ten: ");
    fflush(stdin);
    gets(x.ten);
    printf("Nhap ma nhan vien: ");
    scanf("%d", &x.mnv);
    printf("Nhap he so luong: ");
    scanf("%f", &x.hsl);
    printf("Nhap nam sinh: ");
    scanf("%d", &x.namsinh);
    insert_keep_sorted_by_name(&L, x);
    printf("Danh sach nhan vien sau khi them:\n");
    print(L);
    return 0;
}