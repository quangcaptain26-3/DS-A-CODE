#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        temp->luong = temp->hsl * 2000000 + temp->phucap;
        insertNode(head, temp);
    }
}

void xuat(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        printf("%-30s %-10s %-10.2f %-10.2f %-10.2f\n", p->hoten, p->manv, p->hsl, p->phucap, p->luong);
        p = p->next;
    }
}

void swap(node *a, node *b)
{
    node temp = *a;
    *a = *b;
    *b = temp;
}


void sapxep(node *head)
{
    node *p, *q;
    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->luong < q->luong)
            {
                swap(p, q);
            }
        }
    }
}

void xoa(node **head, int n)
{
    node *p = *head;
    for (int i = 0; i < n - 1; i++)
    {
        p = p->next;
    }
    node *temp = p->next;
    p->next = temp->next;
    free(temp);
}

int main()
{
    node *head = NULL;
    nhap(&head);
    printf("\nDanh sach nhan vien\n");
    printf("%-30s %-10s %-10s %-10s %-10s\n", "Ho ten", "Ma NV", "He so luong", "Phu cap", "Luong");
    xuat(head);
    sapxep(head);
    printf("\nDanh sach nhan vien sau khi sap xep\n");
    printf("%-30s %-10s %-10s %-10s %-10s\n", "Ho ten", "Ma NV", "He so luong", "Phu cap", "Luong");
    xuat(head);
    int n;
    printf("\nNhap so luong nhan vien can xoa: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        xoa(&head, i + 1);
    }
    printf("\nDanh sach nhan vien sau khi xoa\n");
    printf("%-30s %-10s %-10s %-10s %-10s\n", "Ho ten", "Ma NV", "He so luong", "Phu cap", "Luong");
    xuat(head);
    return 0;
}