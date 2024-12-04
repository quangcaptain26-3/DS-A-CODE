#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NhanVien{
    char ten[30];
    int mnv;
    float hsl;
    int namsinh;
    struct NhanVien *next;
}NV;


typedef struct tagNode{
    NV data;
    struct tagNode *left;
    struct tagNode *right;
}Node;

