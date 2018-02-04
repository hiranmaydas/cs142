#include<iostream>
using namespace std;

float* bubble(float* p,int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size-i;j++){
			if(p[i]>p[i+1]){
				float a =p[i];
				p[j]=p[j+1];
				p[j+1]=a;
			}
		}
	}
	cout<<"func"<<endl;
	return p;
}
int main(){
	float* arr;
	float init=0;
	arr=&init;
	cout<<"initiali"<<endl;
	cout<<"This is a program to implement bubble sort"<<endl;
	cout<<"Please enter how much data you have"<<endl;
	int num;
	cin>>num;
	for(int i=0; i<num; i++){
		cout<<"Data"<<i+1<<": ";
		cin>>arr[i];
	}	
	arr=bubble(arr,num);
	cout<<"Sorted data is as follows"<<endl;
	for(int i=0; i<num; i++){
		cout.width(10);
		cout<<arr[i];
	}
	return 0;
}
