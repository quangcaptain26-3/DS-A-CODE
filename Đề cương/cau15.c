//Cho ds liên kết đơn các nhân viên (tên, mã, hsl, pc, mã phòng ban). Bạn hãy tính trung bình lương của từng phòng ban. Biết lương của nhân viên được tính theo công thức hsl*2000+pc

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
        printf("%-30s%-10s%-10.2f%-10.2f%-10.2f\n", p->hoten, p->manv, p->hsl, p->phucap, p->luong);
        p = p->next;
    }
}

void tinhLuong(node *head)
{
    node *p = head;
    float luong = 0;
    int dem = 0;
    while (p != NULL)
    {
        luong += p->luong;
        dem++;
        p = p->next;
    }
    printf("Luong trung binh cua phong ban la: %.2f\n", luong / dem);
}

int main()
{
    //chọn loại phòng ban
    int n;
    printf("Nhap so luong phong ban: ");
    scanf("%d", &n);
    node *head[n];
    for (int i = 0; i < n; i++)
    {
        head[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Nhap thong tin phong ban thu %d\n", i + 1);
        nhap(&head[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Thong tin phong ban thu %d\n", i + 1);
        xuat(head[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Thong tin phong ban thu %d\n", i + 1);
        tinhLuong(head[i]);
    }
    return 0;
    
}

