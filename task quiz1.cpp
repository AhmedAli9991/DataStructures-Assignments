//Ahmed ALi(SP19-BCS-096) section:B
#include <iostream>
using namespace std;
void create_list();
void deleted();
void display();
struct stu{
	int number;
	stu *next=NULL; 
};
stu *first=NULL;
stu *last=NULL;
int main()  
{
	    int choice;
	do
    {

        cout<<"\n 1 - intialize the linked list(must be done before other functions).";
        cout<<"\n 2 - delete.";
        cout<<"\n 3 - display.";
        cout<<"\n 0 - Exit.";
        cout<<"\n Enter your choice: ";
        cin>>choice;
	
        switch(choice){
            case 0:
				break;
			case 1:
				create_list();
				break;
			case 2:
				deleted();
				break;
			case 3:
				display();
				break;
		
		}	
	}while(choice!=0);

	return 0;  	
}
void create_list(){
	cout<<"\n Enter number of nodes you want: ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		stu *curr;		
		curr=new stu;	
		curr->next=NULL;
		cout<<"\n Enter number: ";
		cin>>curr->number;
		if(first==NULL){
			first=last=curr;
		}	
		else{
			last->next=curr;
			last=curr;
		}
	}
	display();
}
void display(){
	cout<<"\n";
	if(first==NULL){
		cout<<"\n List is empty";
	}
	else{
		stu *p;
		p=first;
		while(p!=NULL){
			cout<<p->number<<" ";
			p=p->next;
		}
	}	
}
void deleted(){
	if(first->next==last||first==last){
		cout<<"\n no third node";
	}
	else{
		stu *p=first;
		stu *q=p->next;
		int check;
		while(q->next!=NULL){
			check=p->number+q->number;
			stu *d=q->next;
			if(d->number>check){			
				q->next=d->next;
				cout<<"\n deleted"<<d->number;
				delete d;
			}
			if(q->next!=NULL){
				p=p->next;
				q=q->next;
			}
		}
	}
	display();
}
