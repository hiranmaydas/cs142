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
};
int main(){
	char chc='a';
	l_list ll; //defining a linked list named ll
	while(chc!='q'){ //this looop will run until you enter q when asked
	cout<<endl<<endl;
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout<<"This is a program which store data using link list."<<endl;
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout<<"a. Creat link list"<<endl;
	cout<<"b. Add multiple element at the end of the link list "<<endl;
	cout<<"c. Add element by position "<<endl;
   	cout<<"d. Delete the last element of the linked list "<<endl;
	cout<<"e. Delete the element by its position "<<endl;
	cout<<"f. Display the linked list"<<endl;
	cout<<"g. Display the number of elements"<<endl;
	cout<<" Enter your choice... Enter q to exit "<<endl;	
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout<<endl<<endl;
	cout<<"Your choice: "; //making fun of the user
	cin>>chc; //getting choice
	if (chc=='a'){
	cout<<"Created."<<endl;
	}
	if (chc=='b'){//program to insert the data at the end
	cout<<"How many data you have "<<endl;

	int num ;
	cin>>num;
	for(int i=0; i<num; i++){
		cout<<"Data"<<i+1<<" ";
    	int data; 
		cin>>data;//taking input as data
		ll.insert(data); //inserting the data by calling insert function
	}
	}
	if(chc=='c'){ //program to insert at a certain position
	cout<<"Add data in a certain position"<<endl;
	cout<<"How many data do you have ?"<<endl;
	int num;
	cin>>num;
	int data,pos;
	for (int i=0;i<num; i++){ //taking data repeatedly
	cout<<"Data: ";
	cin>>data;
	cout<<"position: ";
	cin>>pos;
	ll.insert_at(data, pos); //inserting data by calling insert_at function
	cout<<"New linked list"<<endl;
	ll.show(); // showing the modified link list by calling show function 
	}
	}
	if (chc=='d'){ //program to delete the last element
	cout<<"Do you want to delete the last element of this linked list"<<endl;
	cout<<"If yes please enter y"<<endl;
	char choice='n';
	cin>>choice;
	if (choice =='y' || choice =='Y'){
		ll.delt();//    delete the last element of ll by calling delt function
		cout<<"New linked list"<<endl;
		ll.show(); // again showing the link list
	}	
	}
	//program to delete elements of linked list at a certain position
	if(chc=='e'){
	cout<<"How many data you want to delete : "<<endl;
	int num,pos;
	cin>>num;
	for(int i=0; i<num;i++ ){
	cout<<"Enter the position of the data "<<endl;
	cin>>pos;
	ll.delete_at(pos); ///deleting by calling delete_at function 
	cout<<"New linked list "<<endl;
	ll.show();
	}
	}
	//program to show the linked list
	if(chc=='f'){
	cout<<"Elements of the linked list"<<endl;
	ll.show();// showing the linked list by calling show function 
	}
	if (chc=='g'){
		cout<<"The number of node in this linked list is : "<<count<<endl;
	}
	if(chc=='q'){
		break;
	}
	char foo; 
	cout<<endl<<"Enter any key and press |[Enter]|"<<endl;
	cin>>foo;
	}
	return 0;


}

//insert function to insert a new element at the end of the list
void l_list::insert(int data){
	node* temp = new node; // declaring a new object of type node
	temp->data=data;// inserting the data at the objectk
	if (head == NULL){ //if the list is empty 
		head=temp; // head will point temp  
		tail =temp;
		temp->next=NULL;
	}
	else {
		tail->next= temp;
		temp->next=NULL;
		tail = temp;
	}	
	count++;
}
void l_list::insert_at(int data, int pos){
	if(pos<=count+1){
	node* pos1;
	pos1=head;
	node* pos2;
	pos2=NULL;
	node *temp;
	temp->data=data;
	for (int i = 2; i<pos; i++ ){
		pos1= pos1->next;
	}
	pos2= pos1->next;
	pos1->next =temp;
	temp->next=pos2;	
	count++;
	}
	else cout<<"YOU DON'T HAVE THAT MUCH NUMBER OF ELEMENT."<<endl;
}
void l_list::delt(){
	if(count>1){
	node* temp;
    temp=tail;
	tail=head;
	for (int i=2; i<count; i++){
		tail=tail->next;
	}
	tail->next=NULL;
	delete temp;
	count--;
	}
	else if(count==1){
		head=NULL;
		node* temp =tail;
		tail=NULL;
		delete temp;
		count --;
	}
	else cout<<"There is nothing to delete."<<endl;
}
void l_list::delete_at(int pos){
	if (pos<=count && count!=1 && pos!=1){
	node* temp=NULL;
	node* previous=head;
	for (int i=2; i<pos; i++){
		previous=previous->next;
	}	   
	temp =previous->next;
	previous->next=temp->next;
	delete temp;
	count --;
	}
	else if (pos==1 && count >1){
		node *temp=head;
		head =head->next;
		delete temp;
		count --;
	}
	else if(count==1){
		node* temp;
		head =NULL;
		temp = tail;
		tail=NULL;
		delete temp;
		count--;
	}
	else cout<<"You don't have "<<pos<<"th element in linked list."<<endl;
}
void l_list::show(){
	node* temp=head;
	if(head== NULL){
	cout<<"Oops..Nothing is here to print."<<endl;
	}
	else{
	while(temp!=NULL){
	   	cout<<temp->data<<" -> ";
		temp=temp->next;
		
	}
	cout<<endl;
	}
}
