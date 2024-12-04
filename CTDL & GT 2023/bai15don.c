#include<stdio.h>
#include<stdlib.h>

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

void tinhluong(){
    Node *p = L.head;
    while(p != NULL){
        p->info.luong = p->info.hsl * 2000 + p->info.pc;
        p = p->next;
    }
}

void tinhluongtb(int maphongban){
    Node *p = L.head;
    int dem = 0;
    float tong = 0;
    while(p != NULL){
        if(p->info.maphongban == maphongban){
            tong += p->info.luong;
            dem++;
        }
        p = p->next;
    }
    printf("Luong trung binh cua phong ban %d la: %.2f\n", maphongban, tong/dem);
}

int main(){
    init(&L);
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        NhanVien x;
        printf("Nhap thong tin nhan vien thu %d:\n", i+1);
        printf("Ho ten: ");
        fflush(stdin);
        gets(x.hoten);
        printf("Ma nhan vien: ");
        scanf("%d", &x.manv);
        printf("He so luong: ");
        scanf("%f", &x.hsl);
        printf("Phu cap: ");
        scanf("%d", &x.pc);
        printf("Ma phong ban: ");
        scanf("%d", &x.maphongban);
        insert_Tail(&L, x);
    }
    tinhluong();
    int maphongban;
    printf("Nhap ma phong ban: ");
    scanf("%d", &maphongban);
    tinhluongtb(maphongban);
    return 0;
}


