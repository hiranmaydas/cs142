//Implimentation of stack by array
#include<iostream>
using namespace std;

int count=0; //a global variable to count the number of element of  stack
void push(float* list);
void pop(float* list);
void show(float* list);

int main(){
	float* list;//declaring a pointer of float elemt	
	cout<<"NUMber of data to push:"<<endl;
	int num;
	cin>>num;
	for(int i =0; i<num; i++){ //loop to entr the data of stack
		push(list); //calling push function by the pointer list 
	}
	cout<<"new stack"<<endl;
	show(list); ///showing the data of stack
	cout<<"Number of data you want to pop"<<endl;
	cin>>num;
	for(int i= 0; i<num; i++){ //loop to pop  multiple times 
		pop(list); //calling pop function
	}
	cout<<"new stack"<<endl;
	show(list); //showing list after pop
	
	return 0;
}
void push(float* list){
	cout<<"Data"<<count<<":";
	float data; 
	cin>>data; //taking data from user
	list[count]=data; //insert the data to the stack
	count++; //incrementing counting as one data is added 
}
void pop(float* list){
	count--; //decrementing count as popped up 
}
void show(float* list){
	if(count==0){ //if the list is empty
		cout<<"There is nothing to show";
	}
	for(int i=0; i<count; i++){ //running loop to show the data
		cout<<list[i]<<"->"; //showing i-th data
	}
	cout<<endl;
}
