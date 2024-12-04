#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[30];
    int msv;
    float dtb;
}Data;

typedef struct tagNode{
    Data info;
    struct tagNode *link;
}Node;

typedef struct{
    Node *pHead;
    Node *pTail;
}LList;

void emptyList(LList *L){
    L->pHead = L->pTail = NULL;
    
    pL->pHead = pL->pTail = NULL;

