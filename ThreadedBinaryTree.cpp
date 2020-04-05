#include<iostream>
using namespace std;
#define range 999
struct node{
	int data;
	node *left;
	node *right;
	bool LeftThreadh;
	bool RightThreath;
};
node *root = NULL;
void DummyNode(){
	root = new node;
	root->left = root->right = root;
	root->data = range;
	root->LeftThreadh = true;
}
void Insertion(int key){
	node *p;
	p = root;
	while (1){
		if (p->data > key){
			if (p->LeftThreadh){
				break;
			}
			else{
				p = p->left;
			}
		}
		if (p->data < key){
			if (p->RightThreath){
				break;
			}
			else{
				p = p->right;
			}
		}
		else{
			return;
		}	
	}
	node *temp = new node;
	temp->data = key;
	temp->LeftThreadh = temp->RightThreath = true;
	if (p->data > key){
		p->left = temp;
		temp->right = p;
		temp->left = p->left;
		p->LeftThreadh = false;
	}
	else if(p->data < key){
		p->right = temp;
		temp->right = root;
		temp->left = p;
		p->RightThreath = false;
	}
}

int main(){
	DummyNode();
	Insertion(1); 
	Insertion(2);
	Insertion(3);
	Insertion(4); 
	Insertion(5);

	Insertion(1);
}