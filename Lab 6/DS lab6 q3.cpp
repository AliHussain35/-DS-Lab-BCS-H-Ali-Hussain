#include <iostream>
using namespace std;
#define MAX 100
class Queue{
	
    private:
        int front;
        int rear;
        int arr[MAX];

    public:
        Queue(){
        	front = -1;
        	rear = -1;
		}
        
        bool isFull(){
		    return (rear == MAX-1);
		}
		
        bool isEmpty(){
		    return (front == -1);
		}
		
        void enqueue(int x){
            if(isFull()){
                cout<<"Queue already full. Cannot add more elements"<<endl;
                return;
            }
            if (isEmpty()){
            	front = 0;
			}
            arr[++rear] = x;
            return;
        } 

        int dequeue(){
            if(isEmpty()){
                cout << "Queue is Empty"<<endl;
                return -1;
            }

            int n = arr[front];
            if (front == rear){
                front = -1;
				rear = -1; 
            } else {
                front++;
            }
            cout<<"Dequeued = " <<n<<endl;
            return n;
        }

        void display(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<"Queue elements = ";
            for(int i = front; i <= rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        } 
        
};

int main() {
    Queue Q;
    Q.enqueue(30);
    Q.enqueue(300);
    Q.enqueue(3000);
    Q.display();
    cout<<"Removing an element"<<endl;
    Q.dequeue();
    Q.display();
    cout<<"Adding new elements"<<endl;
    Q.enqueue(400);
    Q.enqueue(21);
    Q.display();
}
