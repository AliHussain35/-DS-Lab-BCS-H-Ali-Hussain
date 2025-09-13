#include<iostream>
using namespace std;

int InterpolationSearch(int arr[], int value, int n){
	int high = n-1;
	int low = 0;
	int position;
	
	while(low<=high && arr[low]<=value && arr[high]>=value){
		if(low==high){
			if(arr[low]==value){
				return low;
			}
			else{
				return -1;
			}
		}
		position = low + ((double)(value-arr[low])*(high-low))/ (arr[high]-arr[low]);
		
		if(arr[position]==value){
			return position;
		}
		else if(arr[position]<value){
			low = position+1;
		}
		else{
			high = position-1;
		}
	}
	return -1;
}
int main(){
	int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
	int index;
	for(int i=0; i<10; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int num;
	cout<<"Enter number to search for = ";
	cin>>num;
	index = InterpolationSearch(arr, num, 10);
	if(index!=-1){
		cout<<"The value was found at index = "<<index<<endl;
	}
	else{
		cout<<"Value not found";
	}
	
}
