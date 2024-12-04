#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//danh sách liên kết đơn dùng để quản lý danh sách các học sinh, với cấu trúc mỗi học sinh gồm có hai phần dữ liệu chính:
//Họ tên học sinh, là một chuỗi không quá 80 ký tự.
//Ngày tháng năm sinh của học sinh, theo cấu trúc dữ liệu thể hiện ngày DATE gồm có 3 trường ngày, tháng, và năm được định nghĩa riêng.

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
    scanf("%d%d%d", &x->ngaysinh.ngay, &x->ngaysinh.thang, &x->ngaysinh.nam);
}

void nhapds(LIST *l)
{
    int n;
    HOCSINH x;
    NODE *p;
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Nhap hoc sinh thu %d\n", i + 1);
        nhap(&x);
        p = getnode(x);
        addtail(l, p);
    }
}

void xuat(HOCSINH x)
{
    printf("%-30s %2d/%2d/%4d\n", x.hoten, x.ngaysinh.ngay, x.ngaysinh.thang, x.ngaysinh.nam);
}

void xuatds(LIST l)
{
    NODE *p;
    printf("%-30s %10s\n", "Ho ten", "Ngay sinh");
    for (p = l.dau; p != NULL; p = p->next)
        xuat(p->data);
}


//Viết hàm sắp xếp danh sách học sinh theo thứ tự alphabet họ tên, và viết các hàm hỗ trợ thao tác khởi tạo danh sách rỗng, in danh sách học sinh hiện hành, cũng như hàm hủy toàn bộ học sinh.
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
    l->cuoi = NULL;
}

//Sử dụng các hàm đã viết viết hàm main thực hiện việc nhập vào một danh sách học sinh từ bàn phím, in danh sách đó ra, sắp xếp các học sinh theo họ tên, và in lại danh sách đã sắp xếp ra màn hình. Cuối cùng huỷ danh sách học sinh và kết thúc chương trình.

int main()
{
    LIST l;
    init(&l);
    nhapds(&l);
    printf("\nDanh sach hoc sinh vua nhap:\n");
    xuatds(l);
    sapxep(&l);
    printf("\nDanh sach hoc sinh sau khi sap xep:\n");
    xuatds(l);
    huy(&l);
    return 0;
}