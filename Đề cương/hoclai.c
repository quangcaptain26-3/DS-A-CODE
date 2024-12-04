#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[30];
    int id;
    float d1;
    float d2;
    float d3;
    struct node *next;
} node;

node *addHead(node *head, char name[], int id, float d1, float d2, float d3){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    p->id = id;
    p->d1 = d1;
    p->d2 = d2;
    p->d3 = d3;
    p->next = head;
    head = p;
    return head;
}

node *addTail(node *head, char name[], int id, float d1, float d2, float d3){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    p->id = id;
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
    }
    return head;
}

void hocLai(node *head){
    node *temp = head;
    int count = 0;
    while(temp != NULL){
        if(temp->d1 < 4 || temp->d2 < 4 || temp->d3 < 4){
            count++;
        }
        temp = temp->next;
    }
    printf("Co %d sinh vien hoc lai\n", count);
}

void printHocLai(node *head){
    node *temp = head;
    while(temp != NULL){
        if(temp->d1 < 4 || temp->d2 < 4 || temp->d3 < 4){
            printf("%s %d %.1f %.1f %.1f\n", temp->name, temp->id, temp->d1, temp->d2, temp->d3);
        }
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
        int id;
        float d1, d2, d3;
        printf("Nhap ten: ");
        fflush(stdin);
        gets(name);
        printf("Nhap ma sinh vien: ");
        scanf("%d", &id);
        printf("Nhap diem 3 mon: ");
        scanf("%f%f%f", &d1, &d2, &d3);
        head = addTail(head, name, id, d1, d2, d3);
    }
    printf("-------------------------\n");
    printf("Danh sach sinh vien:\n");
    node *temp = head;
    while(temp != NULL){
        printf("%s %d %.1f %.1f %.1f\n", temp->name, temp->id, temp->d1, temp->d2, temp->d3);
        temp = temp->next;
    }
    
    printf("-------------------------\n");
    printf("Sinh vien hoc lai:\n");
    hocLai(head);
    printHocLai(head);
    return 0;
}

