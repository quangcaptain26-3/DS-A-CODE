#include<stdio.h> 
#include<stdlib.h> 
struct Node { 
	char Infor; 
	struct Node *Left; 
	struct Node *Right; 
}; 
//-------------------------------//
/* newNode() allocates a new Node with the given data and NULL Left and Right pointers. */
struct Node* newNode(char data) { 
	struct Node* Node = (struct Node*)malloc(sizeof(struct Node));
	Node->Infor = data;	
	Node->Left = NULL; 
	Node->Right = NULL; 
	return(Node); 
} 
//-------------------------------//
void LRN(struct Node* Node) { 
	if (Node == NULL) 
		return;	
	LRN(Node->Left); 
	LRN(Node->Right);	
	printf("%c  ", Node->Infor); 
} 
//-------------------------------//
void NLR(struct Node* Node) { 
	if (Node == NULL) 
		return; 		
	printf("%c  ", Node->Infor); 
	NLR(Node->Left); 	
	NLR(Node->Right);
} 
//-------------------------------//
void LNR(struct Node* Node) { 
	if (Node == NULL) 
		return; 	
	LNR(Node->Left);
	printf("%c  ", Node->Infor); 	
	LNR(Node->Right);
} 
//-------------------------------//
int main() { 
	/*create root*/
	struct Node *root = newNode('/');	
/* following is the tree after above statement 
     A 
	/ \ 
 NULL NULL 
*/
	root->Left = newNode('+'); 
	root->Right = newNode('-'); 
/* A and C become Left and Right children of A 
	      A 
	   /    \ 
	 B	     C 
	/   \  /   \ 
 NULL NULL NULL NULL 
*/
	root->Left->Left = newNode('3'); 
/* D becomes Left child of B 
	   A 
	  / \ 
	 B	 C 
    / \ / \ 
   D  E F  G 
*/
	root->Left->Right = newNode('*');
	root->Right->Left = newNode('8');
	root->Right->Right = newNode('5');
	
	root->Left->Right->Left  = newNode('6');
	root->Left->Right->Right  = newNode('9');
	
/* 
	   	  / 
	    / 	\ 
	  +	      - 
    / 	\ 	 / 	\ 
   3  	*	8    5 
   	  /   \
   	 6     9
*/
	printf("Duyet theo thu tu TRUOC:\n");
	NLR(root);
	printf("\n");
	printf("Duyet theo thu tu GIUA:\n");
	LNR(root);
	printf("\n");
	printf("Duyet theo thu tu SAU:\n");
	LRN(root);
	
	return 0; 
}