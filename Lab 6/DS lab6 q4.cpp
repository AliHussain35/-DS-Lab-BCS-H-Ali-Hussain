#include <iostream>
using namespace std;
class CircularQueue{
    int *arr;
    int size;
    int capacity;
    int front;
    int rear;

    public:
    CircularQueue(int size){
        capacity = size;
        front = 0;
        rear = -1;
        arr = new int[capacity];
        this->size = 0;
    }

    void enqueue(int x){
        if(size==capacity){
            cout<<"Circular Queue is already full"<<endl;
            return;
        }
        rear = (rear+1)%capacity;
        arr[rear] = x;
        size++;
    }
    
    bool Isempty(){
        return size == 0;
    }
    
    void dequeue(){
        if(Isempty()){
            cout<<"Circular Queue is Empty"<<endl;
            return;
        }
        front = (front+1)%capacity;
        front--;
        size--;
    }
    
    int getFront(){
        if(Isempty()){
            cout << "Circular Queue is Empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    void display(){
    	
        if(Isempty()){
            cout << "Circular Queue is Empty"<<endl;
            return;
        }
        cout<<"Queue = ";
        for(int i=0; i<size; i++){
		    cout<<arr[(front+i)%capacity]<<" ";
            cout<<endl;
        }
    }

    ~CircularQueue(){ //destructor
        delete[] arr;
    }
};

int main() {
    CircularQueue q(6);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.display();
}
