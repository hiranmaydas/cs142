#include<iostream>
using namespace std;
class mx_hp{
public:
	int arr[100];
	int length;
	mx_hp(){
		for(int i=0; i<100; i++){
			arr[i]=0;
		}
		length=0;
	}
	void insert(int );
	void remove();
	void show();
};

int main(){
	mx_hp heap;
	cout<<"Enter 10 values"<<endl;
	for(int i=0;i<10;i++){
		int data;
		cin>>data;
		heap.insert(data);
	}
	heap.show();
	heap.remove();
	heap.show();
	return 0;
}

void mx_hp::insert(int key){
	arr[length]=key;
	int i=length;
	while(i>0){
		if(arr[i]>arr[(i-1)/2]){
			int j=arr[i];
			arr[i]=arr[(i-1)/2];
			arr[(i-1)/2]=j;
		}
		i=(i-1)/2;
	}
	length++;
}
void mx_hp::show(){
	cout<<"---------------------------------------------------------------------------\n";
	for(int i= 0; i<length; i++){
		cout<<", "<<arr[i];
	}
	cout<<endl;
	cout<<"---------------------------------------------------------------------------\n";

}
void mx_hp::remove(){
	arr[0]=arr[length-1];
	arr[length]=0;
	if(length!=0){
		length--;
	}
	int i=0;
	while(i<length){
		int fix=0;
		if(arr[i]<arr[2*i+1] || arr[i]<arr[2*i+2]){
			int j=arr[i];
			if(arr[2*i+1]>arr[2*i+2]){
				arr[i]=arr[2*i+1];
				arr[2*i+1]=j;
			}
			else {
				arr[i]=arr[2*i+2];
				arr[2*i+2]=j;
				fix=1;
			}
		}

		if(fix==1){
			i=2*i+2;
		}
		else i=2*i+1;
	}
}
