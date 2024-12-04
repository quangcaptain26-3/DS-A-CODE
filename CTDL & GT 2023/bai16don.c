#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NhanVien{
    char hoten[30];
    int manv;
    float hsl;
    int pc;
    int maphongban;
    float luong;
    struct NhanVien *next;
}NhanVien;

typedef struct tagNode{
    NhanVien info;
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

int emptyList(List L){
    return (L.spt == 0);
}

void insert_Head(List *L, NhanVien x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(emptyList(*L)){
        L->head = L->tail = p;
    }
    else{
        p->next = L->head;
        L->head = p;
    }
    L->spt++;
}

void insert_Tail(List *L, NhanVien x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(emptyList(*L)){
        L->head = L->tail = p;
    }
    else{
        L->tail->next = p;
        L->tail = p;
    }
    L->spt++;
}

void printList(List L){
    Node *temp = L.head;
    while(temp != NULL){
        printf("%s %d %.2f %d %d %.2f\n", temp->info.hoten, temp->info.manv, temp->info.hsl, temp->info.pc, temp->info.maphongban, temp->info.luong);
        temp = temp->next;
    }
}

void search(List L, char hoten[]){
    Node *temp = L.head;
    while(temp != NULL){
        if(strcmp(temp->info.hoten, hoten) == 0){
            printf("%s %d %.2f %d %d %.2f\n", temp->info.hoten, temp->info.manv, temp->info.hsl, temp->info.pc, temp->info.maphongban, temp->info.luong);
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay\n");
}

int main(){
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    init(&L);
    for(int i = 0; i < n; i++){
        NhanVien x;
        printf("Nhap thong tin nhan vien thu %d:\n", i+1);
        printf("Nhap ho ten: ");
        fflush(stdin);
        gets(x.hoten);
        printf("Nhap ma nhan vien: ");
        scanf("%d", &x.manv);
        printf("Nhap he so luong: ");
        scanf("%f", &x.hsl);
        printf("Nhap phu cap: ");
        scanf("%d", &x.pc);
        printf("Nhap ma phong ban: ");
        scanf("%d", &x.maphongban);
        x.luong = x.hsl * 2000 + x.pc;
        insert_Tail(&L, x);
    }
    printList(L);
    printf("Nhap ten nhan vien can tim: ");
    char hoten[30];
    fflush(stdin);
    gets(hoten);
    search(L, hoten);
    return 0;
}