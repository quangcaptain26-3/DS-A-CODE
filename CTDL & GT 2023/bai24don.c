#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char name[30];
    int id;
    float dtb;
    struct SinhVien *next;
} SV;

typedef struct tagNode{
    SV data;
    struct tagNode *next;
} Node;

typedef struct tagList{
    Node *head;
    Node *tail;
    int spt;
} List;

List L;

void Init(List *L){
    L->head = L->tail = NULL;
    L->spt = 0;
}

int isEmpty(List L){
    return L.spt == 0;
}

void insert_head(List *L, SV x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
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

void insert_tail(List *L, SV x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
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

void FindByName(List L, char name[]){
    Node *p = L.head;
    while(p != NULL){
        if(strcmp(p->data.name, name) == 0){
            printf("%s %d %.2f\n", p->data.name, p->data.id, p->data.dtb);
        }
        p = p->next;
    }
}

void print(List L){
    Node *p = L.head;
    while(p != NULL){
        printf("%s %d %.2f\n", p->data.name, p->data.id, p->data.dtb);
        p = p->next;
    }
}

int main(){
    int n;
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    Init(&L);
    for(int i = 0; i < n; i++){
        SV x;
        printf("Nhap ten hoc sinh thu %d: ", i + 1);
        fflush(stdin);
        gets(x.name);
        printf("Nhap ma hoc sinh thu %d: ", i + 1);
        scanf("%d", &x.id);
        printf("Nhap diem trung binh hoc sinh thu %d: ", i + 1);
        scanf("%f", &x.dtb);
        insert_tail(&L, x);
    }
    printf("Danh sach hoc sinh:\n");
    print(L);
    char name[30];
    printf("Nhap ten hoc sinh can tim: ");
    fflush(stdin);
    gets(name);
    printf("Thong tin hoc sinh can tim:\n");
    FindByName(L, name);
    return 0;

}