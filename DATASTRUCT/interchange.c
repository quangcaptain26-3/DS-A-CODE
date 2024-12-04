#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
    char hoten[30];
    int masv;
    float diemtb;
} Data;

typedef struct node{
    Data data;
    struct node *next;
} Node;

typedef struct tagList{
    Node *head;
    Node *tail;
    int spt;
} List;

List L;

void Init(List *L){
    L->head = L->tail = NULL;
    L->spt = 0;
}

int empty(List L){
    return L.spt == 0;
}

//void insert_Head(List *L, int Ma, char *Ten, float Diem)
void insert_Head(List *L, Data x){
    Node *p = (Node*)malloc(sizeof(Node));
    if(p == NULL){
        printf("Khong du bo nho\n");
        return;
    }
    p->data = x;
    p->next = NULL;
    if(empty(*L)){
        L->head = L->tail = p;
    }else{
        p->next = L->head;
        L->head = p;
    }
    L->spt++;
}

//void insert_Tail(List *L, int Ma, char *Ten, float Diem)
void insert_Tail(List *L, Data x){
    Node *p = (Node*)malloc(sizeof(Node));
    if(p == NULL){
        printf("Khong du bo nho\n");
        return;
    }
    p->data = x;
    p->next = NULL;
    if(empty(*L)){
        L->head = L->tail = p;
    }else{
        L->tail->next = p;
        L->tail = p;
    }
    L->spt++;
}

//void insert_After(List *L, Node *q, int Ma, char *Ten, float Diem)
void insert_After(List *L, Node *q, Data x){
    Node *p = (Node*)malloc(sizeof(Node));
    if(p == NULL){
        printf("Khong du bo nho\n");
        return;
    }
    p->data = x;
    p->next = NULL;
    if(q != NULL){
        p->next = q->next;
        q->next = p;
        if(q == L->tail){
            L->tail = p;
        }
    }else{
        insert_Head(L, x);
    }
    L->spt++;
}

//void del_Head(List *L)
void del_Head(List *L){
    Node *p;
    if(empty(*L)){
        printf("Danh sach rong\n");
        return;
    }
    p = L->head;
    
    L->head = L->head->next;
    free(p);
    L->spt--;
}

//void del_After(List *L, Node *q)
void del_After(List *L, Node *q){
    Node *p;
    if(q != NULL && q->next != NULL){
        p = q->next;
        q->next = p->next;
        if(p == L->tail){
            L->tail = q;
        }
        free(p);
        L->spt--;
    }
}

//void del_K(List *L, int K)
void del_K(List *L, int K){
    Node *p, *q;
    int i;
    if(K <= 0 || K > L->spt){
        printf("Vi tri khong hop le\n");
        return;
    }
    if(K == 1){
        del_Head(L);
    }else{
        p = L->head;
        for(i = 1; i < K - 1; i++){
            p = p->next;
        }
        del_After(L, p);
    }
}

//void Process(List *L)
void Process(List *L){
    Node *p;
    p = L->head;
    while(p != NULL){
        printf("\nTen: %s", p->data.hoten);
        printf("\nMa: %d", p->data.masv);
        printf("\nDiem: %.2f", p->data.diemtb);
        p = p->next;
    }
}

//void Process_List_If(List *L, float DK)
void Process_List_If(List *L, float DK){
    Node *p;
    p = L->head;
    while(p != NULL){
        if(p->data.diemtb >= DK){
            printf("\nTen: %s", p->data.hoten);
            printf("\nMa: %d", p->data.masv);
            printf("\nDiem: %.2f", p->data.diemtb);
        }
        p = p->next;
    }
}

//bool Search_List(List* L, int x)
bool Search_List(List* L, int x){
    Node *p;
    p = L->head;
    while(p != NULL){
        if(p->data.masv == x){
            return true;
        }
        p = p->next;
    }
    return false;
}

