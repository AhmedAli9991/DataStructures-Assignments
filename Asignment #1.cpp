#include <iostream>
using namespace std;
void insert_end();
void display();
void reverse_display();
void reverse();
void palindrom();
void swapvalue();
void swaplocation();
struct stu{
	int id;
	stu *next=NULL; // pointer to point next node
};
stu *first=NULL;	//pointer to point first node
stu *last=NULL;		//pointer to point last node

int main() {
	int opt;
	do{
		cout<<"\n";
		cout<<"\n\n Enter 1 for insertion  ";
		cout<<"\n Enter 2 to display ";
		cout<<"\n Enter 3 to display in reverse ";
		cout<<"\n Enter 4 to reverse ";
		cout<<"\n Enter 5 to check if palindrom ";
		cout<<"\n Enter 6 to swap value ";
		cout<<"\n Enter 7 to swap location ";
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
		case 3: reverse_display();
		break;
		case 4: reverse();
		break;
		case 5: palindrom();
		break;
		case 6: swapvalue();
		break;
		case 7: swaplocation();
		break;
		default:
			cout<<"\n Wrong option";
		}	
	}while(opt!=0);

	return 0;
}

void insert_end()
{
	cout<<"\n Insert at end method: ";	
	
		stu *curr;		//pointer of stu type
		curr=new stu;		//allocate new memory of stu type and curr point that location
		curr->next=NULL;	//curr of next is null so that it may not point any garbage
		
		cout<<"\n Enter id:   ";
		cin>>curr->id;
		
	if(first==NULL)
	{
		cout<<"\n Before this insertion the list is empty";
		first=last=curr;
		cout<<"\n After insertion first points: "<<first->id;
			cout<<"\n After insertion last points: "<<last->id;		
	}	
	else{
		cout<<"\n First pointer points to:  "<<first->id;
		cout<<"\n Last pointer points to:  "<<last->id;
		last->next=curr;
		last=curr;
		cout<<"\n After insertion:";
		cout<<"\n First pointer points to:  "<<first->id;
		cout<<"\n Last pointer points to:  "<<last->id;
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


void reverse_display()
{
		cout<<"\n Reverse Display method: ";	
		if(first==NULL){
			cout<<"\n List is empty";
		}
		else{
			stu *point;
			point=last;
			stu *p;
			p=first;
			while(p!=point){
				while(p->next!=point)
				{
					p=p->next;	
				}	
				cout<<"\n ID is: "<<point->id;
				point=p;
				p=first;	
			}
			cout<<"\n ID is: "<<first->id;
		}
}
void reverse(){
	cout<<"\n Reverse method: ";	
	stu *p;
	p=NULL;
	stu *curr;
	stu *nxt;
	curr=first;
	nxt=NULL;
	while(curr!=NULL){
		nxt=curr->next;
		curr->next=p;
		p=curr;
		curr=nxt;
	}
	stu *temp=last;
	last=first;
	first=temp;
	cout<<"\n list has been reversed";
}
void palindrom(){
	cout<<"\n Checking Palindrom meathod";
	if(first==NULL){
		cout<<"\n List is Empty";
	}
	else{
		stu *fp=first;
		stu *lp=last;
		stu *p=NULL;
		int check=0;
		if(fp->id!=lp->id){
				check=1;
			}
		while (fp!=lp&&fp->next!=lp){
			if(fp->id!=lp->id){
				check=1;
			}
			p=fp;
			fp=fp->next;
			while(p->next!=lp){
				p=p->next;	
			}
			lp=p;
		}
		if(check==0){
			cout<<"\n It is palindrom";
		}
		else{
			cout<<"\n It is not palindrom";
		}
	}
}
void swapvalue(){
	if(first==last)	{
		cout<<"\n Swap not possible";
	}
	else{
		cout<<"\n Enter the node whose value you wish to swap: ";
		int val1;
		cin>>val1;
		cout<<"\n Enter the other node whose value you wish to swap: ";
		int val2;
		cin>>val2;
		if(val1==val2){
			cout<<"\n same node";
		}
		else{
			int node=1;
			stu *n1=first;
			stu *n2=first;
			while(node<val1){
				n1=n1->next;	
				node++;
			}	
			node=1;
			while(node<val2){
				n2=n2->next;	
				node++;
			}
			int temp=n1->id;
			n1->id=n2->id;
			n2->id=temp;
			cout<<"\n values swaped";
		}
	
	}
}
void swaplocation(){
	cout<<"\n Swap location meathod";
	if(first==last)	{
		cout<<"\n Swap not possible";
	}
	else{
		cout<<"\n Enter the node whose location you wish to swap: ";
		int val1;
		cin>>val1;
		cout<<"\n Enter the other node whose location you wish to swap: ";
		int val2;
		cin>>val2;
		if(val1==val2){
			cout<<"\n same node";
		}
		else{
			int node=1;
			stu *n1=first;
			stu *pr1=NULL;
			stu *n2=first;
			stu *pr2=NULL;
			while(node<val1){
				pr1=n1;
				n1=n1->next;
				node++;
			}
			node=1;
			while(node<val2){
				pr2=n2;
				n2=n2->next;
				node++;		
			}
			if (n1==first){
				if(val2-val1==1){
					n1->next=n2->next;
					n2->next=n1;
					first=n2;	
				}
				else{				
					stu *temp=n1->next;
					pr2->next=n1;
					n1->next=n2->next;
					n2->next=temp;
					first=n2;	
				}
			}
			else if (n2==first){		
				if(val1-val2==1){
					n2->next=n1->next;
					n1->next=n2;
					first=n1;	
				}
				else{
					stu *temp=n1->next;
					pr1->next=n2;
					n1->next=n2->next;
					n2->next=temp;
					first=n1;
				}
			}
			else{
				if(val2-val1==1){
					pr1->next=n2;
					n1->next=n2->next;
					n2->next=n1;
				}	
				else if(val1-val2==1){
					pr2->next=n1;
					n2->next=n1->next;
					n1->next=n2;
				}
				else{
					stu *temp=n1->next;
					pr1->next=n2;
					pr2->next=n1;
					n1->next=n2->next;
					n2->next=temp;
				}
			}
				cout<<"\n locations swaped";
				last=first;
				while(last->next!=NULL){
					last=last->next;
				}
		}
	
	}
}
