#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

//từ bài 4 đến bài 10 là các bài tập về danh sách liên kết đơn
//khai báo cấu trúc danh sách liên kết đơn. thông tin chưa mỗi nút gồm: họ tên, mã sv, điểm trung bình
typedef struct node{
    char name[30];
    char id[10];
    float score;
    struct node *next;
}node;

//thêm một nút vào đầu danh sách
node *addHead(node *head, char name[], char id[], float score){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score = score;
    p->next = head;
    head = p;
    return head;
}

//thêm một nút vào cuối danh sách
node *addTail(node *head, char name[], char id[], float score){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score = score;
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

//thêm một nút vào sau nút mới vào trước nút có mã sinh viên là x
node *addAfter(node *head, char name[], char id[], float score, char x[]){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score = score;
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

//thêm một nút mới vào trước nút có mã sinh viên là x
node *addBefore(node *head, char name[], char id[], float score, char x[]){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score = score;
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
                    return head;
                }
                else{
                    node *q = head;
                    while(q->next != temp){
                        q = q->next;
                    }
                    q->next = p;
                    p->next = temp;
                    return head;
                }
            }
            temp = temp->next;
        }
    }
    return head;
}

//ví dụ sắp xếp theo điểm trung bình, thêm một nút vào trong danh sách liên kết đơn sao cho danh sách vẫn được sắp xếp
node *addSort(node *head, char name[], char id[], float score){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->name, name);
    strcpy(p->id, id);
    p->score = score;
    p->next = NULL;
    if(head == NULL){
        head = p;
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(temp->score > score){
                if(temp == head){
                    p->next = head;
                    head = p;
                    return head;
                }
                else{
                    node *q = head;
                    while(q->next != temp){
                        q = q->next;
                    }
                    q->next = p;
                    p->next = temp;
                    return head;
                }
            }
            temp = temp->next;
        }
        node *q = head;
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
    return head;
}

//xóa nút đầu danh sách
node *delHead(node *head){
    if(head == NULL){
        printf("Danh sach rong!");
    }
    else{
        head = head->next;
    }
    return head;
}

//xóa nút cuối danh sách
node *delTail(node *head){
    if(head == NULL){
        printf("Danh sach rong!");
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


//xoá nút có mã sinh viên là x
node *delNode(node *head, char x[]){
    if(head == NULL){
        printf("Danh sach rong!");
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                if(temp == head){
                    head = head->next;
                    return head;
                }
                else{
                    node *q = head;
                    while(q->next != temp){
                        q = q->next;
                    }
                    q->next = temp->next;
                    return head;
                }
            }
            temp = temp->next;
        }
    }
    return head;
}

//làm hàm main để nhập n sinh viên
int main(){
    node *head = NULL;
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char name[30];
        char id[10];
        float score;
        printf("Nhap thong tin sinh vien thu %d\n", i + 1);
        printf("Nhap ho ten: ");
        fflush(stdin);
        gets(name);
        printf("Nhap ma sinh vien: ");
        fflush(stdin);
        gets(id);
        printf("Nhap diem trung binh: ");
        scanf("%f", &score);
        head = addTail(head, name, id, score);
    }
    return 0;
}

//độ phức tạp của thuật toán: O(n)