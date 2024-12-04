#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char ten[30];
    int msv;
    float diem;
    struct SinhVien *next;
}SV;

typedef struct tagNode{
    SV data;
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
    return L.head == NULL;
}

void push(List *L, SV x){
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

void bubbleSort(List *L){
    Node *p, *q;
    SV temp;
    for(p = L->head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->data.diem > q->data.diem){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

