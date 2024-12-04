#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int ngay;
    int thang;
    int nam;
} DATE;

typedef struct
{
    char hoten[80];
    DATE ngaysinh;
} HOCSINH;

typedef struct node
{
    HOCSINH data;
    struct node *next;
} NODE;

typedef struct
{
    NODE *dau;
    NODE *cuoi;
} LIST;

void init(LIST *l)
{
    l->dau = l->cuoi = NULL;
}

NODE *getnode(HOCSINH x)
{
    NODE *p;
    p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL)
        return NULL;
    p->data = x;
    p->next = NULL;
    return p;
}

void addtail(LIST *l, NODE *p)
{
    if (l->dau == NULL)
        l->dau = l->cuoi = p;
    else
    {
        l->cuoi->next = p;
        l->cuoi = p;
    }
}



void nhap(HOCSINH *x)
{
    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(x->hoten);
    printf("Nhap ngay sinh: ");
    scanf("%d", &x->ngaysinh.ngay);
    printf("Nhap thang sinh: ");
    scanf("%d", &x->ngaysinh.thang);
    printf("Nhap nam sinh: ");
    scanf("%d", &x->ngaysinh.nam);
}

void nhapds(LIST *l)
{
    int n;
    HOCSINH x;
    NODE *p;
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    init(l);
    for (int i = 0; i < n; i++)
    {
        printf("Nhap thong tin hoc sinh thu %d\n", i + 1);
        nhap(&x);
        p = getnode(x);
        addtail(l, p);
    }
}

void xuat(HOCSINH x)
{
    printf("%-30s%-10d%-10d%-10d\n", x.hoten, x.ngaysinh.ngay, x.ngaysinh.thang, x.ngaysinh.nam);
}

void xuatds(LIST l)
{
    NODE *p;
    printf("%-30s%-10s%-10s%-10s\n", "Ho ten", "Ngay", "Thang", "Nam");
    for (p = l.dau; p != NULL; p = p->next)
        xuat(p->data);
}

void swap(HOCSINH *a, HOCSINH *b)
{
    HOCSINH temp = *a;
    *a = *b;
    *b = temp;
}

void sapxep(LIST *l)
{
    NODE *p, *q;
    for (p = l->dau; p != NULL; p = p->next)
        for (q = p->next; q != NULL; q = q->next)
            if (strcmp(p->data.hoten, q->data.hoten) > 0)
                swap(&p->data, &q->data);
}

void huy(LIST *l)
{
    NODE *p;
    while (l->dau != NULL)
    {
        p = l->dau;
        l->dau = l->dau->next;
        free(p);
    }
}

int main()
{
    LIST l;
    nhapds(&l);
    printf("Danh sach hoc sinh vua nhap:\n");
    xuatds(l);
    sapxep(&l);
    printf("Danh sach hoc sinh sau khi sap xep:\n");
    xuatds(l);
    huy(&l);
    return 0;
}

