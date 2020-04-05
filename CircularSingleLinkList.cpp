#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node* head = NULL;
node *temp1 = NULL;
void Insert(int iteam){
	node *temp = new node;
	temp->data = iteam;
	temp->next = NULL;

	if (head == NULL){
		head = temp;
		temp1 = temp;
		temp1->next = temp1;
	}
	else{
		temp1->next = temp;
		temp1 = temp1->next;
		temp1->next = head;
	}
}
void InsertNthPos(int key,int iteam,int count,node *temp,node *temp1,node *temp2){
	if (count == 0){
		temp2 = new node;
		count++;
	}
	if (temp->next!=head){
		if (temp->data != key){
			temp = temp->next;
			InsertNthPos(key, iteam, count, temp, temp1, temp2);
		}
		else{
			temp1 = temp->next;
			temp2->next = temp1;
			temp->next = temp2;
			InsertNthPos(key,iteam,count,temp,temp1,temp2);
			exit(0);
		}
	}
	else{
		temp1 = temp->next;
		temp2->next = temp1;
		temp->next = temp2;
		temp2 = head;
	}
}
void DeleteNthNode(int key,int count,node *temp,node *temp1){
	if (temp->next != head){
		if (temp->data!=key){
			temp = temp->next;
			count++;
			DeleteNthNode(key, count, temp, temp1);
		}
		else{
			if (count != 1){
				temp1 = temp1->next;
				count--;
			}
			else{
				temp1->next = temp->next;
				delete temp;
				exit(0);
			}
		}
	}
	else{
		if (count != 1){
			temp1 = temp1->next;
			count--;
		}
		else{
			temp1->next = temp->next;
			delete temp;
			exit(0);
		}
		
	}
}
void Search(int key,node *temp){
	if (temp->data == key){
		cout << "Found!!!" << endl;
	}
	if (temp->next != head){
		if (temp->data != key){
			temp = temp->next;
		}
		else{
			cout << "Found!!!" << endl;
		}
	}
	else{
		if (temp->data != key){
			temp = temp->next;
		}
		else{
			cout << "Found!!!" << endl;
		}

	}

}
void Print(node *temp){
	if (temp->next!=head){
		cout << temp->data << endl;
		temp = temp->next;
		Print(temp);
	}
	else {
		cout << temp->data << endl;
	}
}
int main(){
	Insert(1);
	Insert(2);
	Insert(3);
	Insert(4);
	Insert(5);
	Print(head);
}