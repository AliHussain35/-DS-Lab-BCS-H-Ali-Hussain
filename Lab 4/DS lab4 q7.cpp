#include<iostream>
#include <cstdlib> 
using namespace std;
int shellcomparisons = 0;
int shellswaps = 0;
int Insertioncomparisons = 0;
int Insertionswaps = 0;
int Bubblecomparisons = 0;
int Bubbleswaps = 0;

void ShellSort(int arr[], int n){
	for(int gap = n/2; gap>0; gap /=2){
		for(int i=gap; i<n; i++){
			int temp = arr[i];
			int j = i - gap;
			while(j>=0 && (++shellcomparisons && arr[j] > temp)){
				arr[j+gap] = arr[j];
				j = j-gap;
				shellswaps++;
			}
			arr[j+gap] = temp;
		}
	}
}
void BubbleSort(int arr[], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			Bubblecomparisons++;
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				Bubbleswaps++;
			}
		}
	}
}
void InsertionSort(int arr[], int n){
	for(int i=1; i<n; i++){
		int value = arr[i];
		int j = i-1;
		
		while(j>=0 && (Insertioncomparisons++ && arr[j]>value)){
			arr[j+1] = arr[j];
			j--;
			Insertionswaps++;
		}
		arr[j+1] = value;
	}
}
int main(){
	const int size = 1000;   
    int arr[size], arr1[size], arr2[size];
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 10000;
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }
    cout<<"----------ORIGINAL ARRAY----------"<<endl;
    for(int i=0; i<size; i++){
    	cout<<arr[i]<<" ";
	}
	cout<<endl;

    BubbleSort(arr, size);
    InsertionSort(arr1, size);
    ShellSort(arr2, size);
    cout<<"----------SORTED ARRAY----------"<<endl;
    for(int i=0; i<size; i++){
    	cout<<arr2[i]<<" ";
	}
	cout<<endl;
    
    cout<<"----------COMPARISONS-----------"<<endl;
    cout<<"Bubble Sort   = "<<Bubblecomparisons<<"   | "<<Bubbleswaps<<endl;
    cout<<"Insertion Sort= " <<Insertioncomparisons<<"   | "<<Insertionswaps<<endl;
    cout<<"Shell Sort    = " <<shellcomparisons<<"   | " << shellswaps << "\n";    
}
