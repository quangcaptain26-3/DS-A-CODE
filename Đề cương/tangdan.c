#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char ten[30];
    char masv[10];
    float dtb;
    struct node *next;
}node;

node *addHead(node *head, char ten[], char masv[], float dtb){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->ten, ten);
    strcpy(p->masv, masv);
    p->dtb = dtb;
    p->next = head;
    head = p;
    return head;
}

node *addTail(node *head, char ten[], char masv[], float dtb){
    node *p = (node*)malloc(sizeof(node));
    strcpy(p->ten, ten);
    strcpy(p->masv, masv);
    p->dtb = dtb;
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

//nhap cac sinh vien vao danh sach
node *nhap(node *head){
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char ten[30];
        char masv[10];
        float dtb;
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        fflush(stdin);
        gets(ten);
        printf("Nhap ma sinh vien thu %d: ", i + 1);
        fflush(stdin);
        gets(masv);
        printf("Nhap diem trung binh sinh vien thu %d: ", i + 1);
        scanf("%f", &dtb);
        head = addTail(head, ten, masv, dtb);
    }
    return head;
}

//in danh sach sinh vien

node *xuat(node *head){
    printf("%-30s%-10s%-10s\n", "Ho va ten", "Ma SV", "DTB");
    node *temp = head;
    while(temp != NULL){
        printf("%-30s%-10s%-10.2f\n", temp->ten, temp->masv, temp->dtb);
        temp = temp->next;
    }
    return head;
}

//tach danh sach sinh vien co diem trung binh >= 5.0 va < 5.0
node *tach(node *head, node **head1, node **head2){
    node *temp = head;
    while(temp != NULL){
        if(temp->dtb >= 5.0){
            *head1 = addTail(*head1, temp->ten, temp->masv, temp->dtb);
        }
        else{
            *head2 = addTail(*head2, temp->ten, temp->masv, temp->dtb);
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    node *head = NULL;
    node *head1 = NULL;
    node *head2 = NULL;
    head = nhap(head);
    printf("Danh sach sinh vien vua nhap:\n");
    head = xuat(head);
    head = tach(head, &head1, &head2);
    printf("Danh sach sinh vien co diem trung binh >= 5.0:\n");
    head1 = xuat(head1);
    printf("Danh sach sinh vien co diem trung binh < 5.0:\n");
    head2 = xuat(head2);
    return 0;
}
