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

int main()
{
    node *top;
    initStack(&top);
    int n;
    printf("Nhap so nhi phan: ");
    scanf("%d", &n);
    while (n != 0)
    {
        push(&top, n % 10);
        n /= 10;
    }
    int dec = 0;
    int i = 0;
    while (!isEmpty(top))
    {
        dec += pop(&top) * pow(2, i);
        i++;
    }
    printf("So thap phan: %d", dec);
    return 0;
}

