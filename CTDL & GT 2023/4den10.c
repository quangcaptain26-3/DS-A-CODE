#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien
{
    char hoten[30];
    char msv[10];
    float dtb;
    struct SinhVien *next;
} SV;

typedef struct tagNode{
    SV info;
    struct tagNode *next;
} Node;

typedef struct tagList{
    Node *head;
    Node *tail;
    int spt;
} List;

List L;

void init(List *L){
    L->head = L->tail = NULL;
    L->spt = 0;
}

int emptyList(List L){
    return (L.spt == 0);
}

void insert_Head(List *L, SV x){
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

void insert_Tail(List *L, SV x){
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

void insert_after(List *L, Node *q, SV x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(q != NULL){
        p->next = q->next;
        q->next = p;
        if(q == L->tail){
            L->tail = p;
        }
    }
    else{
        insert_Head(L, x);
    }
    L->spt++;
}

void insert_Before(List *L, Node *q, SV x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(q != NULL){
        if(q == L->head){
            insert_Head(L, x);
        }
        else{
            Node *i = L->head;
            while(i->next != q){
                i = i->next;
            }
            p->next = q;
            i->next = p;
        }
    }
    else{
        insert_Head(L, x);
    }
    L->spt++;
}

void insert_pos(List *L, int pos, SV x){
    if(pos < 0 || pos > L->spt){
        printf("Vi tri chen khong hop le!\n");
    }
    else{
        if(pos == 0){
            insert_Head(L, x);
        }
        else if(pos == L->spt){
            insert_Tail(L, x);
        }
        else{
            Node *p = L->head;
            int i = 0;
            while(i != pos - 1){
                p = p->next;
                i++;
            }
            insert_after(L, p, x);
        }
    }
}


void insert_sort(List *L, SV x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    if(emptyList(*L)){
        L->head = L->tail = p;
    }
    else{
        Node *i = L->head;
        while(i != NULL && i->info.dtb < x.dtb){
            i = i->next;
        }
        if(i == L->head){
            insert_Head(L, x);
        }
        else if(i == NULL){
            insert_Tail(L, x);
        }
        else{
            insert_Before(L, i, x);
        }
    }
    L->spt++;
}

void del_Head(List *L){
    if(emptyList(*L)){
        printf("Danh sach rong!\n");
    }
    else{
        Node *p = L->head;
        L->head = L->head->next;
        free(p);
        L->spt--;
    }
}

void del_Tail(List *L){
    if(emptyList(*L)){
        printf("Danh sach rong!\n");
    }
    else{
        Node *p = L->head;
        while(p->next != L->tail){
            p = p->next;
        }
        free(L->tail);
        L->tail = p;
        L->tail->next = NULL;
        L->spt--;
    }
}


void del_x(List *L, char x[]){
    if(emptyList(*L)){
        printf("Danh sach rong!\n");
    }
    else{
        Node *p = L->head;
        while(p != NULL && strcmp(p->info.msv, x) != 0){
            p = p->next;
        }
        if(p == NULL){
            printf("Khong tim thay sinh vien co ma %s!\n", x);
        }
        else{
            if(p == L->head){
                del_Head(L);
            }
            else if(p == L->tail){
                del_Tail(L);
            }
            else{
                Node *q = L->head;
                while(q->next != p){
                    q = q->next;
                }
                q->next = p->next;
                free(p);
                L->spt--;
            }
        }
    }
}

void nhap(SV *x){
    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(x->hoten);
    printf("Nhap ma sinh vien: ");
    fflush(stdin);
    gets(x->msv);
    printf("Nhap diem trung binh: ");
    scanf("%f", &x->dtb);
}

void nhap_ds(List *L){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    init(L);
    for(int i = 0; i < n; i++){
        SV x;
        nhap(&x);
        insert_sort(L, x);
    }
}

void xuat(SV x){
    printf("%-30s%-10s%-10.2f\n", x.hoten, x.msv, x.dtb);
}

void xuat_ds(List L){
    printf("%-30s%-10s%-10s\n", "Ho ten", "MSV", "DTB");
    Node *p = L.head;
    while(p != NULL){
        xuat(p->info);
        p = p->next;
    }
}

void menu(){
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach sinh vien\n");
    printf("3. Them sinh vien vao dau danh sach\n");
    printf("4. Them sinh vien vao cuoi danh sach\n");
    printf("5. Them sinh vien vao sau sinh vien co ma x\n");
    printf("6. Them sinh vien vao truoc sinh vien co ma x\n");
    printf("7. Them sinh vien vao vi tri pos\n");
    printf("8. Xoa sinh vien dau danh sach\n");
    printf("9. Xoa sinh vien cuoi danh sach\n");
    printf("10. Xoa sinh vien co ma x\n");
    printf("11. Thoat\n");
}

int main(){
    int choice;
    char x[10];
    SV y;
    do{
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                nhap_ds(&L);
                break;
            case 2:
                xuat_ds(L);
                break;
            case 3:
                nhap(&y);
                insert_Head(&L, y);
                break;
            case 4:
                nhap(&y);
                insert_Tail(&L, y);
                break;
            case 5:
                nhap(&y);
                printf("Nhap ma sinh vien can them vao sau: ");
                fflush(stdin);
                gets(x);
                insert_after(&L, L.head, y);
                break;
            case 6:
                nhap(&y);
                printf("Nhap ma sinh vien can them vao truoc: ");
                fflush(stdin);
                gets(x);
                insert_Before(&L, L.head, y);
                break;
            case 7:
                nhap(&y);
                int pos;
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                insert_pos(&L, pos, y);
                break;
            case 8:
                del_Head(&L);
                break;
            case 9:
                del_Tail(&L);
                break;
            case 10:
                printf("Nhap ma sinh vien can xoa: ");
                fflush(stdin);
                gets(x);
                del_x(&L, x);
                break;
            case 11:
                printf("Thoat!\n");
                break;
            default:
                printf("Nhap sai, nhap lai!\n");
                break;
        }
    }while(choice != 11);
    return 0;
}