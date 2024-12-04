#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien{
    char name[30];
    int id;
    float dtb;
    struct SinhVien *next;
    struct SinhVien *prev;
} SV;

typedef struct tagNode{
    SV data;
    struct tagNode *next;
    struct tagNode *prev;
} Node;


void push(Node **head, SV x){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
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
    p->data = x;
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

void FindByName(Node *head, char name[]){
    Node *temp = head;
    while(temp != NULL){
        if(strcmp(temp->data.name, name) == 0){
            printf("%s %d %.2f\n", temp->data.name, temp->data.id, temp->data.dtb);
        }
        temp = temp->next;
    }
}

void printList(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%s %d %.2f\n", temp->data.name, temp->data.id, temp->data.dtb);
        temp = temp->next;
    }
}

int main(){
    int n;
    Node *head = NULL;
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        SV x;
        printf("Nhap ten hoc sinh thu %d: ", i + 1);
        fflush(stdin);
        gets(x.name);
        printf("Nhap ma hoc sinh thu %d: ", i + 1);
        scanf("%d", &x.id);
        printf("Nhap diem trung binh hoc sinh thu %d: ", i + 1);
        scanf("%f", &x.dtb);
        append(&head, x);
    }
    printf("--------------------\n");
    printf("Danh sach hoc sinh:\n");
    printList(head);
    printf("--------------------\n");
    char name[30];
    printf("Nhap ten hoc sinh can tim: ");
    fflush(stdin);
    gets(name);
    FindByName(head, name);
    return 0;
}