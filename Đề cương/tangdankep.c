#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[30];
    char id[10];
    float score;
    struct node *next;
    struct node *prev;
}node;

node *addHead(node *head, char name[], char id[], float score){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score = score;
    p->next = head;
    p->prev = NULL;
    if(head != NULL){
        head->prev = p;
    }
    head = p;
    return head;
}

node *addTail(node *head, char name[], char id[], float score){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score = score;
    p->next = NULL;
    p->prev = NULL;
    if(head == NULL){
        head = p;
    }
    else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
    return head;
}

//nhap danh sach sinh vien
node *nhap(node *head){
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char name[30];
        char id[10];
        float score;
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        fflush(stdin);
        gets(name);
        printf("Nhap ma sinh vien thu %d: ", i + 1);
        fflush(stdin);
        gets(id);
        printf("Nhap diem trung binh sinh vien thu %d: ", i + 1);
        scanf("%f", &score);
        head = addTail(head, name, id, score);
    }
    return head;
}

//in danh sach sinh vien
void in(node *head){
    printf("%-30s%-10s%-10s\n", "Ho ten", "Ma SV", "Diem TB");
    node *temp = head;
    while(temp != NULL){
        printf("%-30s%-10s%-10.2f\n", temp->name, temp->id, temp->score);
        temp = temp->next;
    }
}

//chia danh sach sinh vien thanh 2 danh sach: danh sach sinh vien co diem TB >= 5 va danh sach sinh vien co diem TB < 5
void chia(node *head, node *head1, node *head2){
    node *temp = head;
    while(temp != NULL){
        if(temp->score >= 5){
            head1 = addTail(head1, temp->name, temp->id, temp->score);
        }
        else{
            head2 = addTail(head2, temp->name, temp->id, temp->score);
        }
        temp = temp->next;
    }
    printf("Danh sach sinh vien co diem TB >= 5:\n");
    in(head1);
    printf("Danh sach sinh vien co diem TB < 5:\n");
    in(head2);
}

int main(){
    node *head = NULL;
    node *head1 = NULL;
    node *head2 = NULL;
    head = nhap(head);
    printf("Danh sach sinh vien vua nhap:\n");
    in(head);
    chia(head, head1, head2);
    return 0;
}