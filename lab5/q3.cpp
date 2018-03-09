#include<iostream>
#include<ctime>
#include"sortA.h"
#include"sortll.h"
using namespace std;

int main(){
	cout<<"Enter what type of data structure you want to store data?"<<endl;
	cout<<"1. Array \n 2. Linked list"<<endl;
	int choice=0;
	cin>>choice;
	if(choice==1){
		cout<<"Enter how much big amount of data you want to check?"<<endl;
		int n=0;
		cin>>n;
		int arr[n];
		//random_inputA(arr,n);
		for(int i=0;i<n; i++){
			arr[i]= rand()%1000;
		}
		cout<<"in which method you want to sort your data \n 1.bubble sort \n 2.Quick sort"<<endl;
		cin>>choice;
		clock_t begin= clock();
		if(choice==1){
			bubble(arr,n);
		}
		else quick(arr,0,n-1);
		clock_t end= clock();
		double time=double(end-begin)/CLOCKS_PER_SEC;
		cout<<"Time spend in your desired set-up is: "<<time<<" S"<<endl;
		choice=1;
	}
	else {
	cout<<"Enter how much big amount of data you want to check?"<<endl;
		int n=0;
		cin>>n;
		l_list ll;
		ll.insert(7);
		//random_input(ll,n);
		for(int i=0; i<n; i++){
			ll.insert(rand()%1000);
		}
		ll.show();
		cout<<"in which method you want to sort your data \n 1.bubble sort \n 2.Quick sort"<<endl;
		cin>>choice;
		clock_t begin= clock();
		if(choice==1){
			ll.bsort();
		}
		else {
			ll.qsort();
		}
		ll.show();
		clock_t end= clock();
		double time =double(end-begin)/CLOCKS_PER_SEC;
		cout<<"Time spend in your desired set-up is: "<<time<<" S"<<endl;
	}
	return 0;
}
