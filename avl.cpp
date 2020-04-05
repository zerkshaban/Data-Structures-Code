#include<iostream>
using namespace std;
struct nodeBST{
	int data;
	nodeBST *left;
	nodeBST *right;
};
nodeBST *root = NULL;
void Insert(int iteam){
	nodeBST *p, *curr, *prev;
	curr = root;
	prev = NULL;
	while (curr != NULL){
		prev = curr;
		if (curr->data < iteam){
			curr = curr->right;
		}
		else{
			curr = curr->left;
		}
	}

	p = new nodeBST;
	if (p == NULL){
		cout << "Its not possible to allocate the memory for new()" << endl;
	}
	p->data = iteam;
	p->left = NULL;
	p->right = NULL;
	if (prev == NULL){
		root = p;
	}
	else{
		if (iteam > prev->data){
			prev->right = p;
			prev=Balance(prev);
		}
		else{
			prev->left = p;
			prev=Balance(prev);
		}
	}
}
nodeBST *RotateLeft(nodeBST *root){
	nodeBST *temp = root->right;
	temp->left = root;
	root->left = NULL;
	return root;
}
nodeBST *RotateRight(nodeBST *root){
	nodeBST *temp = root->left;
	temp->right = root;
	root->left = NULL;
	return root;
}
int depth(nodeBST *root){
	int left = 1 + depth(root->left);
	int right = 1 + depth(root->right);
	if (left > right){
		return left;
	}
	else{
		return right;
	}
}
nodeBST *DoubleRotateRight(nodeBST *root){
	root->right = RotateLeft(root);
	root = RotateRight(root);
	return root;
}
nodeBST *DoubleRotateLeft(nodeBST *root){
	root->left = RotateRight(root);
	root = RotateLeft(root);
	return root;
}
int Diff(nodeBST *root){
	return(root->left - root->right);
}
nodeBST *Balance(nodeBST *root){
	int BalanceFactor = Diff(root);
	if (BalanceFactor > 1){
		int childBF = Diff(root->left);
		if (childBF > 0){
			root = RotateRight(root);
		}
		else{
			root = DoubleRotateRight(root);
		}
	}
	if (BalanceFactor < -1){
		int childBF = Diff(root->right);
		if (BalanceFactor < 0){
			root = RotateLeft(root);
		}
		else{
			root = DoubleRotateLeft(root);
		}
	}
	return root;
}
void Pre_Order(nodeBST *root){
	if (root != NULL){
		Pre_Order(root->left);
		cout << root->data << endl;
		Pre_Order(root->right);
	}
}
int main(){
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	Insert(1);
	Pre_Order(root);
}