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
	
};
node* insert(node* root, int key, int k);
void print_BST(node* root);
int find_min(node* root);

int main(){

    node* root = NULL;

    root = insert(root, 46, 3);
    insert(root, 79, 3);
    insert(root, 46, 3);
    insert(root, 42, 3);
    insert(root, 55, 3);
    //cout << find_min(root) << endl;
    print_BST(root);
    
}

node* insert(node* root, int key, int k){
	// insert a new node with the given key if for all x already in the BST |x-key| > k

	if(root == NULL){
		root = (struct node*)malloc(sizeof(node));
		root->key = key;
		root->parent      = NULL;
		root->left_child  = NULL;
		root->right_child = NULL;
		return root;

	}
    
    node* current_ptr = root; node* next_ptr = root;
    bool dir; // if dir == 0 then its going to the left else its going to the right 
    bool condition=1; // if condition == 1 then |x-key| > k is satisfied
    
    do{
		current_ptr = next_ptr;
		if(key<=current_ptr->key){
			if((current_ptr->key-key)<=k){
				condition = 0;
			}
			next_ptr = current_ptr->left_child;
			dir = 0;
		}
		else{
			if((key-current_ptr->key)<=k){
				condition = 0;
			}
		    next_ptr = current_ptr->right_child;	
		    dir = 1;
		}
	}while((next_ptr!=NULL)&&(condition==1));
    
    if(condition == 1){
	    node* new_node = (struct node*)malloc(sizeof(node));
		if(dir==0){ current_ptr->left_child = new_node;  }
		else      { current_ptr->right_child = new_node; }

		new_node->key = key;
		new_node->parent = current_ptr;
		new_node->left_child  = NULL;
		new_node->right_child = NULL;
    }

	return root;
}

void print_BST(node* root){
	// inorder traversal
	if(root->left_child != NULL){
		print_BST(root->left_child);
	}
    
    printf("%d\n", root->key );
    
    if(root->right_child != NULL){
    	print_BST(root->right_child);
    }
    
	return;

}

int find_min(node* root){
	
	while(root->left_child != NULL){
		root = root->left_child;
	}
	
	return root->key;
}

