#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
}Stack;

void initS(Stack *s){
    s->top = -1;
}

int isEmpty(Stack s){
    return s.top == -1;
}

int isFull(Stack s){
    return s.top == MAX - 1;
}

void pushS(Stack *S, int x){
  if(isFull(*S)){
    printf("Stack day roi\n");
  }
  else{
    S->data[++S->top] = x;
  }
}

int popS(Stack *S){
    if(isEmpty(*S)){
        printf("Stack rong roi\n");
        return -1;
    }
    else{
        return S->data[S->top--];
    }
}

int main(){
    Stack S;
    initS(&S);
    pushS(&S, 1);
    pushS(&S, 2);
    pushS(&S, 3);
    pushS(&S, 4);
    pushS(&S, 5);

    while(!isEmpty(S)){
        printf("%d\n", popS(&S));
    }

    return 0;
}