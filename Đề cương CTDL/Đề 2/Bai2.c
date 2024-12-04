#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char hoten[30];
    int msv;
    char gioitinh[5];
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

void tach(List L, List *L1, List *L2){
    Node *p = L.head;
    while(p != NULL){
        if(strcmp(p->info->gioitinh, "Nam") == 0){
            insert_Tail(L1, p->info);
        }
        else{
            insert_Tail(L2, p->info);
        }
        p = p->next;
    }
}

void xuat(List L){
    Node *p = L.head;
    while(p != NULL){
        printf("%s %d %s\n", p->info->hoten, p->info->msv, p->info->gioitinh);
        p = p->next;
    }
}

int main(){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    init(&L);
    for(int i = 0; i < n; i++){
        SV *sv = (SV*)malloc(sizeof(SV));
        printf("Nhap ten: ");
        fflush(stdin);
        gets(sv->hoten);
        printf("Nhap ma sinh vien: ");
        scanf("%d", &sv->msv);
        printf("Nhap gioi tinh: ");
        fflush(stdin);
        gets(sv->gioitinh);
        insert_Tail(&L, sv);
    }
    List L1, L2;
    init(&L1);
    init(&L2);
    tach(L, &L1, &L2);
    printf("Danh sach sinh vien nam:\n");
    xuat(L1);
    printf("Danh sach sinh vien nu:\n");
    xuat(L2);
    return 0;
}