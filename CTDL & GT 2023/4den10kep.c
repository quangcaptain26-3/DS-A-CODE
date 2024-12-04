#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SinhVien
{
    char name[30];
    char msv[10];
    float dtb;

} SinhVien;

struct Node
{
    SinhVien data;
    struct Node *next;
    struct Node *prev;
};

void push(struct Node **head_ref, char *name, char *msv, float dtb)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new_node->data.name, name);
    strcpy(new_node->data.msv, msv);
    new_node->data.dtb = dtb;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void append(struct Node **head_ref, char *name, char *msv, float dtb)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    strcpy(new_node->data.name, name);
    strcpy(new_node->data.msv, msv);
    new_node->data.dtb = dtb;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return;
}

//thêm nút mới vào sau nút có mã sinh viên x
void insertAfter(struct Node *prev_node, char *name, char *msv, float dtb)
{
    if (prev_node == NULL)
    {
        printf("Không thể thêm vào vị trí này\n");
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new_node->data.name, name);
    strcpy(new_node->data.msv, msv);
    new_node->data.dtb = dtb;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

//thêm nút mới vào trước nút có mã sinh viên x
void insertBefore(struct Node **head_ref, struct Node *next_node, char *name, char *msv, float dtb)
{
    if (next_node == NULL)
    {
        printf("Không thể thêm vào vị trí này\n");
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new_node->data.name, name);
    strcpy(new_node->data.msv, msv);
    new_node->data.dtb = dtb;
    new_node->prev = next_node->prev;
    next_node->prev = new_node;
    new_node->next = next_node;
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        (*head_ref) = new_node;
}

//thêm mt nút vào trong danh sách liên kết kép sao cho danh sách vẫn có thứ tự tăng dần theo điểm trung bình
void insert_Sort(struct Node **head_ref, char *name, char *msv, float dtb)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current;
    strcpy(new_node->data.name, name);
    strcpy(new_node->data.msv, msv);
    new_node->data.dtb = dtb;
    if (*head_ref == NULL || (*head_ref)->data.dtb >= new_node->data.dtb)
    {
        new_node->next = *head_ref;
        new_node->prev = NULL;
        if ((*head_ref) != NULL)
            (*head_ref)->prev = new_node;
        (*head_ref) = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next != NULL && current->next->data.dtb < new_node->data.dtb)
            current = current->next;
        new_node->next = current->next;
        new_node->prev = current;
        if (current->next != NULL)
            current->next->prev = new_node;
        current->next = new_node;
    }
}

//xoá nút ở đầu danh sách
void deleteHead(struct Node **head_ref)
{
    if (*head_ref == NULL)
        return;
    struct Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
    return;
}

//xoá nút ở cuối danh sách
void deleteTail(struct Node **head_ref)
{
    if (*head_ref == NULL)
        return;
    struct Node *temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return;
}

//xoá nút ở sau nút có mã sinh viên x
void deleteAfter(struct Node **head_ref, struct Node *prev_node)
{
    if (prev_node == NULL)
    {
        printf("Không thể xoá nút này\n");
        return;
    }
    struct Node *temp = prev_node->next;
    prev_node->next = temp->next;
    temp->next->prev = prev_node;
    free(temp);
    return;
}

void deleteBefore(struct Node **head_ref, struct Node *next_node)
{
    if (next_node == NULL)
    {
        printf("Không thể xoá nút này\n");
        return;
    }
    struct Node *temp = next_node->prev;
    if (temp == NULL)
    {
        *head_ref = next_node;
        next_node->prev = NULL;
    }
    else
    {
        temp->prev->next = next_node;
        next_node->prev = temp->prev;
    }
    free(temp);
    return;
}

//xoá nút có mã sinh viên x
void deleteNode(struct Node **head_ref, char *msv)
{
    struct Node *temp = *head_ref;
    while (temp != NULL && strcmp(temp->data.msv, msv) != 0)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Không tìm thấy nút có mã sinh viên %s\n", msv);
        return;
    }
    if (temp == *head_ref)
    {
        *head_ref = temp->next;
        temp->next->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    return;
}

void nhap(SinhVien *sv)
{
    printf("Nhap ho ten: \n");
    fflush(stdin);
    gets(sv->name);
    printf("Nhap ma sinh vien: \n");
    fflush(stdin);
    gets(sv->msv);
    printf("Nhap diem trung binh: \n");
    scanf("%f", &sv->dtb);
}

void xuat(SinhVien sv)
{
    printf("%-30s%-10s%-10.2f\n", sv.name, sv.msv, sv.dtb);
}

void xuatDSSV(struct Node *head)
{
    printf("%-30s%-10s%-10s\n", "Ho ten", "Ma SV", "Diem TB");
    while (head != NULL)
    {
        xuat(head->data);
        head = head->next;
    }
}

void nhapDSSV(struct Node **head)
{
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        SinhVien sv;
        nhap(&sv);
        append(head, sv.name, sv.msv, sv.dtb);
    }
}

void menu(){
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach sinh vien\n");
    printf("3. Them sinh vien vao dau danh sach\n");
    printf("4. Them sinh vien vao cuoi danh sach\n");
    printf("5. Them sinh vien vao sau sinh vien co ma sinh vien x\n");
    printf("6. Them sinh vien vao truoc sinh vien co ma sinh vien x\n");
    printf("7. Them sinh vien vao danh sach sao cho danh sach van co thu tu tang dan theo diem trung binh\n");
    printf("8. Xoa sinh vien o dau danh sach\n");
    printf("9. Xoa sinh vien o cuoi danh sach\n");
    printf("10. Xoa sinh vien o sau sinh vien co ma sinh vien x\n");
    printf("11. Xoa sinh vien o truoc sinh vien co ma sinh vien x\n");
    printf("12. Xoa sinh vien co ma sinh vien x\n");
    printf("13. Thoat\n");
}

int main(){
    int choice;
    struct Node *head = NULL;
    do{
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            nhapDSSV(&head);
            break;
        case 2:
            xuatDSSV(head);
            break;
        case 3:
            {
                SinhVien sv;
                nhap(&sv);
                push(&head, sv.name, sv.msv, sv.dtb);
                break;
            }
        case 4:
            {
                SinhVien sv;
                nhap(&sv);
                append(&head, sv.name, sv.msv, sv.dtb);
                break;
            }
        case 5:
            {
                SinhVien sv;
                nhap(&sv);
                insertAfter(head, sv.name, sv.msv, sv.dtb);
                break;
            }
        case 6:
            {
                SinhVien sv;
                nhap(&sv);
                insertBefore(&head, head, sv.name, sv.msv, sv.dtb);
                break;
            }
        case 7:
            {
                SinhVien sv;
                nhap(&sv);
                insert_Sort(&head, sv.name, sv.msv, sv.dtb);
                break;
            }
        case 8:
            deleteHead(&head);
            break;
        case 9:
            deleteTail(&head);
            break;
        case 10:
            deleteAfter(&head, head);
            break;
        case 11:
            deleteBefore(&head, head);
            break;
        case 12:
            {
                char msv[10];
                printf("Nhap ma sinh vien can xoa: ");
                fflush(stdin);
                gets(msv);
                deleteNode(&head, msv);
                break;
            }
        case 13:
            printf("Thoat\n");
            break;
        default:
            printf("Nhap sai, nhap lai\n");
            break;
        }
    }while(choice != 13);
}