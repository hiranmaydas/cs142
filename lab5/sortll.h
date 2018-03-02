//Hiranmay Das
//Roll-1711061
#include<iostream>
using namespace std;

class node{   //defining node class
	public:
	int data;  //data hold the data of each elements in linked list
	node *next;//next stores the address of previous node
};
class l_list{
	node *head; //head store the address of the first element of the linked list	
	node *tail; //tail stores the address of the last element of the linked list
	int count;
	public:
	l_list(){ //constructor to make the head and tail of the linklist null(they point nothing )
		head=NULL;
		tail=NULL;
		count=0;
	}
	void insert(int data); //to insert the data at the end of the linked list
	void show(); //to display the element
	void qsort(node* node1, node* node2);
	void swap(node* node1, node* node2);
	node* partition(node* node1, node* node2);
	void qsort();
	void bsort();
};

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
void l_list::swap(node* node1, node* node2){
	int temp=node1->data; //temp stores the data of node1 
	node1->data=node2->data; //node1 is assigned with node2 value
	node2->data=temp; //finally node2 is assigned with the previous value of node1 
}
node*  l_list::partition(node* lnode, node* rnode){
	int pivot =rnode->data; //make the last element of the partion as pivot
	node* tempi=lnode; //start from the previous of  left part of the partion 
	node* tempj=lnode->next; //temp j will start from the left part of the partition 
	while(tempj!=rnode){ //untill we reached the last element of the partition
		if(tempj->data<=pivot){// if the jth data is less than the pivot 
			tempi=tempi->next; //increment tempi to one to hold that small element
			swap(tempi,tempj); //swap the smaller element with bigger one
		}
		tempj=tempj->next; //go to the next node
	}
	swap(tempi->next, rnode); //swap to make the pivot as i+1the element
	return tempi; //return the address of tempi;
}
void l_list::qsort(node* node1, node* node2){
	if(node1!=node2){ //until only one element left
		node* temp =partition(node1, node2); //make partition and take the pivot element
	    qsort(node1, temp); //call the function recursively 
	 	temp=temp->next; //increment the temp to next node
   		qsort(temp, node2); //again call the function recursively to sort the right part
 	}		
}
void l_list::qsort(){
	if(head==NULL){ //if there is no element
		cout<<"Nothing to sort"<<endl; 
	}
	else if(head==tail){ //if there is only one element on the list
		cout<<"list consists of only one element"<<endl;
	}
	else{
		node* temp=new node; //declarign an extra node to keep something before head
		temp->next=head;
		temp->data=0;
	 	qsort(temp, tail); //calling qsort with temp and tail instead of head and tail
		//as if we start from head then there will be problem in partition
	}
}
void l_list::bsort(){
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
