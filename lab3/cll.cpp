//Hiranmay Das // Roll - 1711061
#include<iostream>
using namespace std;
int count=0;
class node{  //declaring a node class to contain data and the addresse of previous and next element;
	public:
	double data;
	node*  next;
	node* pre;
	public:
	node(){  //constructor to make the next and pre null as soon as the new node will be defined and data is made 0;
		data=0;
		next=NULL;
		pre=NULL;
	}
};

class link{ //link list class has been declare which contains head (node pointer)
	node* head ;
	public:
	link(){  //constructor of link class, which make the head and tail NULL
		head=NULL;
	}
	/* NOw declaring a bunch of function which is associated with link list class*/
	void insert(double data);
	void insert(double data, int pos);
	void dlt();
	void dlt(int pos);
	void countitem();
	void show();
};
int  main(){
	cout<<"This is a program to implement circular linked list"<<endl;
	cout<<"Creating a linked list"<<endl;
	link list;
	cout<<"Enter how many data you have"<<endl;
	int num;
	cin>>num;
   	for(int i=0; i<num; i++){
		cout<<"Data_"<<i+1<<":";
		int data;
		cin>>data;
		list.insert(data);
	}
	list.show();
	cout<<"Now enter data and position respectively"<<endl;
	int data;
	int position;
	cin>>data;
	cin>>position;
	list.insert(data, position);
	list.show();
	cout<<"Now deleting the last data"<<endl;
	list.dlt();
	list.show();
	cout<<"Enter a position to delete that data"<<endl;
	cin>>position;
	list.dlt(position);	
	cout<<"New list"<<endl;
	list.show();
	cout<<"Number of data you have: "<<endl;
	list.countitem();
	return 0;
		
}
void link::insert(double data){
	node* temp=new node; //creating a new object
	temp->data=data; //asigning the data as data of the object
	if(head!=NULL){
		temp->pre=head->pre; //point the pre of temp to  the previously last element 
		(head->pre)->next=temp; // point the next of previously last element to temp
	}
	else {
		head=temp; //making the new node as head and initiate the list
	}
	head->pre=temp; //shifting tail to temp
	temp->next=head;
	count++; //as one item has been added so count will be one more
}
void link::insert(double data, int posi){
	node* temp=new node; //declaring a new object
	temp->data=data;
	node* pos=head;
	if(head==NULL){
		cout<<"This linked list is empty the entered data is added"<<endl;
		insert(data);
	}
	else if(posi==count+1){
		insert(data); //call the function to add data at the  end
	}
	else {
		for(int i=1; i<posi; i++){
			pos=pos->next; //goes to next node until the pos-th node is reached
		}
		temp->next =pos;
		temp->pre=pos->pre;
		(pos->pre)->next=temp;
		pos->pre=temp;
	}	
	count++; // as one item is added 
}	
void link::dlt(){
	if(head!=NULL){ //if the list is not empty
		node* temp=head->pre ; //declaring a node pointer and point it to post head element
		((head->pre)->pre)->next=head; // pointing pre of to the head
		head->pre =(head->pre)->pre; //ohh shit
		delete temp; // deleting temp
		count--; //as a element is deleted so count will be one less
	}
	else cout<<"There is nothing to delete"<<endl;
}

void link::dlt(int posi){ //function to delete at a position 
	if(posi==count){ // if the last element is said to delete
		dlt(); // call the delete function to delete at the end
	}
	else if(head!=NULL){ // if the list is non-empty
		node* pos=head; 
	
			for(int i=1; i<posi; i++){ // until we  get the same node as posi
				pos=pos->next; //goes to the next node

			}
			if (count!=1 && posi!=1){	// if it is not the first element and there is only one element
				(pos->pre)->next=pos->next; //ohh shit
				(pos->next)->pre=pos->pre;  //dhurr
				delete pos;
			}	
			else if(posi==1){ //special case
				head =head->next; //pointing head to the next node
				head->pre=NULL; //pointing the pre of first element NULL
		  		delete pos; // deleting the object pointed by pos
			}		
			count--; //as a node hasbeen deleted so the count will be one less
		}
	
	else cout<<"There is nothing to delete"<<endl;	
	
}

inline void link::countitem(){
	cout<<count<<endl;
}
void link::show(){
	node* temp=head; //making temp to be head;
	while(temp->next!=head){ //while we got the last element
		cout<<temp->data<<" <-> "; // print the data of the element
		temp =temp->next; //goes to the next node
	}
	cout<< temp->data; //it shows the data of last element
	cout<<endl; //used for show off;
}
			


