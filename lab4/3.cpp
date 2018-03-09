#include <iostream>
#include <string.h>
#pragma GCC diagnostic ignored "-Wwrite-strings" //to fix an errro
using namespace std;

int top, front; //global variable to track the top and front 


class Issue //Issue class consisting of  name, phone number description of the issue ,and
//Issue type pointer which contains the address of the next element
//this is simmilar to the node class of the linked list
{
 public:
 char name[30];
 long int ph;
 char desc[100];
 Issue* link;
 Issue(){link=NULL;};
};

class StkPal
{
 public:
 char NM[30];
 /* push a character into stack */
 void push(char a)
 {
 top++;
 NM[top] = a;
 }
/* delete an element in stack */
 void pop()
 {
 top--;
 }
}stack;
 
class CustomerService //customer service class simmilar as the linked list class contains 
//the head,tail pointer, a constructor, and lot more
{
 public:
 Issue* head;
 Issue* tail;
 CustomerService()
 {
 head=NULL;
 tail=NULL;
 }
 int chkPalindrome(char nm[30]); //function to check palindrome
 void addIssue(char nm[30], long int p, char desc[]); //function to add issue
 void displayIssue(); //function to display issue
};

/*Checking Palindrome Using Array STACK*/
int CustomerService::chkPalindrome(char nm[30])
{
 top=-1; 
 front=0;
 char b;
 for (int i = 0;nm[i] != '\0';i++) //untill all the letter of name is checked
 {
 b = nm[i];
 stack.push(b);
 }
 for (int i = 0;i < (signed)(strlen(nm) / 2);i++)
 {
 if (stack.NM[top] == stack.NM[front])
 {
 stack.pop();
 front++;
 }
 else
 {
 return 0;
 }
 }
 int x=front;
 front = 0;
 top = -1;
 if ((signed)(strlen(nm) / 2)==x)
 { return 1;}
 return -1;
}


void CustomerService::addIssue(char nm[],long int p, char des[]) //function to add Issue
{
 Issue* temp=new Issue; //creating an object named temp
 temp->ph=p;
 strcpy(temp->name,nm); //putting all the data 
 strcpy(temp->desc,des);
 if(head==NULL) //if there is no element in the customer service list
 {
 head=temp;
 tail=temp;
 return;
 
 }
 if(chkPalindrome(nm)==1) //if the name is palindrome then adding it to the top of the list
 {
 temp->link=head;
 head=temp;
 
 }
 else //else adding it to the last of the list
 {
 tail->link=temp;
 tail=temp;
 
 }
};
 
 

void CustomerService::displayIssue() //function to display all the issue
{
 Issue* iss; 
 iss=head;
 if(iss==NULL)// if head is null or the list is empty
 {
 cout<<"There is no registration done"<<endl;
 }
 else
 {
 cout<<"\nNAME \t \t PHONE \t \t\t Description \n"; //showing the details of the issue
 while(iss!=NULL) //untill the last element is reached 
 {
 cout<<"\n"<<iss->name<<" \t \t "<<iss->ph<<" \t \t "<<iss->desc; //showing the details 
 iss=iss->link; //going to next issue
 }
 }
 cout<<"\n \n \n"; //just to design
}

int main()
{
 CustomerService CS; //declaring a customerservice type variable CS
 CS.displayIssue(); //displaying the list
 CS.addIssue("Sgh",9876543289,"something  is wrong"); //followings are just direct entry of
 //details of issues
 CS.displayIssue();
 CS.addIssue("ISSI",9905432893,"Code Testing");
 CS.displayIssue();
 CS.addIssue("ISS",9876847584,"PALINDROME STACK");
 CS.displayIssue();
 CS.addIssue("PRBLM",9876543289,"STACK PALINDROME");
 CS.displayIssue();
 CS.addIssue("PRORP",9876003289,"CODE SUCCESFUL");
 CS.displayIssue();
 CS.addIssue("PROB",7319103289,"SUCCESSFUL CODE");
 CS.displayIssue();
 CS.addIssue("TICKET",8093103289,"PDSL 2");
 CS.displayIssue();
 CS.addIssue("TICIT",9099803289,"2 PDSL");
 CS.displayIssue();
 CS.addIssue("TIIT",9009876546,"LAST ONE");
 CS.displayIssue();
 CS.addIssue("ENDNE",7890678987,"ONE LAST");
 CS.displayIssue(); //displaying the issue list
 return 0; 
}



