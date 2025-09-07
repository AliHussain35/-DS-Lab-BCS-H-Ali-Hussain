#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node* childPointer;
		Node(int val){
			data = val;
			next = 0;
			childPointer = 0;
		}
};
Node* flattenLinkList(Node* head){
	Node* curr = head;
	while(curr != 0){
		if(curr->childPointer != 0){
			Node* child = flattenLinkList(curr->childPointer);
			Node* nextNode = curr->next;
			curr->next = curr->childPointer;
			curr->childPointer = 0;
			while(curr->next != 0){
		    	curr= curr->next;
			}
			Node* tail = curr;
			tail->next = nextNode;
		}
		curr = curr->next;
	}
	return head;
}
int main() {
    //link list as per given in the question
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->childPointer = new Node(4);
    head->next->childPointer->next = new Node(5);
    Node* flatten = flattenLinkList(head);
    Node* temp = flatten;
    while(temp != 0){
        cout<<temp->data;
        if (temp->next != 0){
        	cout<<" -> ";
		}
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}

