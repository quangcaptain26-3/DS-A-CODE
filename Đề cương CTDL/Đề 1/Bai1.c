#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char hoten[30];
    int msv;
    float toan, triet, ltC;
    struct SinhVien *next;
}SV;

typedef struct tagNode{
    SV *info;
    struct tagNode *next;
}Node;

typedef struct tagList{
    Node *head, *tail;
    int spt;
}List;

List L;

void init(List *L){
    L->head = L->tail = NULL;
    L->spt = 0;
}

int isEmpty(List L){
    return (L.spt == 0);
}

void insert_Head(List *L, SV *x){
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

void insert_Tail(List *L, SV *x){
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

void insert_Sort(List *L, SV *x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(isEmpty(*L)){
        L->head = L->tail = p;
    }
    else{
        Node *q = L->head;
        Node *prev = NULL;
        while(q != NULL && strcmp(q->info->hoten, x->hoten) < 0){
            prev = q;
            q = q->next;
        }
        if(prev == NULL){
            p->next = L->head;
            L->head = p;
        }
        else{
            p->next = prev->next;
            prev->next = p;
        }
    }
    L->spt++;
}

void printList(List L){
    Node *p = L.head;
    while(p != NULL){
        printf("%s %d %.2f %.2f %.2f\n", p->info->hoten, p->info->msv, p->info->toan, p->info->triet, p->info->ltC);
        p = p->next;
    }
}

int main(){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    init(&L);
    for(int i = 0; i < n; i++){
        SV *x = (SV*)malloc(sizeof(SV));
        printf("Nhap thong tin sinh vien thu %d:\n", i+1);
        printf("Ho ten: ");
        fflush(stdin);
        gets(x->hoten);
        printf("Ma sinh vien: ");
        scanf("%d", &x->msv);
        printf("Diem toan: ");
        scanf("%f", &x->toan);
        printf("Diem triet: ");
        scanf("%f", &x->triet);
        printf("Diem lap trinh C: ");
        scanf("%f", &x->ltC);
        insert_Sort(&L, x);
    }
    printf("Danh sach sinh vien sau khi nhap:\n");
    printList(L);
    
}