#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char ten[30];
    int msv;
    char gioitinh[5];
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


//viết hàm tách danh sách sinh viên thành 2 danh sách con: danh sách sinh viên nam và danh sách sinh viên nữ
void Split(List L, List *L1, List *L2){
    Node *p;
    for(p = L.head; p != NULL; p = p->next){
        if(strcmp(p->data.gioitinh, "Nam") == 0){
            Node *temp = (Node*)malloc(sizeof(Node));
            temp->data = p->data;
            temp->next = NULL;
            if(isEmpty(*L1)){
                L1->head = L1->tail = temp;
            }
            else{
                L1->tail->next = temp;
                L1->tail = temp;
            }
            L1->spt++;
        }
        else{
            Node *temp = (Node*)malloc(sizeof(Node));
            temp->data = p->data;
            temp->next = NULL;
            if(isEmpty(*L2)){
                L2->head = L2->tail = temp;
            }
            else{
                L2->tail->next = temp;
                L2->tail = temp;
            }
            L2->spt++;
        }
    }
}