#include <iostream>
using namespace std;

#define MAX_PROCESSES 100

class Process{
public:
    int processID;
    int priority;

    Process(int id = 0, int pr = 0){
    	processID = id;
    	priority  = pr;
	}
};

class Stack{
private:
    int topIndex;
    Process stackArr[MAX_PROCESSES];

public:
    Stack(){
    	topIndex = -1;
	};

    bool isEmpty(){ return topIndex < 0; }
    bool isFull(){ return topIndex >= MAX_PROCESSES - 1;}

    void push(Process p){
        if (isFull()){
            cout<<"Stack Overflow. Cannot push process"<<endl;
            return;
        }
        stackArr[++topIndex] = p;
    }

    Process pop() {
        if (isEmpty()){
            cout<<"Stack Underflow. No process to pop"<<endl;
            return Process(-1, -1);
        }
        return stackArr[topIndex--];
    }
};

class Queue {
private:
    int frontIndex, rearIndex;
    Process queueArr[MAX_PROCESSES];

public:
    Queue(){
    	frontIndex = -1;
    	rearIndex = -1;
	}

    bool isEmpty() { return frontIndex == -1; }
    bool isFull() { return rearIndex == MAX_PROCESSES - 1; }

    void enqueue(Process p){
        if (isFull()){
            cout<<"Queue Full. Cannot enqueue process"<<endl;
            return;
        }
        if (isEmpty()) frontIndex = 0;
        queueArr[++rearIndex] = p;
    }

    Process dequeue(){
        if (isEmpty()) {
            cout<<"Queue Empty. Cannot dequeue process"<<endl;
            return Process(-1, -1);
        }
        Process temp = queueArr[frontIndex];
        if (frontIndex == rearIndex)
            frontIndex = rearIndex = -1;
        else
            frontIndex++;
        return temp;
    }

    int size(){
        if (isEmpty())return 0;
        return (rearIndex - frontIndex + 1);
    }

    Process getProcess(int i) { return queueArr[frontIndex + i]; }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;;
            return;
        }
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << "ID " << queueArr[i].processID<<" - Priority "<<queueArr[i].priority<<" ";
        }
        cout << endl;
    }
};

int findHighestPriority(Queue &q){
    int highest = -1;
    for (int i = 0; i < q.size(); i++) {
        Process p = q.getProcess(i);
        highest = max(highest, p.priority);
    }
    return highest;
}

int main() {
    Queue readyQueue;
    Stack executionStack;
    readyQueue.enqueue(Process(0, 2));
    readyQueue.enqueue(Process(1, 5));
    readyQueue.enqueue(Process(2, 3));
    readyQueue.enqueue(Process(3, 5));
    readyQueue.enqueue(Process(4, 1));

    cout << "Initial Ready Queue State"<<endl;
    readyQueue.display();
    cout << endl;

    while (!readyQueue.isEmpty()){
        int highest = findHighestPriority(readyQueue);
        int queueSize = readyQueue.size();

        
        for(int i = 0; i < queueSize; i++){
            Process p = readyQueue.dequeue();
            if(p.priority == highest){
            	executionStack.push(p);
			}  
            else{
            	readyQueue.enqueue(p);
			}   
        }
        while (!executionStack.isEmpty()){
            Process p = executionStack.pop();
            cout<<"Executing Process ID " << p.processID<<"(Priority"<<p.priority<<")"<<endl;
        }
        cout<<endl;
    }
    return 0;
}

