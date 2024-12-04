#include<stdio.h>
#include<stdlib.h>

typedef struct HocSinh{
    char name[30];
    float dtb;
    struct HocSinh *next;
    struct HocSinh *prev;
}HocSinh;

typedef struct tagNode{
    HocSinh info;
    struct tagNode *next;
    struct tagNode *prev;
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

void push(List *L, HocSinh x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    if(emptyList(*L)){
        L->head = L->tail = p;
    }
    else{
        p->next = L->head;
        L->head->prev = p;
        L->head = p;
    }
    L->spt++;
}

void append(List *L, HocSinh x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    if(emptyList(*L)){
        L->head = L->tail = p;
    }
    else{
        L->tail->next = p;
        p->prev = L->tail;
        L->tail = p;
    }
    L->spt++;
}

//sắp xếp tăng dần theo điểm trung bình bằng bubble sort
void sort(List *L){
    Node *p, *q;
    HocSinh temp;
    for(p = L->head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->info.dtb > q->info.dtb){
                temp = p->info;
                p->info = q->info;
                q->info = temp;
            }
        }
    }
}

//tách danh sách thành 2 phần trên 5 và dưới 5
void split(List L, List *L1, List *L2){
    Node *p;
    for(p = L.head; p != NULL; p = p->next){
        if(p->info.dtb >= 5){
            append(L1, p->info);
        }
        else{
            append(L2, p->info);
        }
    }
}

int main(){
    int n;
    printf("Nhap so hoc sinh: ");
    scanf("%d", &n);
    init(&L);
    for(int i = 0; i < n; i++){
        HocSinh x;
        printf("Nhap ten hoc sinh: ");
        fflush(stdin);
        gets(x.name);
        printf("Nhap diem trung binh: ");
        scanf("%f", &x.dtb);
        push(&L, x);
    }
    printf("Danh sach hoc sinh vua nhap:\n");
    Node *p;
    for(p = L.head; p != NULL; p = p->next){
        printf("%-30s%-10.2f\n", p->info.name, p->info.dtb);
    }
    sort(&L);
    printf("\nDanh sach hoc sinh sau khi sap xep:\n");
    for(p = L.head; p != NULL; p = p->next){
        printf("%-30s%-10.2f\n", p->info.name, p->info.dtb);
    }
    List L1, L2;
    init(&L1);
    init(&L2);
    split(L, &L1, &L2);
    printf("\nDanh sach hoc sinh co diem trung binh >= 5:\n");
    for(p = L1.head; p != NULL; p = p->next){
        printf("%-30s%-10.2f\n", p->info.name, p->info.dtb);
    }
    printf("\nDanh sach hoc sinh co diem trung binh < 5:\n");
    for(p = L2.head; p != NULL; p = p->next){
        printf("%-30s%-10.2f\n", p->info.name, p->info.dtb);
    }
    return 0;
}