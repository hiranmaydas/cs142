#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
};
class link{
	public:
	node* head;
	node* tail;
	int num;
	link(){
		head =NULL;
		tail=NULL;
		num=0;
	}
	void insert(int d);
	void reverse();
	void show();
};

int main(){
	link list;
	for(int i=0; i<5; i++){
		int d;
		cin>>d;
		list.insert(d);
	}
	list.show();
	cout<<"reversing..."<<endl;
	list.reverse();
	cout<<"Reversed list is here>>"<<endl;
	list.show();
}
	


void link::insert(int d){
	node* temp=new node;
	temp->data=d;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
		tail->next=temp;
	}
	tail=temp;
	num++;
}

void link::reverse(){
	node* temp1=tail;
	tail=head;
	while(temp1!=head){
		node* temp=head;
		head=head->next;
		temp->next=temp1->next;
		temp1->next=temp;
	}
	
}
void link::show(){
		node* temp=head;
		while(temp!=NULL){
			cout<<temp->data;
			cout<<"->";
			temp=temp->next;
		}
}
