#include<stdio.h>
#include<malloc.h>

typedef int Data;

typedef struct QNode{
    Data infor;
    struct QNode *next;
} QNode;

typedef struct tagQueue{
    QNode *front;
    QNode *rear;
    int spt;
} Queue;

Queue Q;

void init(Queue *Q){
    Q->front = NULL;
    Q->rear = NULL;
    Q->spt = 0;
}

int isEmpty(Queue Q){
    return (Q.spt == 0);
}

void enQueue(Queue *Q, Data x){
    QNode *p = (QNode*)malloc(sizeof(QNode));
    p->infor = x;
    p->next = NULL;
    if(isEmpty(*Q)){
        Q->front = p;
        Q->rear = p;
    } else {
        Q->rear->next = p;
        Q->rear = p;
    }
    Q->spt++;
}

void deQueue(Queue *Q, Data *x){
    if(isEmpty(*Q)){
        printf("Queue is empty\n");
    } else {
        QNode *p = Q->front;
        *x = p->infor;
        Q->front = Q->front->next;
        free(p);
        Q->spt--;
    }
}

void ProcessQ(Queue *Q){
    QNode *p = Q->front;
    while(p != NULL){
        printf("%d ", p->infor);
        p = p->next;
    }
    printf("\n");
}

int main(){
    init(&Q);
    enQueue(&Q, 1);
    enQueue(&Q, 2);
    enQueue(&Q, 3);
    enQueue(&Q, 4);
    enQueue(&Q, 5);
    

    Data x;
    while(!isEmpty(Q)){
        deQueue(&Q, &x);
        printf("%d ", x);
    }
    return 0;
}