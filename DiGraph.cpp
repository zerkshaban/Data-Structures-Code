#include<iostream>
#define VERTEX 5
using namespace std;
void Insertion(){
	int Graph[VERTEX][VERTEX];
	int Vector[VERTEX][1] = { 1,2,3,4,5};
	cout << "ORDER TO ENTER DATA:" << endl;
	cout << endl;
	cout << "abcde " << endl;
	cout << endl;
	cout << "a"<<endl;
	cout << "b"<<endl;
	cout << "c" << endl;
	cout << "d" << endl;
	cout << "e" << endl;
	cout << endl;
	cout << "Enter the Directions on the basis of about table of vertices:" << endl;
	for (int i = 0; i < VERTEX; i++){
		for (int j = 0; j < VERTEX; j++){
			cin >>Graph[i][j];
		}
	}
	system("cls");
	cout << "Vector Set:" << endl;
	for (int i = 0; i < VERTEX; i++){
		for (int j = 0; j < 1; j++){
			cout << "[" << Vector[i][j] << "]";
		}
		cout << endl;
	}
	cout << "Graph Directions:" << endl;
	for (int i = 0; i < VERTEX; i++){
		for (int j = 0; j < VERTEX; j++){
			cout<<"[" <<Graph[i][j]<<"]"<<" ";
		}
		cout << endl;
	}

}
int main(){
	Insertion();
}