#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char hoTen[50];
    int maNhanSu;
    float heSoLuong;
    float luongCoBan;
    struct NhanSu *next;
} NhanSu;

typedef struct tagNode {
    NhanSu data;
    struct tagNode *next;
} Node;

typedef struct tagList {
    Node *head;
    Node *tail;
    int spt;
} List;

List L;

void init(List *L) {
    L->head = L->tail = NULL;
    L->spt = 0;
}

int isEmpty(List L) {
    return L.head == NULL;
}

void insert_Head(List *L, NhanSu x) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if (isEmpty(*L)) {
        L->head = L->tail = p;
    } else {
        p->next = L->head;
        L->head = p;
    }
    L->spt++;
}

insert_Tail(List *L, NhanSu x) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if (isEmpty(*L)) {
        L->head = L->tail = p;
    } else {
        L->tail->next = p;
        L->tail = p;
    }
    L->spt++;
}