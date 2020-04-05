#include<iostream>
#include<string>
#include<cstring>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head = NULL;
struct array{
	char vertex;
	node *Linker;
};
int dir;
array arr[5];
int info;
node *temp1 = NULL;
void Fill_Array(){
	cout << "Enter the name of vertex's" << endl;
	for (int i = 0; i < 5; i++){
		cin >> arr[i].vertex;
	}
}
void Insert(){
	Fill_Array();
	for (int i = 0; i < 5; i++){
		arr[i];
		cout << "How many direction do you want to have:" << endl;
		cin >> dir;
		for (int j = 0; j < dir; j++){
			node *temp = new node;
			cout << "Give the first Direction:" << endl;
			cin >> info;
			temp->data = info;
			temp->next = NULL;
			if (head == NULL){
				arr[i].Linker = temp;
				temp->next = head;
				temp = head;
				temp1 = head;
			}
			else{
				temp1->next = temp;
				temp1 = temp1->next;
			}
		}
	}
}
int main(){
	Insert();
}