#include<iostream>
using namespace std;

class node{
	public:
	float data; 
	node* next;
};
class queuell{
	node* head, *tail; 
	public:
	queuell(){
		head = NULL;
		tail = NULL;
	}
	void push(float data);
	void pop();
	void show();
};
int main(){
	queuell stack;
	cout<<"This is to implement queue using linklist"<<endl;
	cout<<"How many data you have?"<<endl;
	int num;
	cin>>num;
	int data;
	for(int i=0; i<num; i++){
		cout<<"Data"<<i+1<<":"<<endl;
		cin>>data;	
		stack.push(data);
	}
	stack.show();
	cout<<"number of data you want to delete"<<endl;	
	cin>>num;
	for(int i=0; i<num; i++){
		stack.pop();
	}
	stack.show();
	return 0; 
}
 
void queuell::push(float data){
	node* temp =new node;
	temp ->data = data;
	temp->next=NULL;
	if (head ==NULL){
		head =temp ;
		tail =temp;
	}	
	else {
		tail->next =temp;	
		tail =temp;
	}
	cout<<"pushed"<<endl;
}
void queuell::pop(){
	if (head==NULL){
		cout<<"This queue is empty you can't pop any more"<<endl;
	}
	else if(head==tail){
		node* temp =head;
		delete temp;
		head =NULL;
		tail= NULL;
		cout<<"popped"<<endl;
	}
	else {
	 	node* temp =head;
		head =head->next;
		delete temp;
		cout<<"popped"<<endl;
	}
}
void queuell::show(){
	node* temp =head;
	if(head==NULL){
	cout<<"there is nothing to show"<<endl;
	}
	else {
		while(temp!=tail){
		cout<<temp->data<<"->";
		temp=temp->next;	
		}
		cout<<temp->data<<endl;
	}
}
