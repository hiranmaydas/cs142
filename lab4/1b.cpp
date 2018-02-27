#include<iostream>
using namespace std;

class node{//node class consisting only two element data and address of next node
	public:
	float data; 
	node* next;
};
class queuell{ //queuell class consisting of head and tail node pointer and push,pop and show function
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
	node* temp =new node; //declaring a new object
	temp ->data = data; //assign data of temp by data
	temp->next=NULL; //making the next pointer of temp as NULL 
	if (head ==NULL){ //if theere is no element in the queue
		head =temp ; //pointing both head and tail to the new object
		tail =temp;
	}	
	else { //else attaching the element next to tail and then point tail to the new object
		tail->next =temp;	
		tail =temp;
	}
	cout<<"pushed"<<endl; //confirm messege for pushing 
}
void queuell::pop(){ //pop function
	if (head==NULL){ //if no element in queue
		cout<<"This queue is empty you can't pop any more"<<endl;
	}
	else if(head==tail){ //if only one element in queue
		node* temp =head; //deleting the first element and pointing head and tail to NULL
		delete temp;
		head =NULL;
		tail= NULL;
		cout<<"popped"<<endl;
	}
	else { //if there is more than one element in linked list
	 	node* temp =head;//pointing temp to 1st element
		head =head->next; //pointing head to the 2nd element
		delete temp; //deleting the 1st element
		cout<<"popped"<<endl;
	}
}
void queuell::show(){ //function to show the queue
	node* temp =head;
	if(head==NULL){ //if the list is empty
	cout<<"there is nothing to show"<<endl;
	}
	else {
		while(temp!=tail){ //until the last element is reached 
		cout<<temp->data<<"->";//showing the data of  elements
		temp=temp->next;	
		}
		cout<<temp->data<<endl; //showing the data of last element
	}
}
