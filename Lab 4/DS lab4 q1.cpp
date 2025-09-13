#include<iostream>
using namespace std;

int LinearSearch(int arr[], int value, int size){
	for(int i=0; i<size; i++){
		if(arr[i]==value){
			return i;
		}
	}
	return -1;
}
int main(){
    int arr[] = {5, 2, 15, 3, 9, 1, 51, 22, 115, 50};
    for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int value;
	cout<<"Enter value to search for = ";
	cin>>value;
	int index = LinearSearch(arr, value, 10);
	if(index!=-1){
		cout<<"The value was found at index = "<<index<<endl;
	}
	else{
		cout<<"Value not found";
	}
}
