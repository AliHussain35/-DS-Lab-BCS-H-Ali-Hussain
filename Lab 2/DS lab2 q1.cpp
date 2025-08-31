#include<iostream>
using namespace std;
int main(){
	int n, choice, index, value;
	cout<<"Enter the size of array = ";
	cin>>n;
	int* array = new int[n];
	for(int i=0; i<n; i++){
		array[i] = 0;
	}
	cout<<" 1. update value 2. exit"<<endl;
	cin>>choice;
	while(choice!=2){
		int flag =1;
		while(flag==1){
			cout<<"Enter index of the array to change the value = ";
		    cin>>index;
		    if(index>=n){
			    cout<<"invalid index"<<endl;
			    flag=1;
		    }
		    else{
		    	flag=0;
			}
		}
		
		cout<<"Enter value = ";
		cin>>value;
		array[index] = value;
		cout<<" 1. update value 2. exit"<<endl;
	    cin>>choice;	
	}
	cout<<"Displaying array"<<endl;
	for(int i=0; i<n; i++){
		cout<<array[i]<<endl;
	}
	delete[] array;
}
