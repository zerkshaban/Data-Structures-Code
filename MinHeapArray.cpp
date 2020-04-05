#include<iostream>
using namespace std;
int index = 0;
int *arr;
int *temp;
int *temp1;
int *temp2;
int *temp3;
int count1 = 0;
bool IsTrue = true;
void Insertion(){
	cout << "Enter the number of nodes that you have in Binary tree:" << endl;
	cin >> index;
	arr = new int[index];
	for (int i = 1; i <= index; i++){
		cin >> arr[i];
	}
}
void FindingTheChilds(int info){
	if (IsTrue){
		temp = arr;
		temp1 = arr;
		temp2 = arr;
		temp3 = arr;
	}
	for (int i = 1; i <= index; i++){
		temp++;
	}
	while (temp1 != temp){

		if (*temp1 != info){
			temp1++;
			count1++;
		}
		else{
			if (2 * count1 >= index){
				cout << "Error:OverFlow!!!" << endl;
				break;
			}
			for (int i = 1; i <= 2 * count1; i++){
				temp2++;
			}
			if (*temp1 < *temp2){
			cout << "Min Heap"<< endl;
			}
			else{
				cout << "Not a min Heap." << endl;
			}
			temp2++;
			if (*temp1 < *temp2){
			cout << "Min Heap"<< endl;
			}
			else{
				cout << "Not a min Heap." << endl;
			}
			break;
		}
	}
}
int main(){
	Insertion();
	FindingTheChilds(2);
}