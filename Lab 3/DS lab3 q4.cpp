#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int val){
			data = val;
			next = 0;
		}
};
Node* JosephusProblem(Node* head, int N, int k){
	Node* p = head;
	Node* q = 0;
	while(N>1){
		for(int i=0; i<k-1; i++){
			q = p;
			p = p->next;
		}
		q->next = p->next;
		delete p;
		p = q->next;
		N = N-1;
	}
	return p;
}

void insertNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        head->next = head; 
        return;
    }
    Node* temp = head;
    while (temp->next != head) { 
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head; 
}


int main(){
    Node* head = 0;
    Node* List2head = 0;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 7);
    Node* node = JosephusProblem(head, 7, 3);
    cout<<"The survivor is = "<<node->data<<endl;
    return 0;
}
