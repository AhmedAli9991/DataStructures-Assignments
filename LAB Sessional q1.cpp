//Name:Ahmed Ali Reg no:SP19-BCS-096 Section:B
#include <iostream>
using namespace std;
void insert_end();
void display();
void sessional();
struct stu{
	int id;
	stu*previous=NULL;
	stu *next=NULL;
};
stu *first_student=NULL;	
stu *last_student=NULL;
stu *pre=NULL;
int main()
{
	int opt;
	do
	{
	
    cout<<"\nEnter 1 to insert at end in linked list: ";
    cout<<"\nEnter 2 to print link list: ";
    cout<<"\nEnter 3 to perform sessional Q1: ";
	cout<<"\nEnter 0 to exit: ";
    cin>>opt;
    switch(opt)
    {	case 0: cout<<"Exit";
    	break;
    	case 1: insert_end();
    	break;
    	case 2: display();
    	break;
    	case 3: sessional();
    	break;
		default: 
    	cout<<"Wrong Input";
	}
}while(opt!=0);
	return 1;
}
void insert_end(){
		cout<<"\n enter number of nodes ypu want";
		int number;
		cin>>number;
		for(int i=0;i<number;i++){
			cout<<"\n Insert student method: ";	
			stu *curr;		
			curr=new stu;	
			curr->next=NULL;	
			cout<<"\n Enter id: ";
			cin>>curr->id;
			
		if(first_student==NULL)
		{
			first_student=last_student=curr;
		}	
		else{
			stu *p=first_student;
			last_student->next=curr;
			last_student=curr;
			curr->previous=pre;
			
    	}		
		pre=curr;
	}
}
void sessional(){
	if(first_student==NULL){
	
	cout<<"\n List is Empty";
	}
	stu *fp=first_student;
	stu *lp=last_student;
	int sum=0;
	while (fp!=lp&&fp->next!=lp){
		sum = fp->id+lp->id;
		if(sum>7){
			stu *curr;
			curr=new stu;
			curr->id=sum;
			curr->next=fp->next;
			fp->next->previous=curr;
			fp->next=curr;
			curr->previous=fp;
			fp=curr->next;
			lp=lp->previous;
		}
		else{
			fp=fp->next;
			lp=lp->previous;
		}
	
	}

}
void display()
{
		cout<<"\n Display method: ";	
		if(first_student==NULL){
			cout<<"\n List is empty";
		}
		else{
		
			stu *p;
			p=first_student;
			while(p!=NULL)
			{
				cout<<"\n ID is:  "<<p->id;
				p=p->next;
			}
	}	
}

