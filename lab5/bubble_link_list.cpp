//Hiranmay Das
//Roll-1711061
#include<iostream>
using namespace std;

int count=0;

class node{   //defining node class
	public:
	int data;  //data hold the data of each elements in linked list
	node *next;//next stores the address of previous node
};
class l_list{
	node *head; //head store the address of the first element of the linked list	
	node *tail; //tail stores the address of the last element of the linked list
	public:
	l_list(){ //constructor to make the head and tail of the linklist null(they point nothing )
		head=NULL;
		tail=NULL;
	}
	void insert(int data); //to insert the data at the end of the linked list
	void insert_at(int data , int pos);// to insert the data of the linked list in a certain position
	void delt(); //to delete the last element
	void delete_at(int pos); //to delete the element at a certain position
	void show(); //to display the element
	void sort();
};
int main(){
	cout<<"This is the program to implement bubble sorting"<<endl;
	cout<<"Enter the number of data"<<endl;
	int num; //hold the number of data;
	cin>>num;
	l_list link; //declaring link list;
	for(int i=0; i<num; i++){ //loop to take the data of the list from user;
		int data;
		cout<<"Data"<<i+1<<":";
		cin>>data;
		link.insert(data); //calling insert function 
	}

	cout<<"Do you want to sort those data?"<<endl;	
	cout<<"y/n"<<endl;
	char choice;
	cin>>choice;
	if(choice=='y' ||choice=='Y'){ //if user enter y or Y
		link.sort(); //calling the sorting function
		cout<<"Sorted link list is below:"<<endl;
		link.show(); //showing the sorted list by calling show function
	}
	else cout<<"Thank you"<<endl;	
	return 0;


}


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
	count++; //incrementing the count as a new element is added
}

void l_list::sort(){
	node* temp; //defining a node type pointer to access the nodes of the list
	if(head==NULL){
		cout<<"No data to sort"<<endl;
	}
	else if(head==tail){
		cout<<"this list contains only one element"<<endl;
		cout<<"the element of the list is"<<head->data<<endl;
	}

	else {
		for(int i=0; i<count;i++){ //loop to repeat the inner loop n times
		temp=head; //starting from the head;
		for(int j=0; j<count-i-1; j++){
			if(temp->data>(temp->next)->data){
				int val =temp->data;
				temp->data=(temp->next)->data;
				(temp->next)->data=val;
			}
			temp=temp->next;
		}
	}
	}
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
//Thank you 
