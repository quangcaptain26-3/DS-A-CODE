#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sinhvien
{
    char hoten[30];
    char masv[10];
    float diemtb;
    struct sinhvien *left;
    struct sinhvien *right;
} node;

node *createNode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insertNode(node **root, node *temp)
{
    if (*root == NULL)
    {
        *root = temp;
    }
    else
    {
        if (strcmp(temp->masv, (*root)->masv) < 0)
        {
            insertNode(&(*root)->left, temp);
        }
        else if (strcmp(temp->masv, (*root)->masv) > 0)
        {
            insertNode(&(*root)->right, temp);
        }
    }
}
//thêm một nút vào cây BST
void nhap(node **root)
{
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        node *temp = createNode();
        printf("Nhap thong tin sinh vien thu %d\n", i + 1);
        printf("Nhap ho ten: ");
        fflush(stdin);
        gets(temp->hoten);
        printf("Nhap ma sinh vien: ");
        fflush(stdin);
        gets(temp->masv);
        printf("Nhap diem trung binh: ");
        scanf("%f", &temp->diemtb);
        insertNode(root, temp);
    }
}

void xuat(node *root)
{
    if (root != NULL)
    {
        xuat(root->left);
        printf("%-30s %-10s %-10.2f\n", root->hoten, root->masv, root->diemtb);
        xuat(root->right);
    }
}
// Xoá các nút trong cây BST về sinh viên có điểm trung bình <4.0
void xoa(node **root)
{
    if (*root != NULL)
    {
        if ((*root)->diemtb < 4.0)
        {
            node *temp = *root;
            *root = (*root)->right;
            free(temp);
            xoa(root);
        }
        else
        {
            xoa(&(*root)->left);
            xoa(&(*root)->right);
        }
    }
}

//in ra các nút mà họ tên có chứa ký tự 'a'
void in(node *root)
{
    if (root != NULL)
    {
        in(root->left);
        if (strchr(root->hoten, 'a') != NULL)
        {
            printf("%s\n", root->hoten);
        }
        in(root->right);
    }
}

int main(){
    node *root;
    root = NULL;
    nhap(&root);
    printf("Danh sach sinh vien\n");
    xuat(root);
    printf("Danh sach sinh vien co ky tu 'a' trong ho ten\n");
    in(root);
    printf("Danh sach sinh vien sau khi xoa\n");
    xoa(&root);
    xuat(root);

    return 0;
}