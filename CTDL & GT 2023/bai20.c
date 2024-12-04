#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100

typedef struct{
    int data[MAX];
    int front, rear;
}Queue;

void initQ(Queue *Q){
    Q->front = -1;
    Q->rear = -1;
}

int isEmpty(Queue Q){
    return Q.front == -1;
}

int isFull(Queue Q){
    return (Q.rear + 1) % MAX == Q.front;
}

void addQ(Queue *Q, int x){
    if(isFull(*Q)){
        printf("Queue day roi\n");
    }
    else{
        if(isEmpty(*Q)){
            Q->front = 0;
        }
        Q->rear = (Q->rear + 1) % MAX;
        Q->data[Q->rear] = x;
    }
}

int delQ(Queue *Q){
    if(isEmpty(*Q)){
        printf("Queue rong roi\n");
        return -1;
    }
    else{
        int x = Q->data[Q->front];
        if(Q->front == Q->rear){
            Q->front = -1;
            Q->rear = -1;
        }
        else{
            Q->front = (Q->front + 1) % MAX;
        }
        return x;
    }
}

int topQ(Queue Q){
    if(isEmpty(Q)){
        printf("Queue rong roi\n");
        return -1;
    }
    else{
        return Q.data[Q.front];
    }
}

int ConvertToDecimal(char *s, int base){
    int len = strlen(s);
    int decimal = 0;
    
    //đưa các chữ số vào hàng đợi
    Queue Q;
    initQ(&Q);
    for(int i = 0; i < len; i++){
        addQ(&Q, s[i] - '0');
    }

    //tính giá trị thập phân
    int i = 0;
    while(!isEmpty(Q)){
        decimal += delQ(&Q) * pow(base, i++);
    }
    return decimal;
}

int main(){
    char s[MAX];
    int base;

    printf("Nhap so can chuyen: ");
    scanf("%s", s);
    printf("Nhap co so can chuyen: ");
    scanf("%d", &base);

    int decimal = ConvertToDecimal(s, base);
    printf("Gia tri thap phan cua %s la: %d\n", s, decimal);

    return 0;
}