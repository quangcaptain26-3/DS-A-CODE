#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int ma;
	char ten[30];
	float dtb;
}Data;
//
typedef struct tagNode{
	Data infor;
	struct tagNode *link;
}Node;

typedef struct{
	Node *pH, *pT;
	int spt;
}LList;
//
void initL(LList *L){
	L->pH=L->pT=NULL;
	L->spt=0;
}
//
int emptyL(LList L){
	return(L.pH==NULL);
}

///
void nhap_dl(Data *x){
	printf("\nNhap ma: ");
	scanf("%d", &(x->ma));
	printf("Nhap ten: ");
	fflush(stdin);
	fgets(x->ten,30,stdin);
	x->ten[strlen(x->ten)-1]='\0';
	printf("Nhap dtb: ");
	scanf("%f", &(x->dtb));
}
//
void in(Data x){
	printf("\n\nMa: %d", x.ma);
	printf("\nTen: %s", x.ten);
	printf("\nDiem trung binh: %.2f", x.dtb);
}
//
void insertHead(LList *L, Data x){
Node* pp = (Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link=L->pH;
	L->pH=pp;
	L->spt++;
	if(L->pT==NULL) L->pT=pp;
}
void sx(LList L)
{
	Node *i, *j;
	for(i=L.pH;i->link!=NULL;i=i->link)  
	for(j=i->link;j!=NULL;j=j->link)
		if( i->infor.dtb > j->infor.dtb)
		{
			Data tg=i->infor;
			i->infor=j->infor;
			j->infor=tg;
		}
}
//
void processL(LList L)
{
	Node *pp;
	pp=L.pH;
	while(pp!=NULL)
	{
		in(pp->infor);
		pp=pp->link;
	}
}
void tachds(LList L ,LList *L1 , LList *L2)
{
	for(Node *pp = L.pH ; pp != NULL ; pp = pp->link)
	{
		if(pp->infor.dtb >= 7)
		{
			insertHead(L1,pp->infor);
		}
		else
		{
			insertHead(L2,pp->infor);
		}
	}
}

int main(){
	LList L;
	initL(&L);
	LList L1;
	initL(&L1);
	LList L2;
	initL(&L2);
	Data x;
	int n;
	printf("Nhap so phan tu cua L: ");
	scanf("%d",&n);
	for( int i = 0; i<n; i++)
	{
		nhap_dl(&x);
		insertHead(&L, x);
	}
	tachds(L,&L1,&L2);
	printf("\nDanh sach sv co dtb >= 7 sap xep tang dan:");
	sx(L1);
	processL(L1);
	printf("\n\nDanh sach sv co dtb < 7 sap xep tang dan:");
	sx(L2);
	processL(L2);
}