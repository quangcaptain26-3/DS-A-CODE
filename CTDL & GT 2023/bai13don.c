#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <string.h>
struct SinhVien{
    char name[30];
    float dtb;
    struct SinhVien *next;
};

void MoveSinhVien(struct SinhVien** destRef, struct SinhVien** sourceRef);

struct SinhVien* SortedMerge(struct SinhVien* a, struct SinhVien* b){
    struct SinhVien* result = NULL;
    if(a == NULL){
        return(b);
    }
    else if(b == NULL){
        return(a);
    }
    if(a->dtb <= b->dtb){
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else{
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}

void MoveSinhVien(struct SinhVien** destRef, struct SinhVien** sourceRef){
    struct SinhVien* newNode = *sourceRef;
    assert(newNode != NULL);
    *sourceRef = newNode->next;
    newNode->next = *destRef;
    *destRef = newNode;
}

void push(struct SinhVien** headRef, char *name, float dtb){
    struct SinhVien* newNode = (struct SinhVien*)malloc(sizeof(struct SinhVien));
    strcpy(newNode->name, name);
    newNode->dtb = dtb;
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(struct SinhVien *head){
    struct SinhVien *temp = head;
    while(temp != NULL){
        printf("%s %.2f\n", temp->name, temp->dtb);
        temp = temp->next;
    }
}

int main(){
    struct Node* result = NULL;
    struct SinhVien* a = NULL;
    struct SinhVien* b = NULL;

    push(&a, "Nguyen Van A", 8.5);
    push(&a, "Nguyen Van B", 7.5);

    push(&b, "Nguyen Van C", 9.5);
    push(&b, "Nguyen Van D", 6.5);

    result = SortedMerge(a, b);

    printf("Danh sach sinh vien sau khi sap xep:\n");
    printList(result);
    return 0;
}