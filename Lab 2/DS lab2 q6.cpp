#include<iostream>
using namespace std;
class SafePointer{
	private:
		int* ptr;
	public:
		SafePointer(){
			ptr = new int;
		}
		void setValue(int val){
			*ptr = val;
		}
		int getValue(){
			return *ptr;
		}
		void release(){
			delete ptr;
		}
		~SafePointer(){
			delete ptr;
		}
};
int main(){
	int num;
	num = 5;
	SafePointer* students[num];
	for(int i=0; i<num; i++){
		students[i] = new SafePointer();
	}
	cout<<"Enter marks of "<<num<< " students:"<<endl;
    for (int i = 0; i < num; i++) {
        int mark;
        cout<<"Student "<<i + 1<<"= ";
        cin>>mark;
        students[i]->setValue(mark);
    }
    cout<<"---Marks---"<<endl;
    for(int i = 0; i < num; i++) {
        cout<<"Student "<<i + 1<< "= "<<students[i]->getValue()<<endl;
    }
    for(int i = 0; i < num; i++){
        students[i]->release();
        delete students[i]; 
    }
    return 0;
}
