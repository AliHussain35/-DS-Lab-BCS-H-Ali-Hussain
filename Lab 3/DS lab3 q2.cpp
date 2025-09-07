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
Node* mergetwoSortedLists(Node* head1, Node* head2){
    Node* head3 = 0;
    Node* ptr3 = 0;
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1 != 0 && ptr2 != 0){
        if (ptr1->data <= ptr2->data){
            if (head3 == 0) {
                head3 = ptr1;
                ptr3 = head3;
                ptr1 = ptr1->next;
            }else{
                ptr3->next = ptr1;
                ptr1 = ptr1->next;
                ptr3 = ptr3->next;
            }
        }else{
            if(head3 == 0){
                head3 = ptr2;
                ptr3 = head3;
                ptr2 = ptr2->next;
            }else{
                ptr3->next = ptr2;
                ptr2 = ptr2->next;
                ptr3 = ptr3->next;
            }
        }
    }

    if(ptr1 != 0){
    	ptr3->next = ptr1;
	} 
    if(ptr2 != 0){
    	ptr3->next = ptr2;
	} 

    return head3;
}

void insertNode(Node*& head, int val){
    Node* newNode = new Node(val);
    if(!head){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != 0){
        temp = temp->next;
    }
    temp->next = newNode;
}
void printLinkedlist(Node* head){
    while(head != 0){
        cout<<head->data;
        if(head->next){
        	cout<<" -> ";
		} 
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node* List1head = 0;
    Node* List2head = 0;

    insertNode(List1head, 1);
    insertNode(List1head, 3);
    insertNode(List1head, 5);

    insertNode(List2head, 2);
    insertNode(List2head, 4);
    insertNode(List2head, 6);

    cout<<"---Linked List 1 = ";
    printLinkedlist(List1head);
    cout<<"---Linked List 2 = ";
    printLinkedlist(List2head);

    Node* mergedListHead = mergetwoSortedLists(List1head, List2head);

    cout<<"---Merged List = ";
    printLinkedlist(mergedListHead);

    return 0;
}
