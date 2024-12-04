#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct SinhVien{
    char name[30];
    float dtb;
    struct SinhVien *next;
    struct SinhVien *prev;
}SinhVien;

void push(SinhVien** headRef, char *name, float dtb){
    SinhVien *newNode = (SinhVien*)malloc(sizeof(SinhVien));
    strcpy(newNode->name, name);
    newNode->dtb = dtb;
    if(*headRef == NULL){
        newNode->next = newNode->prev = NULL;
        *headRef = newNode;
        return;
    }
    (*headRef)->prev = newNode;
    newNode->next = *headRef;
    newNode->prev = NULL;
    *headRef = newNode;
    
}



