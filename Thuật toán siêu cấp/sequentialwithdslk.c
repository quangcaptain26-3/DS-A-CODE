#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

//áp dụng sequential search với danh sách liên kết đơn
typedef struct{
    char ten[30];
    int msv;
    float diem;

} SV;

typedef struct node{
    SV data;
    struct node *next;
} NODE;

typedef struct{
    NODE *head;
    NODE *tail;
} LIST;

void init(LIST *l){
    l->head=l->tail=NULL;
}

NODE *getnode(SV x){
    NODE *p;
    p=(NODE*)malloc(sizeof(NODE));
    if(p==NULL){
        printf("Khong du bo nho");
        return NULL;
    }
    p->data=x;
    p->next=NULL;
    return p;
}

void addtail(LIST *l, NODE *p){
    if(l->head==NULL){
        l->head=l->tail=p;
    }
    else{
        l->tail->next=p;
        l->tail=p;
    }
}


int sequential_search(LIST l, char x[30]){
    NODE *p;
    int i=0;
    for(p=l.head;p!=NULL;p=p->next){
        if(strcmp(p->data.ten,x)==0){
            return i;
        }
        i++;
    }
    return -1;
}

int main(){
    int n,i;
    char x[30];
    printf("Nhap so luong sinh vien: ");
    scanf("%d",&n);
    LIST l;
    init(&l);
    for(i=0;i<n;i++){
        SV x;
        printf("Nhap ten sinh vien thu %d: ",i+1);
        fflush(stdin);
        gets(x.ten);
        printf("Nhap ma sinh vien thu %d: ",i+1);
        scanf("%d",&x.msv);
        printf("Nhap diem sinh vien thu %d: ",i+1);
        scanf("%f",&x.diem);
        NODE *p=getnode(x);
        addtail(&l,p);
    }
    NODE *p;
    for(p=l.head;p!=NULL;p=p->next){
        printf("Sinh vien thu %d: %s %d %.2f\n",i+1,p->data.ten,p->data.msv,p->data.diem);
        
    }

    printf("Nhap ten sinh vien can tim: ");
    fflush(stdin);
    gets(x);
    int kq=sequential_search(l,x);
    if(kq==-1){
        printf("Khong tim thay sinh vien %s",x);
    }
    else{
        printf("Tim thay sinh vien %s tai vi tri %d",x,kq);
    }
    return 0;
}
