#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NhanSu{
    char ten[30];
    int namcongtac;
    float hsl;
    int luongcoban;
    struct NhanSu *next;  
    struct NhanSu *prev;
}NS;

typedef struct tagNode{
    NS data;
    struct tagNode *next;
    struct tagNode *prev;
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
    return L.head == NULL;
}

void push(List *L, NS x){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if(isEmpty(*L)){
        L->head = L->tail = temp;
    }
    else{
        L->tail->next = temp;
        temp->prev = L->tail;
        L->tail = temp;
    }
    L->spt++;
}


void append(List *L, NS x){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    if(isEmpty(*L)){
        L->head = L->tail = temp;
    }
    else{
        L->tail->next = temp;
        temp->prev = L->tail;
        L->tail = temp;
    }
    L->spt++;
}

void nhap(List *L){
    int n;
    printf("Nhap so luong nhan su: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        NS x;
        printf("Nhap ten: ");
        fflush(stdin);
        gets(x.ten);
        printf("Nhap nam cong tac: ");
        scanf("%d", &x.namcongtac);
        printf("Nhap he so luong: ");
        scanf("%f", &x.hsl);
        printf("Nhap luong co ban: ");
        scanf("%d", &x.luongcoban);
        append(L, x);
    }
}

