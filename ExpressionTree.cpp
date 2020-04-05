#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;
struct tree{
	int data;
	tree *left;
	tree *right;
};
struct node{
	node *next;
	tree *addbst;
};
node *p = NULL;
node *q = NULL;
node *top = NULL;

void Push(tree *ptr){
	p = new node;
	p->addbst = ptr;
	p->next = NULL;
	top = p;
	if (top == NULL){
		return;
	}
	else{
		top = p;
		q = top;
		p->next = q;
	}
}
tree *pop(){
	if (top == NULL){
		return 0;
	}
	else{
		p = top;
		top = top->next;
		return p->addbst;
		delete p;
		
	}
}
void Check_Air(char val1){
	if (val1 >= 97 && val1 <= 123){
		tree *temp = new tree;
		temp->data = val1;
		temp->left = NULL;
		temp->right = NULL;
		Push(temp);
	}
	else if (val1 >= 42 && val1 <= 47){
		tree *temp = new tree;
		temp->data = val1;
		temp->left = pop();
		temp->right = pop();
	}
}
void PostOrder(tree *temp){
	if (temp != NULL){
		PostOrder(temp->left);
		PostOrder(temp->right);
		cout << temp->data;
	}
	cout << endl;
}
int main(){
	char arr[15];
	int size;
	cout << "Enter the string of the airthmetic expression:" << endl;
	cin >> arr;
	size = strlen(arr);
	while (size>=0){
		size--;
		Check_Air(arr[size]);
	}
	PostOrder(pop());
	_getch();


}