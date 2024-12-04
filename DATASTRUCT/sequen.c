#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct{
    char hoten[30];
    int masv;
    float diemtb;
} Data;

//áp dụng trên danh sách liên kết đơn
typedef struct tagnode{
    Data infor;
    struct tagnode *link;
} Node;

typedef struct{
    Node *head;
    Node *tail;
    int spt;
} List;

void init(List *L){
    L->head = L->tail = NULL;
    L->spt = 0;
}

int empty(List L){
    return L.spt == 0;
}

void insert_head(List *L, char *hoten, int ma, float diemtb){
    Node *p = (Node*)malloc(sizeof(Node));
    if(p == NULL){
        printf("Khong du bo nho\n");
        return;
    }
    p->infor.masv = ma;
    p->infor.diemtb = diemtb;
    strcpy(p->infor.hoten, hoten);
    p->link = NULL;
    if(empty(*L)){
        L->head = L->tail = p;
    }else{
        p->link = L->head;
        L->head = p;
    }
    L->spt++;
}

void bubble_sort(List *L){
    Node *p, *q;
    Data temp;
    for(p = L->head; p != NULL; p = p->link){
        for(q = p->link; q != NULL; q = q->link){
            if(p->infor.diemtb > q->infor.diemtb){
                temp = p->infor;
                p->infor = q->infor;
                q->infor = temp;
            }
        }
    }
}

void print_list(List L){
    Node *p;
    for(p = L.head; p != NULL; p = p->link){
        printf("%-30s%-10d%-10.2f\n", p->infor.hoten, p->infor.masv, p->infor.diemtb);
    }
}

int main(){
    List L;
    init(&L);
    insert_head(&L, "Nguyen Van A", 123, 8.5);
    insert_head(&L, "Nguyen Van B", 124, 7.5);
    insert_head(&L, "Nguyen Van C", 125, 9.5);
    insert_head(&L, "Nguyen Van D", 126, 6.5);
    insert_head(&L, "Nguyen Van E", 127, 5.5);
    printf("Danh sach sinh vien truoc khi sap xep:\n");
    print_list(L);
    printf("Danh sach sinh vien sau khi sap xep:\n");
    bubble_sort(&L);
    print_list(L);
    return 0;
}

//đánh giá thuật toán   
// - Thời gian chạy: O(n^2)
// - Không gian bộ nhớ: O(1)
// - Ưu điểm: đơn giản, dễ hiểu, dễ cài đặt
// - Nhược điểm: thời gian chạy chậm, không hiệu quả với dữ liệu lớn