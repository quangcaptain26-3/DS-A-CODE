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
    return L.head == NULL;
}

//cài đặt hàm sắp xếp giảm dần theo năm sinh, nếu cùng năm sinh thì theo mã nhân viên
void Sort(List *L){
    Node *p, *q;
    for(p = L->head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->data.namsinh < q->data.namsinh){
                NV temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            else if(p->data.namsinh == q->data.namsinh){
                if(p->data.mnv < q->data.mnv){
                    NV temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
            }
        }
    }
}

