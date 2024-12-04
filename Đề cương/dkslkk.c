#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[30];
    char id[10];
    float score1;
    float score2;
    float score3;
    struct node *next;
    struct node *prev;
}node;

node *addHead(node *head, char name[], char id[], float score1, float score2, float score3){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score1 = score1;
    p->score2 = score2;
    p->score3 = score3;
    p->next = head;
    p->prev = NULL;
    if(head != NULL){
        head->prev = p;
    }
    head = p;
    return head;
}

node *addTail(node *head, char name[], char id[], float score1, float score2, float score3){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score1 = score1;
    p->score2 = score2;
    p->score3 = score3;
    p->next = NULL;
    if(head == NULL){
        p->prev = NULL;
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

node *addAfter(node *head, char name[], char id[], float score1, float score2, float score3, char x[]){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score1 = score1;
    p->score2 = score2;
    p->score3 = score3;
    p->next = NULL;
    p->prev = NULL;
    if(head == NULL){
        head = p;
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                break;
            }
            temp = temp->next;
        }
        if(temp != NULL){
            p->next = temp->next;
            p->prev = temp;
            temp->next = p;
            if(p->next != NULL){
                p->next->prev = p;
            }
        }
    }
    return head;
}

node *addBefore(node *head, char name[], char id[], float score1, float score2, float score3, char x[]){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score1 = score1;
    p->score2 = score2;
    p->score3 = score3;
    p->next = NULL;
    p->prev = NULL;
    if(head == NULL){
        head = p;
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                break;
            }
            temp = temp->next;
        }
        if(temp != NULL){
            if(temp == head){
                p->next = head;
                head->prev = p;
                head = p;
            }
            else{
                p->next = temp;
                p->prev = temp->prev;
                temp->prev->next = p;
                temp->prev = p;
            }
        }
    }
    return head;
}


node *deleteNode(node *head, char x[]){ 
    node *temp = head;
    while(temp != NULL){
        if(strcmp(temp->id, x) == 0){
            break;
        }
        temp = temp->next;
    }
    if(temp != NULL){
        if(temp == head){
            head = head->next;
            head->prev = NULL;
        }
        else{
            temp->prev->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
        }
        free(temp);
    }
    return head;
}

node *sort(node *head){
    node *p, *q;
    for(p = head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if((p->score1 + p->score2 + p->score3) / 3 > (q->score1 + q->score2 + q->score3) / 3){
                char temp[30];
                strcpy(temp, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, temp);
                strcpy(temp, p->id);
                strcpy(p->id, q->id);
                strcpy(q->id, temp);
                float t = p->score1;
                p->score1 = q->score1;
                q->score1 = t;
                t = p->score2;
                p->score2 = q->score2;
                q->score2 = t;
                t = p->score3;
                p->score3 = q->score3;
                q->score3 = t;
            }
        }
    }
    return head;
}



void printList(node *head){
    node *temp = head;
    while(temp != NULL){
        printf("%s %s %.1f %.1f %.1f\n", temp->name, temp->id, temp->score1, temp->score2, temp->score3);
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
        float score1, score2, score3;
        printf("Nhap ten: ");
        fflush(stdin);
        gets(name);
        printf("Nhap ma: ");
        fflush(stdin);
        gets(id);
        printf("Nhap diem 1: ");
        scanf("%f", &score1);
        printf("Nhap diem 2: ");
        scanf("%f", &score2);
        printf("Nhap diem 3: ");
        scanf("%f", &score3);
        head = addTail(head, name, id, score1, score2, score3);
    }
    printf("--------------------------------\n");
    printf("Danh sach sinh vien:\n");
    printList(head);
    printf("--------------------------------\n");
    head = sort(head);
    printf("Danh sach sau khi sap xep:\n");
    printList(head);
    printf("--------------------------------\n");
    int choice;
    do{
        printf("1. Xoa sinh vien theo ma\n");   
        printf("2. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                char x[10];
                printf("Nhap ma sinh vien can xoa: ");
                fflush(stdin);
                gets(x);
                head = deleteNode(head, x);
                printf("Danh sach sau khi xoa:\n");
                printList(head);
                printf("--------------------------------\n");
                break;
            }
            case 2:{
                break;
            }
            default:{
                printf("Nhap sai, nhap lai!\n");
                break;
            }
        }
    }while(choice != 2);
    return 0;

}

