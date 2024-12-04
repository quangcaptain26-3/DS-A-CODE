#include<stdio.h>

#define MAX 100

typedef int Item;
struct Queue{
    Item data[MAX];
    unsigned int Front, Rear;
};

struct Queue Q;

void init(struct Queue *Q){
    Q->Front = 1;
    Q->Rear = 0;
}

int isEmpty(struct Queue Q){
    return (Q.Rear == 0);
}

int isFull(struct Queue Q){
    return (Q.Rear == MAX);
}

int AddQ(struct Queue *Q, Item x){
    if(isFull(*Q)) return 0;
    Q->Rear++;
    Q->data[Q->Rear] = x;
    return 1;
}

int DeleteQ(struct Queue *Q, Item *x){
    if(isEmpty(*Q)) {
        printf("Queue is empty\n");
        return 0;
    } else {
        *x = Q->data[Q->Front];
        if(Q->Front == Q->Rear){
            Q->Front = 1;
            Q->Rear = 0;
        } else {
            Q->Front++;
        }
        return 1;
    }
}

int main(){
    init(&Q);
    AddQ(&Q, 1);
    AddQ(&Q, 2);
    AddQ(&Q, 3);
    AddQ(&Q, 4);
    AddQ(&Q, 5);
    int x;
    while(!isEmpty(Q)){
        DeleteQ(&Q, &x);
        printf("%d ", x);
    }
    return 0;
}