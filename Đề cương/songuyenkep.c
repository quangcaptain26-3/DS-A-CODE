#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

typedef struct list{
    node *head;
    node *tail;
}list;


void init(list *l){
    l->head = l->tail = NULL;
}



node *createNode(int data){
    node *p = (node*)malloc(sizeof(node));
    if(p == NULL){
        printf("khong du bo nho");
        return NULL;
    }
    p->data = data;
    p->next = NULL;
    p->prev = NULL;
    return p;
}



void addHead(list *l, node *p){
    if(l->head == NULL){
        l->head = l->tail = p;
    }
    else{
        p->next = l->head;
        l->head->prev = p;
        l->head = p;
    }
}



void addTail(list *l, node *p){
    if(l->head == NULL){
        l->head = l->tail = p;
    }
    else{
        l->tail->next = p;
        p->prev = l->tail;
        l->tail = p;
    }
}



void input(list *l){
    int n;
    printf("nhap so luong node: ");
    scanf("%d", &n);
    init(l);
    for(int i = 0; i < n; i++){
        int data;
        printf("nhap data: ");
        scanf("%d", &data);
        node *p = createNode(data);
        addTail(l, p);
    }
}



void output(list *l){
    for(node *p = l->head; p != NULL; p = p->next){
        printf("%d ", p->data);
    }
}


void deleteNode(list *l, node *p){
    if(p == l->head){
        l->head = l->head->next;
        l->head->prev = NULL;
    }
    else if(p == l->tail){
        l->tail = l->tail->prev;
        l->tail->next = NULL;
    }
    else{
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    free(p);
}

int main(){
    list l;
    input(&l);
    output(&l);
    printf("\n");
    int pos;
    printf("nhap vi tri can xoa: ");
    scanf("%d", &pos);
    int count = 0;
    for(node *p = l.head; p != NULL; p = p->next){
        count++;
    }
    if(pos < 0 || pos > count){
        printf("khong hop le");
        return 0;
    }
    int i = 0;
    for(node *p = l.head; p != NULL; p = p->next){
        if(i == pos){
            deleteNode(&l, p);
            break;
        }
        i++;
    }
    output(&l);
    return 0;
}