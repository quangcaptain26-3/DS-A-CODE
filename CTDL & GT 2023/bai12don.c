#include<stdio.h>
#include<stdlib.h>

typedef struct HocSinh{
    char name[30];
    float dtb;
    struct HocSinh *next;
}HocSinh;

typedef struct tagNode{
    HocSinh info;
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

void insert_Head(List *L, HocSinh x){
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

void insert_Tail(List *L, HocSinh x){
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

//tách thành 2 phần: 1 phần có điểm trung bình >= 5, 1 phần có điểm trung bình < 5
void split(List *L, List *L1, List *L2){
    Node *p;
    for(p = L->head; p != NULL; p = p->next){
        if(p->info.dtb >= 5){
            insert_Tail(L1, p->info);
        }
        else{
            insert_Tail(L2, p->info);
        }
    }
}

int main(){
    int n;
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    init(&L);
    for(int i = 0; i < n; i++){
        HocSinh x;
        printf("Nhap thong tin hoc sinh thu %d:\n", i+1);
        printf("Nhap ten: ");
        fflush(stdin);
        gets(x.name);
        printf("Nhap diem trung binh: ");
        scanf("%f", &x.dtb);
        insert_Tail(&L, x);
    }

    printf("\nDanh sach hoc sinh vua nhap:\n");
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
    split(&L, &L1, &L2);
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