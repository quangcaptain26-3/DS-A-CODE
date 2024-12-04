#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
    int data;
    struct node *next;
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
    return p;
}


void addHead(list *l, node *p){
    if(l->head == NULL){
        l->head = l->tail = p;
    }
    else{
        p->next = l->head;
        l->head = p;
    }
}



void addTail(list *l, node *p){
    if(l->head == NULL){
        l->head = l->tail = p;
    }
    else{
        l->tail->next = p;
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




void deleteNode(list *l, int pos){
    int count = 0;
    for(node *p = l->head; p != NULL; p = p->next){
        count++;
    }
    if(pos < 0 || pos > count){
        printf("khong hop le");
        return;
    }
    if(pos == 0){
        node *p = l->head;
        l->head = l->head->next;
        free(p);
    }
    else{
        int i = 0;
        node *prev = NULL;
        for(node *p = l->head; p != NULL; p = p->next){
            if(i == pos){
                prev->next = p->next;
                free(p);
                break;
            }
            prev = p;
            i++;
        }
    }
}

int main(){
    list l;
    input(&l);
    output(&l);
    printf("\n");
    int pos;
    printf("nhap vi tri can xoa: ");
    scanf("%d", &pos);
    deleteNode(&l, pos);
    output(&l);
    return 0;
}