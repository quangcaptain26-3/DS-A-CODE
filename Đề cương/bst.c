#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
//--------------------------//
typedef struct {
    char Hoten[30];
   	int MaSV;
   	float DiemTB;
} Data;
//--------------------------//
struct node { 
	Data key; 
	struct node *left, *right; 
}; 

// A utility function to create a new BST node 
struct node* newNode(int Ma, char *Ten, float Diem) { 
	struct node* temp = (struct node*) malloc(sizeof(struct node));	
	/////////////////
	temp->key.MaSV = Ma; 
	strcpy(temp->key.Hoten, Ten); 
	temp->key.DiemTB = Diem; 
	/////////////////	
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to do inorder traversal of BST 
void inorder(struct node* root) { 
	if (root != NULL) { 
		inorder(root->left); 
		printf("%d  %s  %1.1f \n", root->key.MaSV, root->key.Hoten, root->key.DiemTB); 
		inorder(root->right); 
	} 
}

void preorder(struct node* root) { 
	if (root != NULL) { 
		printf("%d  %s  %1.1f \n", root->key.MaSV, root->key.Hoten, root->key.DiemTB);  
		preorder(root->left); 
		preorder(root->right); 
	} 
}

/* A utility function to insert 
a new node with given key in 
* BST */
struct node* insert(struct node* node, int Ma, char *Ten, float Diem) { 
	/* If the tree is empty, return a new node */
	if (node == NULL) 
		return newNode(Ma, Ten, Diem); 

	/* Otherwise, recur down the tree */
	if (Ma < node->key.MaSV) 
		node->left = insert(node->left, Ma, Ten, Diem); 
	else if (Ma > node->key.MaSV) 
		node->right = insert(node->right, Ma, Ten, Diem); 

	/* return the (unchanged) node pointer */
	return node; 
} 

// Driver Code 
int main() { 
	/* Let us create following BST 
		 5 
		/ \ 
	  3	   7 
 	 / \  / \ 
	2  4 6  8 */
	struct node* root = NULL; 
	root = insert(root, 5, "Hanh", 7.6); 
	insert(root, 3, "Hong", 6.1); 
	insert(root, 2, "Minh", 8.7); 
	insert(root, 4, "Huy", 6.5); 
	insert(root, 7, "Nghia", 4.3); 
	insert(root, 6, "Sinh", 9.1); 
	insert(root, 8, "Dao", 2.1); 

	// print inoder traversal of the BST 
	inorder(root); // Duyet cay theo thu tu giua
	//preorder(root);  // Duyet cay theo thu tu truoc
	return 0; 
}
