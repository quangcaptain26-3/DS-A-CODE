//Cho ds liên kết đơn các nhân viên (tên, mã, hsl, pc, mã phòng ban). Bạn hãy viết hàm cho phép sửa thông tin của một nhân viên. Viết hàm tìm kiếm nhân viên theo mã nhân viên.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nhanvien
{
    char hoten[30];
    char manv[10];
    float hsl;
    float phucap;
    float luong;
    struct nhanvien *next;
} node;

node *createNode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

void insertNode(node **head, node *temp)
{
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        node *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void nhap(node **head)
{
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        node *temp = createNode();
        printf("Nhap thong tin nhan vien thu %d\n", i + 1);
        printf("Nhap ho ten: ");
        fflush(stdin);
        gets(temp->hoten);
        printf("Nhap ma nhan vien: ");
        fflush(stdin);
        gets(temp->manv);
        printf("Nhap he so luong: ");
        scanf("%f", &temp->hsl);
        printf("Nhap phu cap: ");
        scanf("%f", &temp->phucap);
        insertNode(head, temp);
    }
}

void xuat(node **head){
    node *p = *head;
    while (p != NULL)
    {
        printf("%s\t%s\t%.2f\t%.2f\t%.2f\n", p->hoten, p->manv, p->hsl, p->phucap, p->luong);
        p = p->next;
    }
}

void timkiem(node **head){
    char ma[10];
    printf("Nhap ma nhan vien can tim: ");
    fflush(stdin);
    gets(ma);
    node *p = *head;
    while (p != NULL)
    {
        if (strcmp(p->manv, ma) == 0)
        {
            printf("%s\t%s\t%.2f\t%.2f\t%.2f\n", p->hoten, p->manv, p->hsl, p->phucap, p->luong);
            return;
        }
        p = p->next;
    }
    printf("Khong tim thay nhan vien co ma %s\n", ma);
}

int main(){
    node *head = NULL;
    nhap(&head);
    xuat(&head);
    timkiem(&head);
    return 0;
}