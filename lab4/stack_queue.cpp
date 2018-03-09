#include<iostream>
using namespace std;

class node{ //node class consisting of data and a node pointer to store the address of 
	//next node of the linked list
	public:
	float data; 
	node* next;
};
class stackll{ //stack class consists of bottom and top node type pointer, constructor and //some function
	public:
	node* bottom, *top; 
	stackll(){
		bottom = NULL;
		top = NULL;
	}
	void push(float data); //function to push
	void pop(); //function to pop 
	void show(); //function to show 
	void mkqu(node* bottom); //function to make queue from two stack
	void dlt(); //function to dlt the whole stack
};
class queue{ //queue class consisting of two stacks 
	stackll stack1, stack2;
	public:
	void push(); //function to push 
	void pop(); //function to pop
	void show(); //function to show
};
int main(){
	queue one;
	cout<<"This is to implement queue using two stack"<<endl;
	one.push();
	one.show();
	one.pop();
	one.show();
	return 0; 
}
 
void stackll::push(float data){
	node* temp =new node; //creating temp object
	temp ->data = data; //inserting the data
	temp->next=NULL; //making the next of the temp as null
	if (bottom ==NULL){ //if the list is empty
		bottom =temp ;
		top =temp;
	}	
	else {
		temp->next=bottom; //adding the temp to the bottom 
		bottom =temp;
	}
}
void stackll::pop(){
	if (bottom==NULL){ //if the list is empty
		cout<<"This stack is empty you can't pop any more"<<endl;
	}
	else if(bottom==top){ //if there is only one item
		node* temp =bottom;
		delete temp; //deleting the item
		bottom =NULL;
		top= NULL;
	}
	else {
		node* temp=bottom;
		bottom=bottom->next; //going to the second last element
		delete temp; //deleting the last element
	}
}
void stackll::show(){
	node* temp =bottom;
	if(bottom==NULL){//if there is no item in the stack
	cout<<"there is nothing to show"<<endl;
	}
	else {
		while(temp!=top){ //while we reach to the first element
		cout<<temp->data<<"->"; // showing the data of temp
		temp=temp->next;	 //going to next node of temp
		}
		cout<<temp->data<<endl; //showing the data of top
	}
}
void stackll::mkqu(node* bottom){  //taking the bottom of one stack
		node* temp =bottom;
		if(bottom!=NULL){ //if the stack is nonempty
			while(temp->next!=NULL){ //until the top element is reached
				push(temp->data); //pushing the data with the data got from another stacck
				temp=temp->next;
			}
			push(temp->data);
		}
}	
void stackll::dlt(){
	while(bottom!=NULL){ //popping up untill the stack is empty
		pop();
	}	
}


void queue::push(){
	cout<<"Number of data"<<endl;
	int num,data; 
	cin>>num;
	for(int i=0; i<num; i++){ //pushing the data multiple times using loop
		cout<<"Data"<<i+1<<":";
		cin>>data; 
		stack1.push(data); //pushing data to stack1
	}
	stack2.dlt(); //deleting stack2
	stack2.mkqu(stack1.bottom); //loading stack2 by the data of stack1
}	
void queue::pop(){
	cout<<"Number of data you want to delete:"<<endl;
	int num;
	cin>>num;
	for(int i=0; i<num; i++){ //popping up multiple times
		stack2.pop(); //popping up stack2
	}
	stack1.dlt(); //deleting the whole data of stack1
	stack1.mkqu(stack2.bottom); //making stack from data of stack2
}	
void queue::show(){
	stack1.show(); //shoing the queue 
}
