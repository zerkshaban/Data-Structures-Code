#include<iostream>
#define MAX_SIZE 25
using namespace std;
int index;
int j = 0;
int val1;
int *temp;
int *temp1;
int cont;
void HashTable(){
	int arr[MAX_SIZE];
	temp = arr;
	temp1 = arr;
	cout << "Enter the amount of elements you want in your Hashtable:" << endl;
	cin >> index;
	for (int i = 0; i < MAX_SIZE; i++){
		arr[i] = -1;
	}
	for (int i = 0; i < MAX_SIZE; i++){
		temp1++;
	}
	while (j != index){
		cout << "Enter the value:" << endl;
		cin >> val1;

		cont = val1 % MAX_SIZE;
		for (int i = 0; i < cont; i++){
			temp++;
		}
		while (1)
		{
			if (temp == temp1){
				temp = arr;
			}
			if (*temp == -1){
				*temp = val1;
				temp = arr;
				break;
			}
			else{
				temp++;
			}
		}
		j++;
	}
}

int main(){
	HashTable();
}