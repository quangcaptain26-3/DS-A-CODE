#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

void initStack(node **top)
{
    *top = NULL;
}

int isEmpty(node *top)
{
    return (top == NULL);
}

void push(node **top, int data)
{
    node *temp = createNode();
    temp->data = data;
    temp->next = *top;
    *top = temp;
}

int pop(node **top)
{
    if (isEmpty(*top))
    {
        return -1;
    }
    else
    {
        node *temp = *top;
        int data = temp->data;
        *top = (*top)->next;
        free(temp);
        return data;
    }
}

int top(node *top)
{
    if (isEmpty(top))
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}

void nhap(node **top)
{
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &data);
        push(top, data);
    }
}

void xuat(node **top)
{
    node *p = *top;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

int main()
{
    node *top;
    initStack(&top);
    nhap(&top);
    printf("Danh sach truoc khi dao nguoc: ");
    xuat(&top);
    printf("\nDanh sach sau khi dao nguoc: ");
    while (!isEmpty(top))
    {
        printf("%d\t", pop(&top));
    }
    return 0;
}