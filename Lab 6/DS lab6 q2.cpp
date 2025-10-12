#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node (int x){
        	data = x;
        	next = 0;
		}
};

class Stack{
    private:
        Node *top;

    public:
        Stack (){
        	top = 0;
		}
		
        bool isEmpty(){
            return (top == 0);
        } 
        
        bool push(int n){
            Node* newNode = new Node(n);
            if(!newNode){
                cout<<"Heap Overflow"<<endl;
                return false;
            } 
            newNode->next = top;
            top = newNode;
            cout<<n<<" element pushed successfully"<<endl;
            return true;
        }

        int pop(){
            if(!top){
                cout<<"List is empty"<<endl;
                return -1;
            }
            Node* temp = top;
            top = temp->next;
            int n = temp->data;
            delete temp;
            return n;
        }

        int peek(){
            if(!top){
                cout<<"List is empty"<<endl;
                return -1;
            }
            return top->data;
        }
        
         
        void display(){
            if(!top){
                cout<<"Stack is Empty"<<endl;
                return;
            }
            cout<<"Stack elements = ";
            Node* temp = top;
            while(temp != 0){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout << endl;
        }
};
int main() {
    Stack BrowserHistory;
    cout<<"---Adding pages in browser history---"<<endl;
    BrowserHistory.push(44);
    BrowserHistory.push(11);
    BrowserHistory.push(9);
    BrowserHistory.push(21);
    cout<<"Top page before popping "<<BrowserHistory.peek()<< endl;
    cout<<"Removing top page"<<BrowserHistory.pop()<<endl;
    cout<<"After popping "<<BrowserHistory.peek()<<endl; 
}
