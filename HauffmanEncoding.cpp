#include<iostream>
using namespace std;
struct node1{
	int iteam;
	node1* next;
};
struct tree{
	int frequency;
	char character;
	int bin;
	tree* left;
	tree* right;
};

struct node{
	int data;
	node *next;
	tree *curr;
};

int repeat = 0;
node *head = NULL;
node *temp1 = NULL;
//tree *root = NULL;
void Insert_SLL(int iteam, tree *ptr){

	node *temp = new node;
	temp->data = iteam;
	temp->next = NULL;
	temp->curr = ptr;

	if (head == NULL){
		temp->next = head;
		head = temp;
		temp1 = head;
	}
	else{
		temp1->next = temp;
		temp1 = temp1->next;
	}
}
node1 *Head = NULL;
node1 *temp4 = NULL;
void Insert1(int data){
	node1 *tmp = new node1;
	tmp->iteam = data;
	tmp->next = NULL;
	
	if (Head == NULL){
		tmp->next = Head;
		Head = tmp;
		temp4 = Head;
	}
	else{
		temp4->next = tmp;
		temp4 = temp4->next;	
	}
}
void Print1(){
	node1 *temp = Head;
	while (temp != NULL){
		cout << temp->iteam;
		temp = temp->next;
	}
}
int count1 = 0;
tree *root = NULL;
void Finding_Path(tree* root, char charact){
	if (count1 == 0){
		node *start = head;
		root = start->curr;
		root = root->left;
		delete start;
		count1++;
	}	
	if (root->character == charact){
		Print1();
		}
		if (root->left->character > root->right->character){
		Insert1(0);
		Finding_Path(root->left,charact);
		}
		else if (root->left->character < root->right->character){
		Insert1(1);
		Finding_Path(root->right, charact);
		}
	}
void Search(){
	node *temp = head;
	node *smallest = head;
	node *secondsmallest = head;
	tree* joint = new tree;
	node *check = head;
	int count1 = 0;
	temp = temp->next;

	while (temp != NULL){
		if (temp->data <= smallest->data){
			secondsmallest = smallest;
			smallest = temp;
		}
		temp = temp->next;
	}
	if (smallest == head){
		secondsmallest = secondsmallest->next;
		smallest->data = smallest->data + secondsmallest->data;
		joint->left = smallest->curr;
		joint->right = secondsmallest->curr;
		joint->frequency = smallest->data;
		smallest->curr = joint;
	}
	else{
		smallest->data = smallest->data + secondsmallest->data;
		joint->left = smallest->curr;
		joint->right = secondsmallest->curr;
		joint->frequency = smallest->data;
		smallest->curr = joint;
	}
	if (secondsmallest == head){
		head = head->next;
		delete secondsmallest;
	}

	else{
		while (check != secondsmallest){
			count1 = count1++;
			check = check->next;
		}
		check = head;
		for (int i = 0; i < count1 - 1; i++){
			check = check->next;
		}
		check->next = secondsmallest->next;
		delete secondsmallest;
	}
}
void Insert(char chara, int freq){
	tree *node = new tree;
	node->character = chara;
	node->frequency = freq;
	node->left = NULL;
	node->right = NULL;
	Insert_SLL(node->frequency, node);
}
void Print(){
	node *temp = head;
	while (temp != NULL){
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << endl;
}
int main(){
	Insert('a', 3);
	Insert('b', 2);
	Insert('c', 4);
	Insert('d', 7);
	Insert('e', 6);
	Print();
	Search();
	Search();
	Search();
	Search();
	Print();
	Finding_Path(root, 'a');
}