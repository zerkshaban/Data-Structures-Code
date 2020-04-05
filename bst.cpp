#include<iostream>
using namespace std;

struct nodeBST{
	int data;
	nodeBST *left;
	nodeBST *right;
};

nodeBST *root = NULL;

int Insert(int info){
	nodeBST *curr, *prev, *p;
	curr = root;
	prev = NULL;

	while (curr != NULL){
		prev = curr;
		if (info > curr->data){
			curr = curr->right;
		}
		else{
			curr = curr->left;
		}
	}
	p = new nodeBST;
	if (p == NULL){
		cout << "Not Possible to make new()." << endl;
	}
	p->data = info;
	p->left = NULL;
	p->right = NULL;

	if (prev == NULL){
		root = p;
	}
	else{
		if (info > prev->data){
			prev->right = p;
		}
		else{
			prev->left = p;
		}
	}
	return (1);
}
nodeBST *FindMin(nodeBST *root){
	while (root->left != NULL){
		root = root->left;
		return root;
	}
}
nodeBST *search(nodeBST *root, int iteam){
	if (root == NULL){
		return 0;
	}
	else if (iteam == root->data){
		cout <<"Found!!!"<<root->data << endl;
	}
	else if (iteam > root->data){
		return(search(root->right,iteam));
	}
	else{
		return(search(root->left,iteam));
	}
}
nodeBST *Delete(nodeBST *root, int iteam){
	if (root == NULL){
		return 0;
	}
	else if (iteam > root->data){
		root->right = Delete(root->right, iteam);
	}
	else if (iteam < root->data){
		root->left = Delete(root->left, iteam);
	}
	else{

	//case 1:no child
		if (root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
	//case 2:one child
		else if (root->left == NULL){
			nodeBST *temp;
			temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL){
			nodeBST *temp;
			temp = root;
			root = root->left;
			delete temp;
		}
	//case 3:two child
		else {
		      nodeBST *temp = FindMin(root->right);
			root->data  = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}
int count1 = 0;
void Depth_Of_LftSTree(nodeBST *root){

	if (root->left == NULL && root->right == NULL){
		cout <<"Length of left sub tree: " <<count1 << endl;
	}
	else{
		if (root->left == NULL){
			count1 = count1++;
			Depth_Of_LftSTree(root->right);
		}
		else{
			count1 = count1++;
			Depth_Of_LftSTree(root->left);
		}
	}
}
int count2 = 0;
void Depth_of_RgtSTree(nodeBST *root){
	if (root->left == NULL && root->right == NULL){
		cout << "Length of right sub tree: " << count1 << endl;
	}
	else{
		if (root->right == NULL){
			count2 = count2++;
			Depth_of_RgtSTree(root->left);
		}
		else{
			count2 = count2++;
			Depth_of_RgtSTree(root->right);
		}
	}
}
int count3 = 0;
int height = 0;
void Height_Of_Node(nodeBST *root,int iteam){
	
	if (count3==0){
		if (iteam > root->data){
			height = count2;
		}
		if (iteam < root->data){
			height = count1;
		}
		count3 = count3++;
	}
	if (iteam == root->data){
		cout << "Height of the node:" << height << endl;
	}
	else if (iteam>root->data){
		height = height--;
		Height_Of_Node(root->right, iteam);
	}
	else if (iteam < root->data){
		height = height--;
		Height_Of_Node(root->left, iteam);
	}
}
int leaves = 0;
void No_Of_Leaves(nodeBST *root){
	if (root != NULL){
	if (root->left == NULL && root->right == NULL){
		leaves = leaves++;
		cout << "Number Of leaves: " << leaves << endl;
	}
	No_Of_Leaves(root->left);
	No_Of_Leaves(root->right);
}
}
void Pre_Order(nodeBST *rootb){
	if (rootb != NULL){
		cout << rootb->data << endl;
		Pre_Order(rootb->left);
		Pre_Order(rootb->right);
	}
}
void In_Order(nodeBST *roota){
	if (roota != NULL){
		In_Order(roota->left);
		cout << roota->data << endl;
		In_Order(roota->right);
	}
}
void Post_Order(nodeBST *roota){
	if (roota != NULL){
		Post_Order(roota->left);
		Post_Order(roota->right);
		cout << roota->data << endl;
	}
}
int main(){

	Insert(5);
	Insert(4);
	Insert(6);
	Insert(7);
	Insert(3);
	Insert(8);
	Pre_Order(root);
	search(root, 4);
	//Delete(root, 6);
	Pre_Order(root);
	Depth_Of_LftSTree(root);
	Depth_of_RgtSTree(root);
	Height_Of_Node(root, 6);
	No_Of_Leaves(root);
}