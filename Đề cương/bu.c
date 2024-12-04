#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
    char name[30];
    char id[10];
    float d1;
    float d2;
    float d3;
    struct node *next;
    struct node *prev;
} node;

node *addHead(node *head, char name[], char id[], float d1, float d2, float d3){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->d1 = d1;
    p->d2 = d2;
    p->d3 = d3;
    p->next = head;
    p->prev = NULL;
    if(head != NULL){
        head->prev = p;
    }
    head = p;
    return head;
}

node *addTail(node *head, char name[], char id[], float d1, float d2, float d3){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->d1 = d1;
    p->d2 = d2;
    p->d3 = d3;
    p->next = NULL;
    if(head == NULL){
        head = p;
    } else {
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
    return head;
}

float dtb(float d1, float d2, float d3){
    return (d1 + d2 + d3) / 3;
}

void find(node *head){
    node *temp = head;
    node *max = head;
    node *start = head;
    node *end = head;
    int count = 1;
    int maxCount = 1;
    while(temp->next != NULL){
        if(dtb(temp->d1, temp->d2, temp->d3) >= dtb(temp->next->d1, temp->next->d2, temp->next->d3)){
            count++;
            end = temp->next;
        } else {
            if(count > maxCount){
                maxCount = count;
                max = start;
            }
            count = 1;
            start = temp->next;
            end = temp->next;
        }
        temp = temp->next;
    }
    if(count > maxCount){
        maxCount = count;
        max = start;
    }
    printf("Doan dai nhat: \n");
    while(max != end){
        printf("%s %s %.2f %.2f %.2f\n", max->name, max->id, max->d1, max->d2, max->d3);
        max = max->next;
    }
    printf("%s %s %.2f %.2f %.2f\n", max->name, max->id, max->d1, max->d2, max->d3);
}

node *delete(node *head){
    node *temp = head;
    node *max = head;
    node *start = head;
    node *end = head;
    int count = 1;
    int maxCount = 1;
    while(temp->next != NULL){
        if(dtb(temp->d1, temp->d2, temp->d3) >= dtb(temp->next->d1, temp->next->d2, temp->next->d3)){
            count++;
            end = temp->next;
        } else {
            if(count > maxCount){
                maxCount = count;
                max = start;
            }
            count = 1;
            start = temp->next;
            end = temp->next;
        }
        temp = temp->next;
    }
    if(count > maxCount){
        maxCount = count;
        max = start;
    }
    node *p = head;
    while(p != max){
        node *temp = p;
        p = p->next;
        free(temp);
    }
    node *q = end->next;
    while(q != NULL){
        node *temp = q;
        q = q->next;
        free(temp);
    }
    end->next = NULL;
    return head;
}

void display(node *head){
    node *temp = head;
    while(temp != NULL){
        printf("%s %s %.2f %.2f %.2f\n", temp->name, temp->id, temp->d1, temp->d2, temp->d3);
        temp = temp->next;
    }
}

int main(){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    node *head = NULL;
    for(int i = 0; i < n; i++){
        char name[30];
        char id[10];
        float d1, d2, d3;
        printf("Nhap ten: ");
        fflush(stdin);
        gets(name);
        printf("Nhap ma: ");
        fflush(stdin);
        gets(id);
        printf("Nhap diem 1: ");
        scanf("%f", &d1);
        printf("Nhap diem 2: ");
        scanf("%f", &d2);
        printf("Nhap diem 3: ");
        scanf("%f", &d3);
        head = addTail(head, name, id, d1, d2, d3);
    }
    printf("Danh sach sinh vien: \n");
    display(head);
    find(head);
    head = delete(head);
    printf("Danh sach sinh vien sau khi xoa: \n");
    display(head);
    return 0;
}