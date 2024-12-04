#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int top;
    int data[MAX];
}Stack;

void init(Stack *s){
    s->top = -1;
}

int isEmpty(Stack s){
    return s.top == -1;
}

int isFull(Stack s){
    return s.top == MAX - 1;
}

void pushS(Stack *s, int x){
    if(isFull(*s)){
        printf("Stack day con me no roi\n");
    }
    else{
        s->data[++s->top] = x;
    }
}

int popS(Stack *s){
    if(isEmpty(*s)){
        printf("Stack nay no rong nha\n");
        return -1;
    }
    else{
        return s->data[s->top--];
    }
}

int topS(Stack s){
    if(isEmpty(s)){
        printf("Stack nay no rong nha\n");
        return -1;
    }
    else{
        return s.data[s.top];
    }
}

void DecimalToBinary(int n){
    Stack s;
    init(&s);
    while(n != 0){
        pushS(&s, n % 2);
        n /= 2;
    }
    while(!isEmpty(s)){
        printf("%d", popS(&s));
    }
}

int main(){
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    printf("So %d chuyen sang he nhi phan la: ", n);
    DecimalToBinary(n);
    return 0;
}