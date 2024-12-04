#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[30];
    char id[10];
    float score1;
    float score2;
    float score3;
    struct node *next;

}node;


node *addHead(node *head, char name[], char id[], float score1, float score2, float score3){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score1 = score1;
    p->score2 = score2;
    p->score3 = score3;
    p->next = head;
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
        head = p;
    }
    else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = p;
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
    if(head == NULL){
        head = p;
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                p->next = temp->next;
                temp->next = p;
                return head;
            }
            temp = temp->next;
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
    if(head == NULL){
        head = p;
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                if(temp == head){
                    p->next = head;
                    head = p;
                }
                else{
                    node *q = head;
                    while(q->next != temp){
                        q = q->next;
                    }
                    q->next = p;
                    p->next = temp;
                }
                return head;
            }
            temp = temp->next;
        }
    }
    return head;
}

node *deleteNode(node *head, char x[]){
    if(head == NULL){
        printf("Danh sach rong!");
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                if(temp == head){
                    head = head->next;
                    free(temp);
                }
                else{
                    node *q = head;
                    while(q->next != temp){
                        q = q->next;
                    }
                    q->next = temp->next;
                    free(temp);
                }
                return head;
            }
            temp = temp->next;
        }
    }
    return head;
}

node *sort(node *head){
    node *p, *q, *end;
    for(end = NULL; end != head->next; end = p){
        for(p = head; p->next != end; p = p->next){
            q = p->next;
            if(p->score1 + p->score2 + p->score3 > q->score1 + q->score2 + q->score3){
                char temp[30];
                strcpy(temp, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, temp);

                strcpy(temp, p->id);
                strcpy(p->id, q->id);
                strcpy(q->id, temp);

                float temp1 = p->score1;
                p->score1 = q->score1;
                q->score1 = temp1;

                temp1 = p->score2;
                p->score2 = q->score2;
                q->score2 = temp1;

                temp1 = p->score3;
                p->score3 = q->score3;
                q->score3 = temp1;
            }
        }
    }
    return head;
}

void display(node *head){
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
        printf("Nhap ma sinh vien: ");
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
    printf("Danh sach sinh vien vua nhap:\n");
    display(head);
    printf("--------------------------------\n");
    printf("Danh sach sinh vien sau khi sap xep:\n");
    head = sort(head);
    display(head);
    printf("--------------------------------\n");
    int choice;
    do{
        printf("1. Xoa sinh vien\n");
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
                printf("--------------------------------\n");
                printf("Danh sach sinh vien sau khi xoa va sap xep lai:\n");
                head = sort(head);
                display(head);
                break;
            }
            case 2:{
                printf("Thoat chuong trinh!");
                break;
            }
            default:{
                printf("Nhap sai, nhap lai!\n");
                break;
            }
        }
    

}
    while(choice != 2);
    return 0;
}

