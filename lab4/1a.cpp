#include<iostream>
using namespace std;

class node{
	public:
	float data; 
	node* next;
};
class stackll{
	node* bottom, *top; 
	public:
	stackll(){
		bottom = NULL;
		top = NULL;
	}
	void push(float data);
	void pop();
	void show();
};
int main(){
	stackll stack;
	cout<<"This is to implement stack using linklist"<<endl;
	cout<<"How many data you have?"<<endl;
	int num;
	cin>>num;
	int data;
	for(int i=0; i<num; i++){
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
 
void stackll::push(float data){
	node* temp =new node;
	temp ->data = data;
	temp->next=NULL;
	if (bottom ==NULL){
		bottom =temp ;
		top =temp;
	}	
	else {
		top->next =temp;	
		top =temp;
	}
}
void stackll::pop(){
	if (bottom==NULL){
		cout<<"This stack is empty you can't pop any more"<<endl;
	}
	else if(bottom==top){
		node* temp =bottom;
		delete temp;
		bottom =NULL;
		top= NULL;
	}
	else {
		node* temp=bottom;
		while(temp->next !=top &&  temp->next!=NULL){
			temp =temp->next;
		}
		top =temp;
		temp =temp->next;
		delete temp;
	}
}
void stackll::show(){
	node* temp =bottom;
	if(bottom==NULL){
	cout<<"there is nothing to show"<<endl;
	}
	else {
		while(temp!=top){
		cout<<temp->data<<"->";
		temp=temp->next;	
		}
		cout<<temp->data<<endl;
	}
}
