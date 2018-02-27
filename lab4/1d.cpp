#include<iostream>
using namespace std;

int count=0; //declaring a global function to count the number of data
int pos=0; 
void push(float* list); //function to push
void pop(float* list); //function to pop
void show(float* list); //function to show

int main(){
	float* list;	
	cout<<"NUMber of data to push:"<<endl;
	int num;
	cin>>num;
	for(int i =0; i<num; i++){ //loop to push multiple times
		push(list); //calling the push to insert data
	}
	cout<<"new stack"<<endl;
	show(list); //showing the queue
	cout<<"Number of data you want to pop"<<endl; 
	cin>>num;
	for(int i= 0; i<num; i++){ //loop for popping multiple times
		pop(list); //calling pop function with reference to the first element of the queue
	}
	cout<<"new stack"<<endl;
	show(list); //shoeing the queue
	
	return 0;
}
void push(float* list){
	cout<<"Data"<<count<<":";
	float data;
	cin>>data; //taking data from the user 
	list[count]=data; //inserting the data to queue
	count++; //incrementing count to one as one item is added
	cout<<"pushed"<<endl;
}
void pop(float* list){
	pos++; //pos is incremented, now the show  function will show the data after pos
	cout<<"pooped"<<endl;
	
}

void show(float* list){
	if(count==0){
		cout<<"There is nothing to show";
	}
	else{
		float* temp=list; 
		for(int i=pos; i<count; i++){ //runnig loop number of times same as count-pos
			cout<<temp[i]<<"->"; //showing the data after pos
		}
	}
	cout<<endl;
}

