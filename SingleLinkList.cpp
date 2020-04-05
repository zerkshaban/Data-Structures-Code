#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head = NULL;
node *temp = NULL;
node *temp1 = NULL;
void InsertionForward(int iteam){
	temp = new node;
	temp->data = iteam;
	temp->next = NULL;
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
int count4 = 0;
node *temp2 = NULL;
void InserthinAtNthPosition(int key,int info){
	if (count4 == 0){
		temp = new node;
		temp->data = info;
		temp->next = NULL;

		temp1 = head;
		temp2 = head;
		count4++;
	}
	if (temp1->data != key){
		temp1 = temp1->next;
		InserthinAtNthPosition(key, info);
	}
	else{
		if (temp1->next == NULL){
			temp1->next = temp;
		}
		else{
		temp2 = temp1->next;
		temp1->next = temp;
		temp->next = temp2;
		}
	}


}

void InsertionBackward(int iteam){
	temp = new node;
	temp->data = iteam;
	temp->next = NULL;
	
	if (head != NULL){
		temp->next = head;
	}
	head = temp;
}

int count2 = 0;
void Search(int key){
	if (count2 == 0){
		temp = head;
		count2++;
	}
	if (count2 > 0){
		if (temp == NULL){
			cout << "Error:Number Does Not Exsist." << endl;
			exit(0);
		}
	}
	if (temp->data == key){
		cout << "Found!!!" << endl;
		exit(0);
	}
	else if (temp->data != key){
		temp = temp->next;
		Search(key);
	}
}

int count5 = 0;
void Duplicate(){
	if (count5 == 0){
		temp = head;
		temp1 = head;
		temp1 = temp1->next;
		count5++;
	}
	if (temp->data != temp1->data){
		temp1 = temp1->next;
		if (temp1 == NULL){
			if (temp== NULL){
				exit(0);
			}
			else{
			temp = temp->next;
			temp1 = temp->next;
			Duplicate();
			}
		}
		Duplicate();
	}
	else{
		cout << "Duplicate Found!!!" << endl;
		exit(0);
	}

}

int count3 = 0;
void DeleteNthNode(int key){
	if (count3 == 0){
		temp = head;
		temp1 = head;
	}
	count3++;
	if (count3 > 1){
		if (temp->data != key){
			temp1 = temp1->next;
		}
		else{
			temp1->next = temp->next;
			delete temp;
			exit(0);
		}
	}
	if (temp->data != key){
		temp = temp->next;
		DeleteNthNode(key);
	}
}

int count1 = 0;
void Print(){
	if (count1 == 0){
		temp = head;
		count1 = count1++;
	}
	if (temp != NULL){
		cout << temp->data << endl;
		temp = temp->next;
		Print();
	}
}

int main(){
	InsertionForward(1);
	InsertionForward(3);
	InsertionForward(3);
	InsertionForward(7);
	InsertionForward(4);
//	InsertionBackward(1);
//	InsertionBackward(2);
//	InsertionBackward(3);
//	InsertionBackward(4);
//	InsertionBackward(5);
	//Print();
	//Search(7);
	//DeleteNthNode(2);
	//Print();
	//cout << "Afert Deletion" << endl;
//	InserthinAtNthPosition(1, 8);
//	Print();
	Duplicate();
}