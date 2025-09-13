#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main(){
    int arr[] = {5, 2, 15, 3, 9, 1, 51, 22, 115, 50};
	cout<<"---Original Array---"<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	BubbleSort(arr, 10);
    cout<<"---Sorted Array---"<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}

}
