#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#define mod 1000000000+7
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair 
#define pii pair <int, int>
using namespace std;

struct node
{ 
	int key;
	struct node* parent;
	struct node* left_child;
	struct node* right_child;

    int height;
	int weight;//if weight = 0 then the height of the right child == height left child
	    //if weight = +k then the height of the right child is k larger than the height of the left child
	    //similarly if weight = -k then the height of the left child is k larger than the height of the right child 
	
};

node* create_node(node* parent, int key, bool dir);
int max(int m, int n);
node* left_rotate(node* root);
node* right_rotate(node* root);
void print_AVL(node* ptr);
void insert(node** root, int key, int k);

int main(){
	node* root = NULL;
	node** ptr = &root;

	insert(ptr, 41, 2);
	insert(ptr, 20, 2);
	insert(ptr, 65, 2);
	insert(ptr, 11, 2);
	insert(ptr, 29, 2);
	insert(ptr, 50, 2);
	insert(ptr, 26, 2);

	print_AVL(*ptr);

	insert(ptr, 23, 2);
	printf("\n");

	print_AVL(*ptr);

	insert(ptr, 55, 2);
	printf("\n");

	print_AVL(*ptr);

	
}

void insert(node** ptr, int key, int k){
    
    node* root = *ptr;
    if(root == NULL){
		root = (struct node*)malloc(sizeof(node));
		root->key         = key;
		root->parent      = NULL;
		root->left_child  = NULL;
		root->right_child = NULL;
        
        root->height      = 0;
        root->weight      = 0;
		
		*ptr = root;
		return;

	}

	bool dir;// if dir == 0 then its going to the left else its going to the right 
    if(key<=root->key){
    	dir = 0;
    }	
    else{
    	dir = 1;
    }

	if(dir==0){
		if((root->key-key)>k){
            if(root->left_child != NULL){
            	insert(&root->left_child, key, k);
            }
            else{
            	create_node(root, key, 0);
            }
		}
		else{
			return;
		}
	}
	else{
	    if((key-root->key)>k){
            if(root->right_child != NULL){
            	insert(&root->right_child, key, k);
            }
            else{
            	create_node(root, key, 1);
            }
		}
		else{
			return;
		}	
	}

	int hegiht_of_left_child = -1;
	if(root->left_child!=NULL){ hegiht_of_left_child = root->left_child->height; }

    int hegiht_of_right_child = -1;
	if(root->right_child!=NULL){ hegiht_of_right_child = root->right_child->height; }

    root->weight = hegiht_of_right_child - hegiht_of_left_child;// >1 means right heavy and <-1 means left heavy
	root->height = max(hegiht_of_right_child, hegiht_of_left_child) + 1;
	
	
	if((root->weight)>1){
         if((root->right_child->weight) >= 0){
         	root = left_rotate(root);
         }
         else{
         	right_rotate(root->right_child);
         	root = left_rotate(root);
         }
	}
	else if((root->weight)<-1){
		if( (root->left_child->weight) <= 0){
         	root = right_rotate(root);
         }
         else{
         	left_rotate(root->left_child);
         	root = right_rotate(root);
         }
	}

    
    *ptr = root;
    return;

}

node* left_rotate(node* root){
    node* X        = root;
    node* Y        = root->right_child;
    node* A        = root->left_child;
    node* B        = Y->left_child;
    node* C        = Y->right_child;
    
    if(X->parent != NULL){
    	if(X->parent->left_child == X){
    		X->parent->left_child = Y;
    	}
    	else{
    		X->parent->right_child = Y;
    	}
    }

    int height_A=-1,height_B=-1,height_C=-1; 

    Y->left_child = X;
    Y->parent     = X->parent;

    X->right_child = B;
    X->parent      = Y;
    
    if(B!=NULL){
    	B->parent = X;
    	height_B  = B->height;
    }
    if(A!=NULL){
        height_A  = A->height;	
    }
    if(C!=NULL){
        height_C  = C->height;	
    }

    X->height = max(height_A, height_B) + 1;
    X->weight = height_B - height_A;

    Y->height = max(X->height, height_C) + 1;
    Y->weight = height_C - X->height;
    
    
    return Y;
}

node* right_rotate(node* root){
    node* Y        = root;
    node* X        = root->left_child;
    node* A        = X->left_child;
    node* B        = X->right_child;
    node* C        = Y->right_child;
    
    if(Y->parent != NULL){
    	if(Y->parent->left_child == Y){
    		Y->parent->left_child = X;
    	}
    	else{
    		Y->parent->right_child = X;
    	}
    }
    
    int height_A=-1,height_B=-1,height_C=-1; 

    X->right_child = Y;
    X->parent      = Y->parent;

    Y->left_child  = B;
    Y->parent      = X;
    
    if(B!=NULL){
    	B->parent = Y;
    	height_B  = B->height;
    }
    if(A!=NULL){
        height_A  = A->height;	
    }
    if(C!=NULL){
        height_C  = C->height;	
    }

    Y->height = max(height_C, height_B) + 1;
    Y->weight = height_C - height_B;

    X->height = max(Y->height, height_A) + 1;
    X->weight = Y->height - height_A;

    return X;
}

node* create_node(node* parent, int key, bool dir){
	node* new_node = (struct node*)malloc(sizeof(node));
	
	if(dir==0){
		parent->left_child = new_node;
	}
	else{
		parent->right_child = new_node;
	}

	new_node->key         = key;
	new_node->parent      = parent;
	new_node->left_child  = NULL;
	new_node->right_child = NULL;
    new_node->height      = 0;
    new_node->weight      = 0;
    
    return new_node;
}

void print_AVL(node* root){
	// inorder traversal
	
	if(root->left_child != NULL){
		print_AVL(root->left_child);
	}
    
    printf("key = %d   height = %d   weight = %d\n", root->key, root->height, root->weight);
    
    if(root->right_child != NULL){
    	print_AVL(root->right_child);
    }
    
	return;

}

int max(int m, int n){
	if(m>n){
		return m;
	}
	return n;
}