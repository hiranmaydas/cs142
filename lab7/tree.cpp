#include<iostream>
using namespace std;

class node{ 
	public:
	int data;
	node *parent,*left,*right;
	node(){
		parent=left=right=NULL;
	}
};

class btree{
	node *root;
	public:
	btree(){
		root=NULL;
	}
	void insert(int );
	void show();
	void show_A(node* temp);
	void del(int );
 	int search(int );
};

int main(){
	btree t;
	t.insert(7);
	t.insert(9);
	t.insert(5);
	t.insert(6);
	t.show();
/*	cout<<"this is a program to grow tree and then maintain it"<<endl;
	cout<<"We will provide necessary nutrients to it , but you have to command to grow it."<<endl;
	cout<<"buying seed..\nDone."<<endl;
	btree t;
	cout<<"this tree need values to make it branches and leaves, Please provide values when asked"<<endl;
	cout<<"\n\n\n How much values  you want to enter?"<<endl;
	int num=0;
	cin>>num;
	for(int i =0; i<num;i++){
		cout<<"Data"<<i+1<<": ";
		int d;
		cin>>d;
		t.insert(d);
	}
	cout<<"tree is grown, check it by pressing any key"<<endl;
	t.show();*/
	return 0;
}
void btree::insert(int d){
	node* t=new node;
	t->data=d;
	if(root==NULL){
		root=t;
		cout<<"if two times";
	}
	else {
		cout<<"else";
		node *temp;
		cout<<"dec";
		temp->parent=root;
		cout<<"before loop";
		while(temp!=NULL){
			cout<<"loop_insert";
			if(d> temp->data){
				if(temp->right==NULL){
					t->parent=temp;
				}
				temp=temp->right;
			}
			else if(d<temp->data){
				t->parent=temp;
				temp->parent=(temp->parent)->left;
			}
			else cout<<"This value is already present"<<endl;
		}
	}
}
void  btree::show_A(node* temp){
	if (root==NULL){
		cout<<"Tree has not grown from seed"<<endl;
	}
	else{
		if(temp->left!=NULL){
			temp=temp->left;
			show_A(temp);
		}
		cout<<temp->data<<",";
		if(temp->right!=NULL){
			temp=temp->right;
			cout<<","<<temp->data;
			show_A(temp);
		}
	}
}
void btree::show(){
	show_A(root);
}
