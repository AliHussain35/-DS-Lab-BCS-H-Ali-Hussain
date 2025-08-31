#include<iostream>
using namespace std;
int main(){
	int benches, seats;
	cout<<"Enter total benches in class = ";
	cin>>benches;
	cout<<"Enter total seats in each row = ";
	cin>>seats;
	int** classroom = new int*[benches];
	for(int i=0; i<benches; i++){
		classroom[i] = new int[seats];
	}
	for(int i=0; i<benches; i++){
		for(int j=0; j<seats; j++){
			classroom[i][j] = 0;
		}
	}
	cout<<"Class is empty"<<endl;
	int choice, row, col;
	cout<<"1. fill seat 2. exit = ";
	cin>>choice;
	while(choice!=2){
		cout<<"Enter row number = ";
		cin>>row;
		cout<<"Enter seat number = ";
		cin>>col;
		classroom[row-1][col-1] = 1;
		cout<<"Seat occupied"<<endl;
		cout<<"1. fill seat 2. exit = ";
	    cin>>choice;
	}
	cout<<"Displaying arrangement"<<endl;
	for(int i = 0; i < benches; i++){
        for(int j = 0; j < seats; j++){
            cout << classroom[i][j]<<" "; 
        }
        cout<<endl;
    }
}
