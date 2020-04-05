#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
	node *prev;
};
node *temp1 = NULL;
node *head = NULL;
void InsertForward(int iteam){
	node *temp = new node;
	temp->data = iteam;
	temp->next = NULL;
	temp->next = NULL;

	if (head == NULL){
		temp->next = head;
		head = temp;
		temp1 = head;
	}
	else{
		temp1->next = temp;
		temp->prev = temp1;
		temp1 = temp1->next;
	}
}
node *temp2 = NULL;
void InsertBackward(int iteam){
	node *temp = new node;
	
	temp->data = iteam;
	temp->next = NULL;
	temp->prev = NULL;

	if (head==NULL){
		temp->next = head;
		head = temp;
		temp2 = head;
	}
	else{
		temp2->next = temp;
		temp->prev = temp2;
		head = temp;
		temp2 = temp2->next;
	}
}

void Search(node *temp,int key){
	//if (count == 0){
	//	temp = head;
	//	count++;
	//}
	if (temp != NULL){
		if (temp->data != key){
			temp = temp->next;
			Search(temp, key);
		}
		else{
			cout << "Found!!!" << endl;
			exit(0);
		}
	}
	cout << "Number Not Present" << endl;
}

void InsertionNthNode(node *temp,int iteam,int key,int count){
	if (count == 0){
	node *temp1 = new node;
	temp1->data = iteam;
	temp1->next = NULL;
	temp1->prev = NULL;
	count++;
	}
	if (temp != NULL){
		if (temp->data != key){
			temp = temp->next;
			InsertionNthNode(temp,iteam,key,count);
		}
		else{
			temp->next->prev = temp1;
			temp1->next = temp->next;
			temp1->next = temp;
			temp->prev = temp1;
			exit(0);
		}
	}
	cout << "Number not found!!!" << endl;

}
void DeleteNthPosition(node *temp,int key){

	if (temp->data != key){
		temp = temp->next;
		DeleteNthPosition(temp, key);
	}
	else{
		if (temp->next == NULL){
			delete temp;
		}
		else{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
}
void Print(node *temp1,int count1){
	if (count1 == 0){
	temp1 = head;
	count1++;
	}
	if (temp1 != NULL){
		cout << temp1->data << endl;
		temp1 = temp1->next;
		Print(temp1, count1);
	}
}
void PrintReverse(node *temp1, int count1){
	if (count1 == 0){
		temp1 = head;
		count1++;
	}
	if (temp1 != NULL){
		cout << temp1->data << endl;
		temp1 = temp1->prev;
		PrintReverse(temp1, count1);
	}
}

int main(){

	InsertForward(1);
	InsertForward(2);
	InsertForward(3);
	InsertForward(4);
	InsertForward(5);
//	Print(head,0);

	//Search(head,5);
	/*InsertionNthNode(head, 8, 3,0);
	Print(head,0);*/
	
	DeleteNthPosition(head,3);
	Print(head, 0);
}