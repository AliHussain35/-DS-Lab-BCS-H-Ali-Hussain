#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n){
	for(int i=1; i<n; i++){
		int value = arr[i];
		int j = i-1;
		
		while(j>=0 && arr[j]>value){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = value;
	}
}
int BinarySearch(int arr[], int n, int key){
	int high = n-1;
	int low = 0;
	while(low<=high){
		int mid = low + (high -low) /2;
		if(arr[mid] == key){
			return mid;
		}
		else if(arr[mid]>key){
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return -1;
}
int main(){
    int arr[] = {5, 2, 15, 3, 9, 1, 51, 22, 115, 50};
	cout<<"---Original Array---"<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	InsertionSort(arr, 10);
    cout<<"---Sorted Array---"<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	int num;
	cout<<endl;
	cout<<"Enter number to search for = ";
	cin>>num;
	int index = BinarySearch(arr, 10, num);
	if(index!=-1){
		cout<<"Found at Index = "<<index<<endl;
	}
	else{
		cout<<"Not found";
	}
}
