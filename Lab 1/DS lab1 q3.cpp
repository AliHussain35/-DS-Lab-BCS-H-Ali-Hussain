#include<iostream>
using namespace std;
class Box{
	private:
		int *value;
	public:
		Box(int num){
			value = new int(num);
		}
		~Box(){
			delete value;
		}
		Box(Box& b){
			value = new int(*b.value);
		}
		Box& operator=(const Box& obj) {
            if(this != &obj){
                delete value;
                value = new int(*obj.value);
            }
            return *this;
        }
        int getvalue(){
        	return *value;
		}
		void changeVal(int v){
			*value = v;
		}
};
int main(){
	Box b1(20);
	Box b2 = b1;
	cout<<"Value of b1 = "<<b1.getvalue()<<endl;
	cout<<"Value of b2 = "<<b2.getvalue()<<endl;
	b2.changeVal(30);
	cout<<"New Value of b2 = "<<b2.getvalue()<<endl;
	
}
