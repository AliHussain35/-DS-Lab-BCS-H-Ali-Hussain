#include<iostream>
using namespace std;

void SelectionSort(int arr[], int size){
	int minimumIndex;
	for(int i=0; i<size-1; i++){
		minimumIndex = i;
		for(int j=i+1; j<size;j++){
			if(arr[j]<arr[minimumIndex]){
				minimumIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minimumIndex];
		arr[minimumIndex] = temp;
	}
}
int main(){
	int arr[] = {5, 2, 15, 3, 9, 1, 51, 22, 115, 50};
	cout<<"---Original Array---"<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	SelectionSort(arr, 10);
    cout<<"---Sorted Array---"<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}

}
