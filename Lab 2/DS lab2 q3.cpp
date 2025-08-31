#include<iostream>
using namespace std;
int main(){
	int num, courses;
	cout<<"Enter number of students = ";
	cin>>num;
	int** students = new int*[num];
	int size[num];
	cout<<"Enter number of courses each student is enrolled in"<<endl;
	for(int i=0; i<num; i++){
		cout<<"Add number of courses for student number "<<i+1<<" = ";
		cin>>courses;
		size[i] = courses;
		students[i] = new int[courses];
	}
	
	for(int i=0; i<num; i++){
		cout<<"Details for student number "<<i+1<<endl;
		int count = size[i];
		int total =0;
		for(int j=0; j<count; j++){
			int marks;
			cout<<"Enter marks in course number "<<j+1<<" = ";
			cin>>marks;
			students[i][j] = marks;
			total += marks;
		}
		float avg = total/count;
		cout<<"Avg marks for student number  "<<i+1<<" are = "<<avg<<endl;
	}
	
	
}
