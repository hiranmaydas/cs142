#include<iostream>
using namespace std;

void marge(int arr[],int low, int high){
	int mid=(low+high)/2;
	int a[high-low]; //define another array to store the sorted data
	cout<<"a definition is ok"<<endl;
	int j=mid+1,x=0;
	int i=low;
	for(i=low;i<=mid && j<=high;i++){
		if(arr[i]<=arr[j]){
			a[x]=arr[i];
			x++;
			i++;
		}
		else{
			a[x]=arr[j];
			x++; 
			j++;
		}
	}
	cout<<"for loop is ok";
	while(i<=mid){
		a[x]=arr[i];
		i++;
		x++;
	}
	while(j<=high){
		a[x]=arr[j];
		x++;
		j++;
	}
	cout<<"two while loops are also ok"<<endl;
	
	x=0;
	for(int i=low; i<=high-1; i++){
		arr[i]=a[x];
		x++;
		cout<<"loop is running"<<endl;
	}
}


void sort(int arr[],int low, int high){
	int mid=(low+high)/2;
	if(low!=high){
		sort(arr,low,mid);
	}
	cout<<"first part of sort is ok";
	marge(arr,low,high);
	cout<<"merge is ok";
	sort(arr,mid+1,high);
	cout<<"last part of sort is ok";
}
int main(){
	int arr[6];
	for(int i=0;i<6; i++){
		cin>>arr[i];
	}
	cout<<"foo";
	sort(arr,0,6);
	cout<<"Sorted"<<endl;
	for(int i=0; i<6; i++){
		cout<<arr[i]<<",";
	}
	return 0; 
}
		
		
