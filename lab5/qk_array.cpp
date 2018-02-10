#include<iostream>
using namespace std;
void swap(double*,double*);
int  partition(double, int , int);
void quick(double arr[],int , int );
void show(double arr[],int);
int main(){ //main function
	cout<<"This is the program to implement quick sort by array"<<endl;
	int num;
	cin>>num;
	double arr[num];
	for(int i=0; i<num;i++){
		cout<<"Data"<<i+1<<":";
		cin>>arr[i];
	}
	cout<<"Do you want to short those data"<<endl;
	char choice;
	cin>>choice;
	if(choice=='y'|| choice=='Y'){
		cout<<"Sorting.."<<endl;
		quick(arr,0,num-1);
		show(arr,num);
	}
	else cout<<"Thank you"<<endl;
	return 0;
}
	

void swap(double* a, double* b){ //function to swap two element. pointer is used to swap permanently
	double t=*a;
	*a=*b;
	*b=t;
}
int partition(double arr[], int low, int high){
	double pivot =arr[high]; //making the pivot as the last element of the partion
	int i=low-1; //assigning selecting the first element of the partion 
	for(int j=low; j<=high-1;j++){ //untill all the elements are checked in the partition
		if(arr[j]<=pivot){ //if the jth element is greater than the pivot
			i++; //incrementing the i to i+1 in first step it 
			swap(&arr[i], &arr[j]);// swaping the jth element with the i-1 th element such that if the value is less than the pivot it remains on the left side.
		}
	}
	swap(&arr[i+1],&arr[high]); //altast swaping the pivot and ith element to place the pivot at the boundary of lower and upper value of pivot 
	return (i+1); //returning the position of the pivot on which partion is done.
}

void quick(double arr[], int low, int high){
	if(low<high){ //if the partion contains atleast two element
		int pi =partition(arr,low,high);//take the position of the pivot value
		quick(arr,low, pi-1); //calling the quick function recursively to sort the left part of a partion and make further partion through preceding statement until only one element left  
		quick(arr,pi+1, high); //sorting the right part of the partion
	}
}
void show(double arr[],int num){ //a simple function to print the array
	for(int i=0; i<num;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
