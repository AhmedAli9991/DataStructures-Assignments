#include <iostream>
using namespace std;
void search(int x);
void print_reverse();
void insert_end();
void display();
void reverse_linkList();
void palindrome();
void swap_values();
void swap_location();
struct stu
{
	stu *next;
	int id;
};
stu *first = NULL;
stu *last = NULL;
int main()
{
	int opt;
	do
	{
	
    cout<<"\nEnter 1 to insert at end in linked list: ";
    cout<<"\nEnter 2 to print link list in reverse order: ";
    cout<<"\nEnter 3 to arrange the linked list in reverse order: ";
    cout<<"\nEnter 4 to check if the linked list is a palindrome: ";
    cout<<"\nEnter 5 to swap values of any two given nodes";
    cout<<"\nEnter 6 to swap locations of any two given nodes";
    cout<<"\nEnter 7 to Display the linked list: ";
    cout<<"\nEnter 0 to exit: ";
    cin>>opt;
    switch(opt)
    {
    	case 1: insert_end();
    	break;
    	case 2: print_reverse();
    	break;
    	case 3: reverse_linkList();
    	break;
    	case 4: palindrome();
    	break;
    	case 5: swap_values();
    	break;
    	case 6: swap_location();
    	break;
    	case 7: display();
    	break;
    	default: 
    	cout<<"Wrong Input";
	}
}while(opt!=0);
	return 1;
}
void reverse_linkList()
{
	if(first == NULL)
	{
		cout<<"\nThe linked List is empty";
	}
	else
	{
		stu *curr = new stu;
		stu *p = new stu;
		stu *p1 = new stu;
		p1 = NULL;
		curr = first;
		while(curr!=NULL)
		{
			p = curr->next;
			curr->next = p1;
			p1 = curr;
			curr = p;
		}
		stu *k = new stu;
		k = first;
		first = last;
		last = k;
		
	}
}
void print_reverse()
{
	if(first == NULL)
	{
		cout<<"Linked List is empty";
	}
	else
	{
			stu *p;
	p = new stu;
	stu *k = new stu;
	k = NULL;
	stu *m = new stu;
	m = last;
	while(m!= first)
	{
		p = first;
		while(p!=m)
		{
			k = p;
			p = p->next;
			
		}
		cout<<p->id;
		m=k;
	}
	cout<<first->id;
	}

}
void palindrome()
{

	if(first == NULL)
	{
		cout<<"\nThe linked list is empty.";
	}
	else
	{
		stu *second_start = new stu;
		second_start = NULL;
		stu *p = new stu;
		p = first;
		stu *q = new stu;
		q = first;
		
		while(true)
		{
			if(p->next==NULL)
		{
			cout<<"\nOnly one element in the linked list,which is a palindrome.";
			break;
		}
			p = p->next->next;
			if(p->next==NULL)
			{
				stu *i = new stu;
				i = NULL;
				second_start = q->next->next;
				stu *curr = new stu;
				while(curr!=NULL)
				{
					curr = second_start->next;
					second_start->next = i;
					i = second_start;
					second_start = curr;
				}
				stu *temp = new stu;
				temp = second_start;
				second_start = p;
				p = temp;
				cout<<"\nHI2";
				break;
			}
			if(p==NULL)
			{
				stu *i = new stu;
				i = NULL;
				second_start = q->next;
				stu *curr = new stu;
				while(curr!=NULL)
				{
					curr = second_start->next;
					second_start->next = i;
					i = second_start;
					second_start = curr;
				}
				stu *temp = new stu;
				temp = second_start;
				second_start = p;
				p = temp;
				cout<<"\nHI3";
				break;
			}
			q = q->next;
			cout<<"\nHI4";
			
		}
		q->next = NULL;
		stu *p2;
		p2 = first;
		while(p2->next!=NULL && p->next != NULL)
		{ 
			if(p2==p)
			{
				continue;
			}
			else
			{
				cout<<"\nThe given linked list is not a palindrome.";
				break;
			}
			p2 = p2->next;
			p = p->next;
		}
		if(p2 == p)
		{
			cout<<"\nThe given linked list is a palindrome.";
		}
		
	}
}
void swap_values()
{
	if(first == NULL)
	{
		cout<<"\nThe linked list is empty.";
	}
	else
	{
		int first_val,second_val;
		cout<<"\nEnter the first value you want to swap";
		cin>>first_val;
		cout<<"\nEnter the second value you want to swap";
		cin>>second_val;
		stu *p = new stu;
		p = first;
		stu *q = new stu;
		q = first;
		while(p!=NULL)
		{
			if(p->id==first_val)
			{
				break;
			}
			p=p->next;
		}
		if( p->id!= first_val)
		{
			cout<<"Wrong input, id does not exist";
		}
		while(q!=NULL)
		{
		
			if(q->id==second_val)
			{
			
				break;
			}
		
			q = q->next;
		}
		if(q->id!= second_val)
		{
		
		cout<<"Wrong input, id does not exist";
		}
		p->id = second_val;
		q->id = first_val;
	}
}
void search(int x,int y, stu *first)
{
	stu *p = first;
	stu *prev = NULL;
	while(p!=NULL && p->id!=x)
	{
		prev = p;
		p = p->next;
}
	stu *pX = p;
	stu *prevX = prev;
	p = first;
	prev = NULL;
	while(p!= NULL && p->id!=y)
	{
		prev = p;
		p = p->next;
	}
	stu *pY = p;
	stu *prevY = prev;
	}

