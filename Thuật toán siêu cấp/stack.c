#include<stdio.h>

#define MAX 100

typedef int Item;
char A[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
              'A', 'B', 'C', 'D', 'E', 'F'};
struct Stack{
    Item Elements[MAX];
    unsigned int Top;
};

struct Stack S;

void InitializeStack(struct Stack *S){
    S->Top = 0;
}

int Empty(struct Stack *S){
    return S->Top == 0;
}

int Full(struct Stack *S){
    return S->Top == MAX;
}

int Push(struct Stack *S, Item X){
    if(Full(S)){
        return 0;
    }
    S->Elements[S->Top++] = X;
    return 1;
}

int Pop(struct Stack *S, Item *X){
    if(Empty(S)){
        return 0;
    }
    *X = S->Elements[--S->Top];
    return 1;
}

int main(){
    InitializeStack(&S);
    int n;
    int co_so;
    printf("Nhap so can chuyen: ");
    scanf("%d", &n);
    printf("Nhap co so can chuyen: ");
    scanf("%d", &co_so);
    while(n > 0){
        Push(&S, n % co_so);
        n /= co_so;
    }
    Item X;
    while(!Empty(&S)){
        Pop(&S, &X);
        printf("%c", A[X]);
    }
    return 0;
}