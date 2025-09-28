#include<iostream>
using namespace std;
int sumTail(int n, int total){
	if(n==0){
		return total;
	}
	total+=n;
	sumTail(n-1, total);
}
int sumNonTail(int n, int total){
	if(n==0){
		return total;
	}
	int sum = sumNonTail(n-1, total);
	return sum + n;
}
int main(){
	int sum = sumTail(4, 0);
	cout<<sum<<" "<<endl;
	int sum2 = sumNonTail(4, 0);
	cout<<sum2<<" "<<endl;
	cout<<"in tail recursion we are carrying the result forward. the stack doesn’t need to remember pending operations"<<endl;
    cout<<"in non-tail recursion the function works until returning. the call stack must remember each pending + n"<<endl;
}
