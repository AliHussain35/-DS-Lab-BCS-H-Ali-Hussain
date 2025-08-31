#include<iostream>
using namespace std;
int main(){

	int departments;
	cout<<"Enter number of departments = ";
	cin>>departments;
	double** employees = new double*[departments];
	int size[departments];
	int num;
	float avg[departments];
	cout<<"---Enter number of employees in each department---"<<endl;
	for(int i=0; i<departments; i++){
		cout<<"Add number of employees for department number "<<i+1<<" = ";
		cin>>num;
		size[i] = num;
		employees[i] = new double[num];
    } 
    
    
    for(int i=0; i<departments; i++){
		cout<<"Details for department number "<<i+1<<endl;
		int count = size[i];
		double total =0;
		float salaries[count];
		for(int j=0; j<count; j++){
			double salary;
			cout<<"Enter salary of employee number "<<j+1<<" = $";
			cin>>salary;
			salaries[j] = salary;
			employees[i][j] = salary;
			total += salary;
		}
		float max = salaries[i];
		for(int k=0; k<count; k++){
			if(max<salaries[k]){
				max = salaries[k]; 
			}
		}
		cout<<"The maximum salary in this department is = $"<<max<<endl;
		float avgval = total/count;
		avg[i] = avgval;
		cout<<"Avg salary for department number  "<<i+1<<" is = $"<<avgval<<endl;
	}
	
	float maxAvg = avg[0];
	int index = 0;
	for(int i=0; i<departments; i++){
		if(avg[i] > maxAvg){
			maxAvg = avg[i];
			index = i;
		}
	}
	cout<<"The maximum Average salary of all employees is = $"<<maxAvg<<" and it is of department number = "<<index+1<<endl;
}
   
