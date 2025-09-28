#include<iostream>
using namespace std;
void printNumbers(int n){
	if(n==1){
		cout<<n<<" ";
		return;
	}
	else{
		cout<<n<<" ";
		printNumbers(n-1);
	}
}
void functionB(int n);
void functionA(int n){
	if(n>0){
		cout<<n<<" ";
		functionB(n-1);
	}
}
void functionB(int n){
	if(n>0){
		cout<<n<<" ";
		functionA(n-1);
	}
}
int main(){
	cout<<"TASK 2 PART 1"<<endl;
	printNumbers(5);
	cout<<endl;
	//printing numbers from n to 1 in pattern
	cout<<"TASK 2 PART 2"<<endl;
	functionA(5);
}
