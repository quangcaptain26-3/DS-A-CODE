#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct HocSinh{
    char name[30];
    int ma;
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

void Insertion_Sort(List *L){
    Node *p, *q, *temp;
    for(p = L->head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(strcmp(p->info.name, q->info.name) > 0){
                temp->info = p->info;
                p->info = q->info;
                q->info = temp->info;
            }
            else if(strcmp(p->info.name, q->info.name) == 0){
                if(p->info.ma > q->info.ma){
                    temp->info = p->info;
                    p->info = q->info;
                    q->info = temp->info;
                }
            }
        }
    }
}

void print(List L){
    Node *p;
    for(p = L.head; p != NULL; p = p->next){
        printf("%s %d %.2f\n", p->info.name, p->info.ma, p->info.dtb);
    }
}

int main(){
    int n;
    HocSinh x;
    init(&L);
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Nhap ten hoc sinh thu %d: ", i + 1);
        fflush(stdin);
        gets(x.name);
        printf("Nhap ma hoc sinh thu %d: ", i + 1);
        scanf("%d", &x.ma);
        printf("Nhap diem trung binh hoc sinh thu %d: ", i + 1);
        scanf("%f", &x.dtb);
        insert_Tail(&L, x);
    }
    printf("--------------------------------\n");
    printf("Danh sach hoc sinh truoc khi sap xep: \n");
    print(L);

    printf("--------------------------------\n");
    printf("Danh sach hoc sinh sau khi sap xep: \n");
    Insertion_Sort(&L);

    print(L);
}