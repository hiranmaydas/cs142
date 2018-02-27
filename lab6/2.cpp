//Hiranmay Das
//R0ll -1711061
#include<iostream>
#include"link.h" //including link.h file containing class for linklist
using namespace std;

int bsearch( node* lnode, node* rnode, int key,int lindex, int rindex){
	if(lindex!=rindex){ 
		int middle=(lindex+rindex)/2; //assigning middle element 
		node* temp=lnode; //assigning temp as lnode
		for(int i=0;i<(rindex-lindex)/2;i++){ //(rindex-lindex)/2 gives the number of loop to go to the middle node
			temp=temp->next; //travarsing through node
		}
		if(key<temp->data){  //if the middle element is bigger than key 
			bsearch(lnode, temp, key,lindex,middle); //call revursive function for left part of middle
		}
		else if(key>temp->data){ //if the middle element is bigger than key 
			bsearch(temp,rnode,key,middle,rindex); //call revursive function for right  part of middle

		}
		else return middle+1; //if the middle element is equal to the key then returning the index of middle
	}
	else return -1; //else returning -1 as a sign of not found
}

int main(){
	cout<<"This is to implement binary search through link list"<<endl;
	cout<<"number of  the data of linked list"<<endl;
	l_list ll; 
	int num=0;
	cin>>num;
	for(int i=0; i<num; i++){ //loop to take input 
		int data;
		cout<<"Data"<<i+1<<": ";
		cin>>data;
		ll.insert(data);
	}
	ll.sort(); //sorting the linked list
	cout<<"Sorted linklist"<<endl; 
	ll.show(); //showing sorted linklist
	cout<<"Enter the element to be searched"<<endl;
	int key=0;
	cin>>key; //taking the key 
	cout<<"Found at"<<bsearch(ll.head, ll.tail,key,0,num)<<endl; ///calling binary search function with head, tail of the link list, key , right index and left index
	return 0;
}
