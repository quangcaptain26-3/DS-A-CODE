#include <stdio.h>
#include <stdlib.h>

typedef struct SoNguyen{
    int data;
    struct SoNguyen *next;
}SoNguyen;

typedef struct tagNode{
    SoNguyen info;
    struct tagNode *next;
}Node;

typedef struct tagList{
    Node *head;
    Node *tail;
    int spt;
}List;

List L;

int isEmpty(List L){
    return L.spt == 0;
}

void init(List *L){
    L->head = L->tail = NULL;
    L->spt = 0;
}

void insert_Head(List *L, SoNguyen x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
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

void insert_Tail(List *L, SoNguyen x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
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

void delete_Node(List *L){
    Node *p = L->head;
    while(p->next != NULL){
        if(p->info.data < p->next->info.data){
            p = p->next;
        } else {
            Node *q = p->next;
            p->next = q->next;
            free(q);
        }
    }
}

int main(){
    int n;
    SoNguyen x;
    init(&L);
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &x.data);
        insert_Tail(&L, x);
    }
    delete_Node(&L);
    Node *p = L.head;
    while(p != NULL){
        printf("%d ", p->info.data);
        p = p->next;
    }
    return 0;
}