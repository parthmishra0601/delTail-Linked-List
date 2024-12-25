#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int n){
		data=n;
		next=NULL;
	}
};
Node *delTail(Node *head){
	if(head==NULL){
		return NULL;
	}
	if(head->next==NULL){
		delete head;
		return NULL;
	}
	Node *curr=head;
	while(curr->next->next!=NULL){
		curr=curr->next;
		delete(curr->next);
		curr->next=NULL;
		return head;
	}
}
void display(Node *head){
	Node *curr=head;
	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr=curr->next;
	}
}
int main(){
	Node *head=new Node(20);
	head->next=new Node(30);
	head->next->next=new Node(40);
	head=delTail(head);
	display(head);
	return 0;
}
