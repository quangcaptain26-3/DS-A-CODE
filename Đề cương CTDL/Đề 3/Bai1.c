#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct HangHoa{
    char ten[30];
    int ma;
    float giamua;
    float giaban;
    struct HangHoa *next;
}HH;

typedef struct tagNode{
    HH *info;
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

void insert_Head(List *L, HH *x){
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

void insert_Tail(List *L, HH *x){
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

void insert_Sort(List *L, HH *x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(isEmpty(*L)){
        L->head = L->tail = p;
    }
    else{
        Node *q = L->head;
        Node *prev = NULL;
        while(q != NULL && strcmp(q->info->ten, x->ten) < 0){
            prev = q;
            q = q->next;
        }
        if(q == L->head){
            p->next = L->head;
            L->head = p;
        }
        else{
            p->next = q;
            prev->next = p;
        }
    }
    L->spt++;
}

void print(List L){
    Node *p = L.head;
    while(p != NULL){
        printf("%s %d %.2f %.2f\n", p->info->ten, p->info->ma, p->info->giamua, p->info->giaban);
        p = p->next;
    }
}

int main(){
    int n;
    printf("Nhap so luong hang hoa: ");
    scanf("%d", &n);
    init(&L);
    for(int i = 0; i < n; i++){
        HH *hh = (HH*)malloc(sizeof(HH));
        printf("Nhap ten: ");
        fflush(stdin);
        gets(hh->ten);
        printf("Nhap ma hang hoa: ");
        scanf("%d", &hh->ma);
        printf("Nhap gia mua: ");
        scanf("%f", &hh->giamua);
        printf("Nhap gia ban: ");
        scanf("%f", &hh->giaban);
        insert_Sort(&L, hh);
    }
    printf("Danh sach hang hoa sau khi sap xep:\n");
    print(L);
    return 0;
}
