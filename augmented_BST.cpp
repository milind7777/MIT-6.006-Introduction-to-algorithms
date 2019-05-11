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
	
	int size;// the new feature we want to add to a node is size. Which will keep track of the
	         // size of the subtree which has this node as root 
};
node* insert(node* root, int key, int k);
node* create_node(node* parent, int key, bool dir);
void print_BST(node* root);
int rank_t(node* root, int t);


int main(){
	
    node* root = NULL;

    root = insert(root, 49, 2);
    insert(root, 46, 2);
    insert(root, 79, 2);
    insert(root, 43, 2);
    insert(root, 64, 2);
    insert(root, 89, 2);

    print_BST(root);

    cout << rank_t(root, 79) << endl;
       
}

node* insert(node* root, int key, int k){
	// in the previous case(in BST.cpp) we simply went down the tree, checking the condition at each node 
	// and in the end added the node if the condition was satisfied, we didnt know for sure if the 
	// condition is satisfied until we reached the last node.
	// but here we want to change the size of each node depending on wheter the condition is satisfied or not
	// so we will go down the tree as we did before to check the condition but we'll do it recursively here
	// and change the sizes of the nodes on our way back.

    if(root == NULL){
		root = (struct node*)malloc(sizeof(node));
		root->key         = key;
		root->parent      = NULL;
		root->left_child  = NULL;
		root->right_child = NULL;
        root->size        = 1;
		
		return root;

	}

	bool dir;// if dir == 0 then its going to the left else its going to the right 
    if(key<=root->key){
    	dir = 0;
    }	
    else{
    	dir = 1;
    }
    
    int old_size;// storing the present size of the child
    if(dir==0){
    	if(root->left_child!=NULL){
    		old_size = root->left_child->size;
    	}
    	else{
    		old_size = 0;
    	}
    }
    else{
        if(root->right_child!=NULL){
    		old_size = root->right_child->size;
    	}
    	else{
    		old_size = 0;
    	}	
    }


	if(dir==0){
		if((root->key-key)>k){
            if(root->left_child != NULL){
            	insert(root->left_child, key, k);
            }
            else{
            	create_node(root, key, 0);
            }
		}
		else{
			return root;
		}
	}
	else{
	    if((key-root->key)>k){
            if(root->right_child != NULL){
            	insert(root->right_child, key, k);
            }
            else{
            	create_node(root, key, 1);
            }
		}
		else{
			return root;
		}	
	}

	int new_size;// finding the new size of the child after the insertion part is done
    if(dir==0){
    	if(root->left_child!=NULL){
    		new_size = root->left_child->size;
    	}
    	else{
    		new_size = 0;
    	}
    }
    else{
        if(root->right_child!=NULL){
    		new_size = root->right_child->size;
    	}
    	else{
    		new_size = 0;
    	}	
    }
    
    // if new_size and old_size are the same then it means no new node has been inserted
    if(new_size!=old_size){ root->size++; }
    return root;

}
int rank_t(node* root, int t){
	int count = 0;
	do{
		if(t<root->key){
			root = root->left_child;
		}
		else{
            if(root->left_child!=NULL){
                 count += root->left_child->size;	
            }
            count += 1;
            root   = root->right_child;
		}
	}while(root!=NULL);

	return count;
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
    new_node->size        = 1;
    
    return new_node;
}
void print_BST(node* root){
	// inorder traversal
	if(root->left_child != NULL){
		print_BST(root->left_child);
	}
    
    printf("key = %d   size = %d\n", root->key, root->size );
    
    if(root->right_child != NULL){
    	print_BST(root->right_child);
    }
    
	return;

}