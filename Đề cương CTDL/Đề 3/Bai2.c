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
    HH *data;
    struct tagNode *next;
}Node;

typedef struct tagList{
    Node *head;
    Node *tail;
    int spt;
}List;

void init(List *l){
    l->head = l->tail = NULL;
    l->spt = 0;
}

int isEmpty(List *l){
    return l->head == NULL;
}

void insert_head(List *l, HH *x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if(isEmpty(l)){
        l->head = l->tail = p;
    }
    else{
        p->next = l->head;
        l->head = p;
    }
    l->spt++;
}

void insert_tail(List *l, HH *x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if(isEmpty(l)){
        l->head = l->tail = p;
    }
    else{
        l->tail->next = p;
        l->tail = p;
    }
    l->spt++;
}

//giả sử có 2 danh sách L1 và L2 các mặt hàng. Viết hàm trộn xen kẽ 2 danh sách thành 1 danh sách L
void tron(List *l, List *l1, List *l2){
    Node *p1 = l1->head;
    Node *p2 = l2->head;
    while(p1 != NULL && p2 != NULL){
        insert_tail(l, p1->data);
        insert_tail(l, p2->data);
        p1 = p1->next;
        p2 = p2->next;
    }
    while(p1 != NULL){
        insert_tail(l, p1->data);
        p1 = p1->next;
    }
    while(p2 != NULL){
        insert_tail(l, p2->data);
        p2 = p2->next;
    }
}

void nhap(HH *x){
    printf("Nhap ten hang hoa: ");
    fflush(stdin);
    gets(x->ten);
    printf("Nhap gia: ");
    scanf("%d", &x->gia);
    printf("Nhap so luong: ");
    scanf("%d", &x->soluong);
}

void xuat(HH *x){
    printf("%-30s%-15d%-15d\n", x->ten, x->gia, x->soluong);
}

void xuatList(List *l){
    Node *p = l->head;
    while(p != NULL){
        xuat(p->data);
        p = p->next;
    }
}

int main(){
    List l, l1, l2;
    init(&l);
    init(&l1);
    init(&l2);
    int n, m;
    printf("Nhap so luong hang hoa cua danh sach 1: ");
    scanf("%d", &n);
    printf("Nhap so luong hang hoa cua danh sach 2: ");
    scanf("%d", &m);
    for(int i = 0; i < n; i++){
        HH *x = (HH*)malloc(sizeof(HH));
        nhap(x);
        insert_tail(&l1, x);
    }
    for(int i = 0; i < m; i++){
        HH *x = (HH*)malloc(sizeof(HH));
        nhap(x);
        insert_tail(&l2, x);
    }
    printf("\nDanh sach 1:\n");
    xuatList(&l1);
    printf("\nDanh sach 2:\n");
    xuatList(&l2);
    printf("\nDanh sach tron:\n");
    tron(&l, &l1, &l2);
    xuatList(&l);
    return 0;
}