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

//Giả sử có hai danh sách liên kết đơn L1, L2 chứa các sinh viên. Hãy viết hàm gộp hai  danh sách trên thành một danh sách sao cho danh sách kết quả được sắp xếp tăng dần theo điểm trung bình.
void gop(List L1, List L2, List *L){
    Node *p = L1.head;
    Node *q = L2.head;
    while(p != NULL && q != NULL){
        if(p->data.diem < q->data.diem){
            push(L, p->data);
            p = p->next;
        }
        else{
            push(L, q->data);
            q = q->next;
        }
    }
    while(p != NULL){
        push(L, p->data);
        p = p->next;
    }
    while(q != NULL){
        push(L, q->data);
        q = q->next;
    }
}