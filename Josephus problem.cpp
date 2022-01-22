#include <iostream>
using namespace std;
void create_List(int num);
void display();
struct stu{
	int id;
	stu *next=NULL; 
};
stu *first=NULL;	
int main() {
	int n;
	cout<<"\n Enter number of Players: ";
	cin>>n;
	create_List(n);
	stu *p;
	p=first;
	int node;
	do{
	cout<<"\nEnter starting point of the game: ";
	cin>>node;
	}while(node>n||node<=0);
	for(int i=1;i<node;i++){
		p=p->next;
		}
	stu *del=NULL;
	while(p->next!=p)
	{
		cout<<"\n Remaing Left";
		display();
		if(p->next==first){
			first=(p->next)->next;
		}
		del=p->next;
		p->next=(p->next)->next;
		p=p->next;
		cout<<"\n "<<del->id<<" has been eleminated";
		delete del;		
	}
	cout<<"\n The winner is: ";
	display();
	return 0;
}
void create_List(int num){
	stu *point=NULL;
	for(int i=1;i<=num;i++){
		stu *curr;	
		curr=new stu;	
		curr->id=i;
		if(first==NULL){
			first=curr;
			curr->next=first;
		}
		else{
			point->next=curr;
			curr->next=first;	
		}
		point=curr;	
	}	
}
void display(){
	stu *p;
	p=first;
	do{
		cout<<"\n ID is:  "<<p->id;
		p=p->next;
	}while(p!=first);
}
