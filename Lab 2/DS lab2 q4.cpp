#include<iostream>
using namespace std;
double* resizearray(double* array, int oldsize, int newsize){
	double* resized = new double[newsize]; 
    for(int i = 0; i < oldsize; i++){
        resized[i] = array[i]; 
    }
    delete[] array; 
    return resized;
}
int main(){
	int n;
	cout<<"Enter number of months for expenses = ";
	cin>>n;
	double* expenses = new double[n];
	cout<<"---add expenses for each month---"<<endl;
	for(int i=0; i<n; i++){
		double exp;
		cout<<"Enter expense for month number "<<i+1<<" = $";
		cin>>exp;
		expenses[i] = exp;
	}
	int choice, newmonths;
	cout<<"Do you want to add more months = (1. yes, 2. no)";
	cin>>choice;
	if(choice == 1){
		cout<<"how many more months do you want to add = ";
		cin>>newmonths;
		expenses = resizearray(expenses, n, n + newmonths);
		
		cout<<"---Enter expenses for next months---"<<endl;
        for(int i = n; i < n + newmonths; i++){
        	double exp;
            cout<<"Enter expense for month number "<<i+1<<" = $";
		    cin>>exp;
		    expenses[i] = exp;
        }
        n = n + newmonths;
	}
	double total = 0;
    for (int i = 0; i < n; i++){
        total += expenses[i];
    }
    double avg = total / n;
    
    cout<<"Average expense of all the months is = $"<<avg<<endl;
    cout<<"---THANK YOU :)---"<<endl;
	
}