void insert_end()
{
	stu *curr;
		curr = new stu;
		curr->next = NULL;
		cout<<"\n Enter ID: ";
		cin>>curr->id;
	if(first==NULL)
	{
		cout<<"\n Before this insertion, the list is empty";
		first = last = curr;
		cout<<"\n After insertion first points: "<<first->id;
		cout<<"\n After insertion last points: "<<last->id;
		
	}
	else
	{
		cout<<"\n First pointer points to: "<<first->id;
		cout<<"\n Last pointer points to: "<<last->id;
		last->next = curr;
		last = curr;
		cout<<"\n After insertion: ";
		cout<<"\n First pointer points to: "<<first->id;
		cout<<"\n Last pointer points to: "<<last->id;
	}	
}
void display()
{
	cout<<"\n Display method: ";
	stu *p;
	p = first;
	while(p!=NULL)
	{
		cout<<"\n ID is: "<<p->id;
		
		p = p->next;
	}
}
void swap_location()
{
	int first_val,second_val;
	stu *temp;
	if(first == NULL)
	{
		cout<<"\nLinked list is empty";
	}
	else
	{
		cout<<"\nEnter the id of the first node you want to swap. ";
		cin>>first_val;
		cout<<"\nEnter the id of the second node you want to swap. ";
		cin>>second_val;
		stu *p = first;
	stu *prev = NULL;
	while(p!=NULL && p->id!=first_val)
	{
		prev = p;
		p = p->next;
}
	stu *pF = p;
	stu *prevF = prev;
	p = first;
	prev = NULL;
	while(p!= NULL && p->id!=second_val)
	{
		prev = p;
		p = p->next;
	}
	stu *pS = p;
	stu *prevS = prev;
		if( first_val == first->id ||  second_val == first->id)
		{
			temp = pS->next;
			pS->next = pF->next;
			pF->next = temp;
			if(prevF==NULL)
			{
				first = pS;
				prevS ->next = pF;
			}
			if(prevS == NULL)
			{
				first = pF;
				prevF->next = pS;
			}
		}/*
		else if(first_val == last->id || second_val == last->id)
		{
			temp = pS->next;
			pS->next = pF->next;
			pF->next = temp;
			if(prevS->next->next = NULL)
			{
				last = pF;
				prevS ->next = pF;
				prevF->next = pS;
			}
			if(prevF->next->next = NULL)
			{
				last = pS;
				prevF->next = pS;
				prevS->next = pF;
			}
		}*/
		else if(pF->next == pS || pS->next == pF)
		{
			cout<<"\nHI";
			if(pS->next==pF&&pS==first)
			{
			cout<<"\nHI";
				pS->next=pF->next;
				pF->next=pS;
				first=pF;	
			
				cout<<"\nHI";
			}
			else if(pF->next==pS&&pF==first)
			{
				cout<<"\nHI";
				pF->next=pS->next;
				pS->next=pF;
				first=pS;	
				cout<<"\nHI2";
			}
			else if (pF->next == NULL && prevF == pS)
			{
				pF->next = pS;
				pS->next = NULL;
				prevS = pF;
				last = pS;
			}
			else if (pS->next == NULL && prevS == pF)
			{
				pS->next = pF;
				pF->next = NULL;
				prevF = pS;
				last = pF;
			}
			if(pF->next == pS && prevS == pF )
			{
				prevF->next=pS;
				pF->next=pS->next;
				pS->next=pF;
			}
			else if(pS->next == pF && prevF == pS)
			{
				prevS->next=pF;
				pS->next=pF->next;
				pF->next=pS;
				}
		}
		
		else if(first_val!= first->id || first_val != last->id || second_val!= first->id || second_val != last->id)
		{
			temp = pS->next;
			pS->next = pF->next;
			pF->next = temp;
			prevF->next = pS;
			prevS->next = pF;
			
		}
	}			last=first;
				while(last->next!=NULL){
					last=last->next;
		}
}

