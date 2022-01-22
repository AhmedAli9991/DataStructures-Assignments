//Name:Ahmed Ali Reg no:SP19-BCS-096 Section:B
#include <iostream>
using namespace std;
void insert_end();
void display();
void sessional();
struct stu{
	int id;
	stu *next=NULL; // pointer to point next node
};
stu *first=NULL;	//pointer to point first node
stu *last=NULL;		//pointer to point last node

int main() {
	int opt;
	do{
		cout<<"\n\n Enter 1 for insertion  ";
		cout<<"\n Enter 2 to display ";
		cout<<"\n Enter 3 to preform sessional task ";
		cout<<"\n Enter 0 to exit";
		cout<<"\n Enter your option: ";
		cin>>opt;
	switch(opt)
	{
		case 0:
		break;
		case 1: insert_end();
		break;
		case 2: display();
		break;
		case 3: sessional();
		break;
		default:
			cout<<"\n Wrong option";
		}	
	}while(opt!=0);

	return 0;
}
void insert_end()
{	cout<<"\n enter number of nodes ypu want";
	int number;
	cin>>number;
	for(int i=0;i<number;i++){
		cout<<"\n Insert at end method: ";	
		stu *curr;		
		curr=new stu;	
		curr->next=NULL;
		cout<<"\n Enter id:   ";
		cin>>curr->id;
		
		if(first==NULL)
		{
			first=last=curr;
		}	
		else{
			last->next=curr;
			last=curr;
			}		
	}
}
void display()
{
		cout<<"\n Display method: ";	
		if(first==NULL){
			cout<<"\n List is empty";
		}
		else{
		
			stu *p;
			p=first;
			while(p!=NULL)
			{
				cout<<"\n ID is:  "<<p->id;
				p=p->next;
			}
	}	
}
void sessional(){	
	if(first==NULL){
	cout<<"\n List is Empty";
	}
	else{
		stu *fp=first;
		stu *curr=first->next;
		stu *sp=curr->next;
		stu *temp=NULL;
		int sum=0;
		while (curr->next!=NULL){
			sum=fp->id+sp->id;
			if(sum==curr->id){
				fp->next=sp;
				delete curr;
				fp=sp;
				if(sp->next!=NULL){
					curr=sp->next;
					sp=curr->next;
				}
				else{
					curr=sp;
				}
			}
			else{
				fp=fp->next;
				sp=sp->next;
				curr=curr->next;
			}
		}
	}
}

