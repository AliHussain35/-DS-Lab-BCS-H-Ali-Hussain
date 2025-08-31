#include<iostream>
using namespace std;
int main(){
	int days, times;
	cout<<"Enter number of days = ";
	cin>>days;
	cout<<"Enter number of times in day = ";
	cin>>times;
	double** temp = new double*[days];
	for(int i=0; i<days; i++){
		temp[i] = new double[times];
	}
	float avg[days];
	cout<<"---Enter temperature readings---"<<endl;
	for(int i=0; i<days; i++){
		cout<<"Enter readings for day number "<<i+1<<endl;
		float total = 0;
		for(int j=0; j<times; j++){
			int value;
			cout<<"Enter temperature value for time (in celcius)"<<j+1<<" = ";
			cin>>value;
			total+=value;
			temp[i][j] = value;
		}
		float dailyAvg;
		dailyAvg = total/times;
		avg[i] = dailyAvg;
		cout<<"Average temperature for day number "<<i+1<<" is = "<<dailyAvg<<" celcius"<<endl;
	}
	float maxtemp = avg[0];
	float mintemp = avg[0];
	int hottest = 0;
	int coldest = 0;
	for(int i=0; i<days; i++){
		if(maxtemp<avg[i]){
			maxtemp = avg[i];
			hottest = i;
		}
	}
	for(int i=0; i<days; i++){
		if(mintemp>avg[i]){
			mintemp = avg[i];
			coldest = i;
		}
	}
	cout<<"The hottest day was day number = "<<hottest+1<<endl;
	cout<<"The coldest day was day number = "<<coldest+1<<endl;
	
}
