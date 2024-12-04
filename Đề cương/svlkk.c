#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//bài 4 đến bài 10 là các bài tập về danh sách liên kết kép
//khai báo cấu trúc danh sách liên kết kép, thông tin mỗi nút gồm: họ tên, mã sv, dtb
typedef struct node{
    char name[30];
    char id[10];
    float score;
    struct node *next;
    struct node *prev;
}node;

//thêm một nút vào đầu danh sách
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

//thêm một nút vào cuối danh sách
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

//thêm một nút vào sau nút có mã sinh viên là x
node *addAfter(node *head, char name[], char id[], float score, char x[]){
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
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                p->next = temp->next;
                p->prev = temp;
                temp->next = p;
                if(p->next != NULL){
                    p->next->prev = p;
                }
                break;
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
    p->prev = NULL;
    if(head == NULL){
        head = p;
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                p->next = temp;
                p->prev = temp->prev;
                temp->prev = p;
                if(p->prev != NULL){
                    p->prev->next = p;
                }
                else{
                    head = p;
                }
                break;
            }
            temp = temp->next;
        }
    }
    return head;
}

//sắp xếp theo điểm trung bình, thêm một nút vào trong danh sách liên kết kép sao cho danh sách vẫn được sắp xếp
node *addSort(node *head, char name[], char id[], float score){
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
        while(temp != NULL){
            if(temp->score > score){
                break;
            }
            temp = temp->next;
        }
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
    return head;
}

//xoá nút đầu danh sách
node *delHead(node *head){
    if(head == NULL){
        printf("Danh sach rong!\n");
    }
    else{
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
    return head;
}

//xoá nút cuối danh sách
node *delTail(node *head){
    if(head == NULL){
        printf("Danh sach rong!\n");
    }
    else{
        node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    return head;
}

//xoá nút có mã sinh viên là x
node *delNode(node *head, char x[]){
    if(head == NULL){
        printf("Danh sach rong!\n");
    }
    else{
        node *temp = head;
        while(temp != NULL){
            if(strcmp(temp->id, x) == 0){
                if(temp == head){
                    head = head->next;
                    free(temp);
                    head->prev = NULL;
                }
                else{
                    temp->prev->next = temp->next;
                    if(temp->next != NULL){
                        temp->next->prev = temp->prev;
                    }
                    free(temp);
                }
                break;
            }
            temp = temp->next;
        }
    }
    return head;
}



//main function
int main(){
    node *head = NULL;
    head = addHead(head, "Nguyen Van A", "SV001", 8.5);
    head = addHead(head, "Nguyen Van B", "SV002", 7.5);
    head = addHead(head, "Nguyen Van C", "SV003", 9.5);
    head = addTail(head, "Nguyen Van D", "SV004", 6.5);
    head = addTail(head, "Nguyen Van E", "SV005", 5.5);
    head = addTail(head, "Nguyen Van F", "SV006", 4.5);
    head = addAfter(head, "Nguyen Van G", "SV007", 3.5, "SV004");
    head = addBefore(head, "Nguyen Van H", "SV008", 2.5, "SV005");
    head = addSort(head, "Nguyen Van I", "SV009", 10);
    head = addSort(head, "Nguyen Van K", "SV010", 1);
    head = delHead(head);
    head = delTail(head);
    head = delNode(head, "SV007");
    node *temp = head;
    while(temp != NULL){
        printf("%s %s %.2f\n", temp->name, temp->id, temp->score);
        temp = temp->next;
    }
    return 0;
}