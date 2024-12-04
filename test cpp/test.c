#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

void insert_push(node **head, int data)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }

    node *temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_append(node **head, int data)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }

    node *temp = *head;
    *head = new_node;
    new_node->next = temp;
    temp->prev = new_node;
}


void delete_node(node **head)
{
    if(*head == NULL)
    {
        return;
    }

    node *temp = *head;
    while(temp->next != NULL)
    {
        if(temp->data < temp->next->data)
        {
            temp = temp->next;
        }
        else
        {
            node *temp2 = temp->next;
            temp->next = temp2->next;
            temp2->next->prev = temp;
            free(temp2);
        }
    }
}

int main(){
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    node *head = NULL;
    for(int i = 0; i < n; i++)
    {
        int data;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &data);
        insert_push(&head, data);
    }

    delete_node(&head);

    node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}