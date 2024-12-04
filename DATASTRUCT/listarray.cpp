#include<iostream>
#define MaxLength 50
typedef int Data;
struct List{
    Data data[MaxLength];
    int size;
};

struct List L;
void Initialize(struct List*L);
int Length(struct List*L);
int Delete