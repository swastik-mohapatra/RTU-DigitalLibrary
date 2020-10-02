#include<iostream>
using namespace std;

class node {//defining node class
public:
	int data;
	node* next;

	//constructor
	node(int d) {
		data=d;
		next=NULL;
	}
};

//passing the pointer by reference
void insertAtHead(node* &head,int d) {
	if(head==NULL) {
		head=new node(d);//it creates a new node of data 3 and pointer is null and the head value changes
		return;
	}
	node *n=new node(d);//here n is the pointer of the new node
	(*n).next=head;//or n->next=head;
	head=n;//now head is the address of new node
}
void print(node*head) {
	while(head!=NULL) {
		cout<<head->data<<" ->";
		head=head->next;
	}
	cout<<endl;
}
// void reverse(node* &head) {
// 	node* prev=NULL;
// 	node* curr=head;
// 	node*N;
// 	while(curr!=NULL) {
// 		//save the address of curr to the next node
// 		N=curr->next;
// 		//make the current node point to prev
// 		curr->next=prev;
// 		//update the  prev and curr
// 		prev=curr;
// 		curr=N;
// 	}
// 	head=prev;
// }
node* recReverse(node* &head) {
	//base case
	if(head->next==NULL or head==NULL) {
		return head;
	}

	//rec case 
	node * shead=recReverse(head->next);
	node * temp=shead;

	while(temp->next!=NULL) {
		temp=temp->next;
	}
	head->next=NULL;
	temp->next=head;
	return shead;
}
 


int main() {
	node*head=NULL;//1st node address
	insertAtHead(head,3);//here 3 is the data to be inserted at the head
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);

	print(head);  //if we pass by refernce then it will become null
	////////
	head=recReverse(head);
	print(head);

	return 0;


}