#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char name[30];
    int id;
    float dtb;
    struct SinhVien *next;
    struct SinhVien *prev;
}SV;

typedef struct tagNode{
    SV info;
    struct tagNode *next;
    struct tagNode *prev;
}Node;

void push(Node **head, SV x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    if(*head == NULL){
        *head = p;
    }
    else{
        p->next = *head;
        (*head)->prev = p;
        *head = p;
    }
}

void append(Node **head, SV x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    if(*head == NULL){
        *head = p;
    }
    else{
        Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}

void selection_Sort(Node **head){
    Node *p, *q;
    SV temp;
    //tăng dần theo tên, cùng tên theo id
    for(p = *head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(strcmp(p->info.name, q->info.name) > 0){
                temp = p->info;
                p->info = q->info;
                q->info = temp;
            }
            else if(strcmp(p->info.name, q->info.name) == 0){
                if(p->info.id > q->info.id){
                    temp = p->info;
                    p->info = q->info;
                    q->info = temp;
                }
            }
        }
    }
}

void print(Node *head){
    Node *p;
    for(p = head; p != NULL; p = p->next){
        printf("%s %d %.2f\n", p->info.name, p->info.id, p->info.dtb);
    }
}

int main(){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    SV x;
    Node *head = NULL;
    for(int i = 0; i < n; i++){
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        fflush(stdin);
        gets(x.name);
        printf("Nhap ma sinh vien thu %d: ", i + 1);
        scanf("%d", &x.id);
        printf("Nhap diem trung binh sinh vien thu %d: ", i + 1);
        scanf("%f", &x.dtb);
        append(&head, x);
    }
    printf("--------------------------------\n");
    printf("Danh sach sinh vien truoc khi sap xep: \n");
    print(head);

    printf("--------------------------------\n");
    printf("Danh sach sinh vien sau khi sap xep: \n");
    selection_Sort(&head);
    print(head);
    return 0;
}