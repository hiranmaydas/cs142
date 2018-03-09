//Hiranmay Das
//Roll-1711061
#include<iostream>
using namespace std;

int bsearch(int arr[],int lsize, int rsize, int key){
	int mid = (lsize +rsize)/2; //making the middle element 
	if (key <= arr[rsize] && key >= arr[lsize]){ //if the element is inside the boundary made by lsize and rsize
		if(arr[mid] == key){ //if the middle element mathch with key 
			return mid; //returnign the  value of midlle where the element found
		}
		else{
			if(arr[mid] < key){ //if the middle element is less than key 
				bsearch(arr,mid+1,rsize,key); //calling recursive function with the right
				//side of middle element
			}
			else{
				bsearch(arr,lsize,mid-1,key); //calling recursive function with the left 
				//side of middle element
			}
		}
	}
	else{
		return -1; //else return -1 as a symbol of not found 
	}
}

void sort(int arr[], int size){ //function to sort the array
	for(int j=0; j<size; j++){ //running loop size times
		for(int i=0; i<size-j; i++){ //travarsing through all element upto (size-j)th element
			if(arr[i]>arr[i+1]){ //if i th element is greater than i+1 th 
				int temp =arr[i]; //program to swap the data
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
	}
}

int main(){
	cout<<"Number of element in array"<<endl;
	int num;
	cin>>num; //taking input of number of element of array
	int arr[num]; 
	for(int i=0;i<num; i++){ //loop to take input of the array
		cout<<"data"<<i+1<<": ";
		cin>>arr[i];
	}
	sort(arr,num); //sorting the array
	for(int i=0; i<num; i++){ //loop to show the sorted array
		cout<<" ["<<arr[i]<<"]";
	}
	cout<<endl;
	cout<<"Enter the element to be searched"<<endl;
	int key;
	cin>>key; //taking the key element as input 
	bsearch(arr,0,num,key); //calling bsearch function with array ,lsize , rsize and key 
	return 0;
}
