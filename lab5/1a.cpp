#include<iostream>
using namespace std;

float* bubble(float* p,int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size-i-1;j++){
			if(p[j]>p[j+1]){
				float a =p[j];
				p[j]=p[j+1];
				p[j+1]=a;
			}
		}
	}
	return p;
}
int main(){
	cout<<"This is a program to implement bubble sort"<<endl;
	cout<<"Please enter how much data you have"<<endl;
	int num;
	cin>>num;
	float arr[num];
	for(int i=0; i<num; i++){
		cout<<"Data"<<i+1<<": ";
		cin>>arr[i];
	}	
	float *foo;
	foo=arr;
	foo=bubble(foo,num);
	cout<<"Sorted data is as follows"<<endl;
	for(int i=0; i<num; i++){
		cout.width(10);
		cout<<*foo;
		foo++;
	}
	cout<<endl;
	return 0;
}
