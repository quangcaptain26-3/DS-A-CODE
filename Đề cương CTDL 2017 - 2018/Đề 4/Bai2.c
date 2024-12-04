#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct HangHoa{
    char ten[30];
    int gia;
    int soluong;    
    struct HangHoa *next;
}HH;

typedef struct tagNode{
    HH data;
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

//cài đặt hàm sắp xếp chiều tăng dần của giá mặt hàng, nếu cùng giá thì theo tên.
void Sort(List *L){
    Node *p, *q;
    for(p = L->head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->data.gia > q->data.gia){
                HH temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            else if(p->data.gia == q->data.gia){
                if(strcmp(p->data.ten, q->data.ten) > 0){
                    HH temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
            }
        }
    }
}