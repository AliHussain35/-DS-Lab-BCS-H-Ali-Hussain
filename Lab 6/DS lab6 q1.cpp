#include <iostream>
using namespace std;
#define MAX 100
class Stack {
    private:
        int top;
        int arr[MAX];
    public:
        Stack(int t = -1){
        	top = t;
		}
		
        bool push(int n){
            if(top >= MAX - 1){
                cout<<"Stack overflow. Cannot add more elements"<<endl;
                return false;
            }
            arr[++top] = n;
            cout<<n<<" element added successfully"<<endl;
            return true;
        }
        
        int pop(){
            if(top<0){
                cout<<"Stack empty. underflow"<<endl;
                return -1;
            }
            int x = arr[top--];
            cout<<x<<" element popped"<<endl;
            return x;
        }
        
        int peek(){
            if(top<0){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            return arr[top];
        }
        
        bool isEmpty(){
            return (top<0);
        }
        
        void display(){
            if(top<0){
                cout<<"Stack is Empty. No elements to display"<<endl;
                return;
            }
            cout<<"Stack elements = ";
            for(int i = 0; i <= top; i++){
                cout<<arr[i]<< " ";
            }
            cout<<endl;
        }
};
int main (){
    Stack s;
    s.push(40);
    s.push(20);
    s.push(10);
    s.push(200);
    cout<<"---Displaying elements---"<<endl;
    s.display();
    cout<<"Top element = "<<s.peek()<<endl;
    s.pop();
    cout<<"---displaying elements after popping out---"<<endl;
    s.display();
}
