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
Node* reverseLinkedList(Node* head){
	Node* p = head;
	Node* q = 0;
	Node* r = 0;
	while(p!=0){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	return q;
}
void palindromeChecker(Node* head){
	Node* fast = head;
	Node* slow = head;
     
    while(fast->next != 0 && fast->next->next !=0){
    	slow = slow->next;
    	fast = fast->next->next;
	}
	int flag =0;
	slow->next = reverseLinkedList(slow->next);
	Node* secondHalf = slow->next;
	Node* firstHalf = head;
	while(secondHalf!=0){
		if(firstHalf->data != secondHalf->data){
			cout<<"---NOT PALINDROME---"<<endl;
			flag = 1;
			return;
		}
		firstHalf = firstHalf->next;
		secondHalf = secondHalf->next;
	}
	if(flag==0){
		cout<<"The linked list was palindrome"<<endl;
	}
}
int main(){
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(2);
	head->next->next->next->next = new Node(1);
	palindromeChecker(head);
}
