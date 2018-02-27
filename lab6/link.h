#include<iostream>
using namespace std;


class node{   //defining node class
	public:
	int data;  //data hold the data of each elements in linked list
	node *next;//next stores the address of previous node
	int count;
};
class l_list{
	public:
	node *head; //head store the address of the first element of the linked list	
	node *tail; //tail stores the address of the last element of the linked list
	int cnt;
	l_list(){ //constructor to make the head and tail of the linklist null(they point nothing )
		head=NULL;
		tail=NULL;
		cnt=0;
	}
	void insert(int data); //to insert the data at the end of the linked list
	void delt(); //to delete the last element
	void show(); //to display the element
	void sort();
};
//insert function to insert a new element at the end of the list
void l_list::insert(int data){
	node* temp = new node; // declaring a new object of type node
	temp->data=data;// inserting the data at the objectk
	if (head == NULL){ //if the list is empty 
		head=temp; // head will point temp  
		tail =temp; //tail will point temp
		temp->next=NULL; //making next of temp to NULL
	}
	else {
		tail->next= temp; //making link with new object to tail
		temp->next=NULL; //making the next of new element to NULL
		tail = temp; //pointing tail to the new element
	}	
	cnt++;
}

void l_list::delt(){
	node* temp=head; //declaring a pointer to point the element which has to be deleted
	if(head!=NULL){
		while(temp!=tail->next ){
			temp=temp->next;
		}
		tail=temp;
		if(temp->next!=NULL){
			temp=temp->next;
		}
	 	delete temp;
		cnt--;
	}
	else cout<<"There is nothing to delete."<<endl;
}
void l_list::show(){
	node* temp=head; //declaring a new pointer to point the nodes which have to be shown
	if(head== NULL){ //if the link list is empty
	cout<<"Oops..Nothing is here to print."<<endl;
	}
	else{
	while(temp!=NULL){ //untill reach the last element// the last element's next is NULL
	   	cout<<temp->data<<" -> "; //showing the data of the nodes as mentioned
		temp=temp->next; //proceeding to next element
		
	}
	cout<<endl;
	}
}
void l_list::sort(){
	for(int i=0;i<cnt;i++){
		node* temp=head;
		while(temp!=tail){
			if(temp->data > temp->next->data){
				int tmp=temp->data;
				temp->data=temp->next->data;
				temp->next->data=tmp;
			}
			temp=temp->next;
		}
	}
}
//Thank you 