//Node*Sreach_List(List* L, int x)
Node*Sreach_List(List* L, int x){
    Node *p;
    p = L->head;
    while(p != NULL){
        if(p->data.masv == x){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

//void Print_Node(Node *p)
void Print_Node(Node *p){
    printf("\nTen: %s", p->data.hoten);
    printf("\nMa: %d", p->data.masv);
    printf("\nDiem: %.2f", p->data.diemtb);
}

//void Selection_Sort(List L)
void Selection_Sort(List L){
    Node *p, *q, *min;
    Data temp;
    for(p = L.head; p != L.tail; p = p->next){
        min = p;
        for(q = p->next; q != NULL; q = q->next){
            if(q->data.masv < min->data.masv){
                min = q;
            }
        }
        temp = p->data;
        p->data = min->data;
        min->data = temp;
    }
}

//void Interchange_Sort(List L)
void Interchange_Sort(List L){
    Node *p, *q;
    Data temp;
    for(p = L.head; p != L.tail; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(q->data.masv < p->data.masv){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

//Node *newNode(int Ma, char *Ten, float Diem)
Node *newNode(Data x){
    Node *p = (Node*)malloc(sizeof(Node));
    if(p == NULL){
        printf("Khong du bo nho\n");
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

//them mot nut vao ds da sap xep
//void insert_Sort(List *L, int Ma, char *Ten, float Diem)
void insert_Sort(List *L, Data x){
    Node *p, *q;
    p = newNode(x);
    if(p == NULL){
        return;
    }
    if(empty(*L)){
        L->head = L->tail = p;
    }else{
        if(p->data.masv < L->head->data.masv){
            p->next = L->head;
            L->head = p;
        }else if(p->data.masv > L->tail->data.masv){
            L->tail->next = p;
            L->tail = p;
        }else{
            q = L->head;
            while(q->next->data.masv < p->data.masv){
                q = q->next;
            }
            p->next = q->next;
            q->next = p;
        }
    }
    L->spt++;
}

//void insert_Head_Node(List *L, Node* new_node)
void insert_Head_Node(List *L, Node* new_node){
    if(empty(*L)){
        L->head = L->tail = new_node;
    }else{
        new_node->next = L->head;
        L->head = new_node;
    }
    L->spt++;
}

//void insert_after_Node(List *L, Node *q, Node *new_node)
void insert_after_Node(List *L, Node *q, Node *new_node){
    if(q != NULL){
        new_node->next = q->next;
        q->next = new_node;
        if(q == L->tail){
            L->tail = new_node;
        }
    }else{
        insert_Head_Node(L, new_node);
    }
    L->spt++;
}

//void insert_before_Node(List *L, int K, Node *new_node)
void insert_before_Node(List *L, int K, Node *new_node){
    Node *p, *q;
    int i;
    if(K <= 0 || K > L->spt){
        printf("Vi tri khong hop le\n");
        return;
    }
    if(K == 1){
        insert_Head_Node(L, new_node);
    }else{
        p = L->head;
        for(i = 1; i < K - 1; i++){
            p = p->next;
        }
        insert_after_Node(L, p, new_node);
    }
}



//void edit_Node(Node *p, int Ma, char *Ten, float Diem)
void edit_Node(Node *p, Data x){
    p->data = x;
}

//write for me main function
int main(){
    Init(&L);
    Data x;
    int i, n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Nhap ten: ");
        fflush(stdin);
        gets(x.hoten);
        printf("Nhap ma: ");
        scanf("%d", &x.masv);
        printf("Nhap diem: ");
        scanf("%f", &x.diemtb);
        insert_Tail(&L, x);
    }
    Process(&L);
    printf("\nDanh sach sau khi sap xep: \n");
    Interchange_Sort(L);
    Process(&L);
    printf("\nDanh sach sau khi them: \n");
    Data y;
    printf("Nhap ten: ");
    fflush(stdin);
    gets(y.hoten);
    printf("Nhap ma: ");
    scanf("%d", &y.masv);
    printf("Nhap diem: ");
    scanf("%f", &y.diemtb);
    insert_Sort(&L, y);
    Process(&L);
    printf("\nDanh sach sau khi xoa: \n");
    del_K(&L, 2);
    Process(&L);
    printf("\nDanh sach sau khi sua: \n");
    Node *p = Sreach_List(&L, 3);
    Data z;
    printf("Nhap ten: ");
    fflush(stdin);
    gets(z.hoten);
    printf("Nhap ma: ");
    scanf("%d", &z.masv);
    printf("Nhap diem: ");
    scanf("%f", &z.diemtb);
    edit_Node(p, z);
    Process(&L);
    return 0;
}