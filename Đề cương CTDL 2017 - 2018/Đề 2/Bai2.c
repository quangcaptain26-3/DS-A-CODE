#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    int msv;
    char ten[30];
    float dtb;
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

//) Hãy cài đặt hàm loại bỏ phần tử có mã sinh viên x trong danh sách (x là tham số được truyền vào). 
//Nếu x không có trong danh sách thì thông báo không có trong danh sách.

void Delete(List *L, int x){
    Node *p, *q;
    for(p = L->head; p != NULL; p = p->next){
        if(p->data.msv == x){
            if(p == L->head){
                L->head = L->head->next;
                free(p);
                L->spt--;
                return;
            }
            else if(p == L->tail){
                L->tail = q;
                q->next = NULL;
                free(p);
                L->spt--;
                return;
            }
            else{
                q->next = p->next;
                free(p);
                L->spt--;
                return;
            }
        }
        q = p;
    }
    printf("Khong co trong danh sach\n");
}