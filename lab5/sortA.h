#include<iostream>
using namespace std;

void swap(int* a,  int * b){ //function to swap two element. pointer is used to swap permanently
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[], int low, int high){
	int pivot =arr[high]; //making the pivot as the last element of the partion
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

void quick(int arr[], int low, int high){
	if(low<high){ //if the partion contains atleast two element
		int pi =partition(arr,low,high);//take the position of the pivot value
		quick(arr,low, pi-1); //calling the quick function recursively to sort the left part of a partion and make further partion through preceding statement until only one element left  
		quick(arr,pi+1, high); //sorting the right part of the partion
	}
}
int* bubble(int p[],int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size-i-1;j++){
			if(p[j]>p[j+1]){
				int  a =p[j];
				p[j]=p[j+1];
				p[j+1]=a;
			}
		}
	}
	return p;
}
