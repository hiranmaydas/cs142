#include<iostream>
using namespace std;

void bsearch(int arr[],int lsize, int rsize, int key){
	// Make a variable.
	int mid = (lsize +rsize)/2;
	// float mid;
	if (key <= arr[rsize] && key >= arr[lsize]){
		if(arr[mid] == key){
			cout << " Found at " << mid<<endl;
		}
		else{
			if(arr[mid] < key){
				bsearch(arr,mid+1,rsize,key);
			}
			else{
				bsearch(arr,lsize,mid-1,key);
			}
		}
	}
	else{
		cout << "Not found";
	}
}
void sort(int arr[],int size){
	for(	int i=0; i<size;i++){
		for(int j=0; j<i;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
}

int main(){
	cout<<"Enter the number of elements you want to keep in your array"<<endl;
	int num;
	cin>>num;
	int arr[num];
	for(int i=0; i<num;i++){
		cin>>arr[i];
	}
	for(int i=0; i<num; i++){
		cout<<"Data"<<i+1<<": "<<arr[i]<<endl;
	}
	sort(arr,num);
	int key;
	cout<<"enter the key"<<endl;
	cin>>key;
	// Function call for b...
	bsearch(arr,0,num-1,key);
	return 0;
}
