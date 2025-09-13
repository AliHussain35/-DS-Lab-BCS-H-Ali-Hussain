#include<iostream>
using namespace std;
int totalswaps = 0;
int totalComparisons = 0;
void CombSort(int arr[], int size){
	int gap = size;
	bool Noswap = false;
	
	while(gap>1 || !Noswap){
		Noswap = true;
		gap = (int)gap/1.3;
		if(gap<1){
			gap=1;
		}
		for(int i=0; i+gap<size; i++){
			totalComparisons++;
			if(arr[i] > arr[i+gap]){
				totalswaps++;
				int temp = arr[i+gap];
				arr[i+gap] = arr[i];
				arr[i] = temp;
				Noswap = false;
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
	CombSort(arr, 10);
    cout<<"---Sorted Array---"<<endl;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Total swaps = "<<totalswaps<<endl;
	cout<<"Total comparisons = "<<totalComparisons<<endl;

}
