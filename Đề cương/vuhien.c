//Viết chương trình tạo dslk đơn chứa thông tin sinh viên (họ tên, mã, điểm môn 1, 2, 3)
//Thực hiện xoá 1 số nút trong ds đó sao cho sau khi xoá xong ta được 1 ds mới sắp xếp tăng dần theo điểm trung bình
//Yêu cầu số nút phải xoá là ít nhất

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

//Thực hiện xoá 1 số nút trong ds đó sao cho sau khi xoá xong ta được 1 ds mới sắp xếp tăng dần theo điểm trung bình
//Yêu cầu số nút phải xoá là ít nhất

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

node *deleteHead(node *head){
    if(head == NULL){
        return head;
    }
    else{
        head = head->next;
    }
    return head;
}

node *deleteTail(node *head){
    if(head == NULL || head->next == NULL){
        return deleteHead(head);
    }
    else{
        node *temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
    }
    return head;
}

node *deleteAfter(node *head, char x[]){
    if(head == NULL || head->next == NULL){
        return head;
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                if(temp->next == NULL){
                    return head;
                }
                else{
                    temp->next = temp->next->next;
                    return head;
                }
            }
            temp = temp->next;
        }
    }
    return head;
}


node *deleteBefore(node *head, char x[]){
    if(head == NULL || head->next == NULL){
        return head;
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                if(temp == head){
                    return head;
                }
                else{
                    node *q = head;
                    while(q->next->next != temp){
                        q = q->next;
                    }
                    q->next = temp;
                    return head;
                }
            }
            temp = temp->next;
        }
    }
    return head;
}


node *bubbleSort(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    else{
        node *p = head;
        while(p->next != NULL){
            node *q = p->next;
            while(q != NULL){
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
                q = q->next;
            }
            p = p->next;
        }
    }
    return head;
}

int main(){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    node *head = NULL;
    for(int i = 0; i < n; i++){
        char name[30];
        char id[10];
        float score1;
        float score2;
        float score3;
        printf("Nhap thong tin sinh vien thu %d\n", i + 1);
        printf("Nhap ho ten: ");
        fflush(stdin);
        gets(name);
        printf("Nhap ma sinh vien: ");
        fflush(stdin);
        gets(id);
        printf("Nhap diem mon 1: ");
        scanf("%f", &score1);
        printf("Nhap diem mon 2: ");
        scanf("%f", &score2);
        printf("Nhap diem mon 3: ");
        scanf("%f", &score3);
        head = addTail(head, name, id, score1, score2, score3);
    }
    printf("--------------------\n");
    printf("\nDanh sach sinh vien vua nhap la:\n");
    node *p = head;
    while(p != NULL){
        printf("%s\t%s\t%.2f\t%.2f\t%.2f\n", p->name, p->id, p->score1, p->score2, p->score3);
        p = p->next;
    }
    printf("--------------------\n");
    printf("\nDanh sach sinh vien sau khi sap xep la:\n");
    head = bubbleSort(head);
    p = head;
    while(p != NULL){
        printf("%s\t%s\t%.2f\t%.2f\t%.2f\n", p->name, p->id, p->score1, p->score2, p->score3);
        p = p->next;
    }
    printf("--------------------\n");
    printf("\nDanh sach sinh vien sau khi xoa la:\n");
    head = deleteHead(head);
    head = deleteTail(head);
    p = head;
    while(p != NULL){
        printf("%s\t%s\t%.2f\t%.2f\t%.2f\n", p->name, p->id, p->score1, p->score2, p->score3);
        p = p->next;
    }
    return 0;
}

