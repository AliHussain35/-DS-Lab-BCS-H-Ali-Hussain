#include<iostream>
using namespace std;
int ackermannFunc(int m, int n){
	if(m==0){
		return n+1;
	}
	if(m>0 && n==0){
		return ackermannFunc(m-1, 1);
	}
	if(m>0 && n>0){
		return ackermannFunc(m-1, ackermannFunc(m, n-1));
	}
}
int main(){
	int num = ackermannFunc(2, 2);
	cout<<num<<" ";
}

