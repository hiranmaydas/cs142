#include<iostream>
using namespace std;

int count=0;
void push(float* list);
void pop(float* list);
void show(float* list);

int main(){
	float* list;	
	cout<<"NUMber of data to push:"<<endl;
	int num;
	cin>>num;
	for(int i =0; i<num; i++){
		push(list);
	}
	cout<<"new stack"<<endl;
	show(list);
	cout<<"Number of data you want to pop"<<endl;
	cin>>num;
	for(int i= 0; i<num; i++){
		pop(list);
	}
	cout<<"new stack"<<endl;
	show(list);
	
	return 0;
}
void push(float* list){
	cout<<"Data"<<count<<":";
	float data;
	cin>>data;
	list[count]=data;
	count++;
}
void pop(float* list){
	count--;
}
void show(float* list){
	if(count==0){
		cout<<"There is nothing to show";
	}
	for(int i=0; i<count; i++){
		cout<<list[i]<<"->";
	}
	cout<<endl;
}

