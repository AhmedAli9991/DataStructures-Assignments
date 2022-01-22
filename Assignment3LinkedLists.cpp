//Ahmed Ali SP19-BCS-096 section:B
#include <iostream>
using namespace std;
void create_list();
void selectionSort();
void bubbleSort();
void insertionSort();
void display();
void linear_search();
struct stu{
	int number;
	stu *next=NULL; 
};
void SelectionReccursion(stu *p); 
void sel(stu *j);
void bubbleRecursive(stu *p);
void bub(stu *j); 
void insertionRecursive(stu *p);
void ins(stu *k,int key,int check);
void inb(stu *d,stu *k);
void linear_recursive(int s,stu *p);
stu *first=NULL;
stu *last=NULL;
int main()  
{  	
    int choice;
	do
    {

        cout<<"\n 1 - intialize the linked list(must be done before other functions).";
        cout<<"\n 2 - selection sort with iterations.";
        cout<<"\n 3 - selection sort with recurrsion.";
        cout<<"\n 4 - bubble sort with iterations.";
        cout<<"\n 5 - bubble sort with recurrsion."; 
        cout<<"\n 6 - insertion sort with iterations.";
        cout<<"\n 7 - insertion sort with recurrsion.";
        cout<<"\n 8 - linear seach with iterations.";
        cout<<"\n 9 - linear seach with recurrsion."; 
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
				selectionSort();
				break;
			case 3 :
				SelectionReccursion(first);
				display();	   
				break;
			case 4 :
				bubbleSort();
				break;
			case 5 :
				bubbleRecursive(first);
				display();
				break;
			case 6 :
				insertionSort();
				break;
			case 7:
			 	insertionRecursive(first);
				display();
				break;
			case 8:
				linear_search();
				break;
			case 9:
				cout<<"\n Enter value you want to search";
				int s;
				cin>>s;
				linear_recursive(s,first);
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
void selectionSort(){ 
    stu *p=first;	 
    while (p->next!=NULL) { 
        stu* min=p; 
        stu* j=p->next; 
		while (j!=NULL) { 
        	if (min->number>j->number) 
            	min=j; 
				j=j->next; 
        } 
        if(min!=p){
  			int temp=p->number; 
        	p->number=min->number; 
        	min->number=temp; 
		}
		p=p->next;
    }
	display(); 
} 
stu *mini=NULL;
void SelectionReccursion(stu *p){
	if(p==last){
		return;
	}
	else{
		mini=p;
		stu *j=p->next;
		sel(j);
		if(mini!=p){
        	int temp = mini->number;
        	mini->number=p->number;
        	p->number=temp;			
		}
		p=p->next;
		SelectionReccursion(p);	
	}
}
void sel(stu *j){
	if(j==NULL){
		return;
	}
	else if (j->number<mini->number){
		mini=j;
	}
	j=j->next;
	sel(j);
}
void bubbleSort(){
	stu *p=first;
	int check=1;
	while(p->next!=NULL&&check!=0){
		int check=0;
		stu *j=first;
		while(j->next!=NULL){
			if(j->number>j->next->number){
				int temp=j->number;
				j->number=j->next->number;
				j->next->number=temp;
				check=1;	
			}
			j=j->next;
		}
		p=p->next;
	}
	display();
}
int check=1;
void bubbleRecursive(stu *p){
	if(p->next==NULL||check==0){
		return;
	}
	else{
		int check=0;
		stu *j=first;
		bub(j);
	}
	p=p->next;
	bubbleRecursive(p);
}
void bub(stu *j){
	if(j->next==NULL){
		return;
	}
	else if(j->number>j->next->number){
		int temp=j->number;
		j->number=j->next->number;
		j->next->number=temp;
		check=1;	
	}
	j=j->next;
	bub(j);
}
void insertionSort(){
	stu *p=first;
	stu *j=NULL;
	int key;
    while(p->next!=NULL) {  
        j=p;
		p=p->next;
		key=p->number;
		while(j!=NULL&&j->number>key){  
			j->next->number=j->number;  
            if(j==first){
            	j=NULL;
			}	 
			else{
				stu *d=first;
				while(d->next!=j){
					d=d->next;
				}
				j=d;
			}
        }
		if(j==NULL){
			first->number=key;
		} 
		else{
			j->next->number=key;  
		} 
        
    }
	display();  
}

void insertionRecursive(stu *p){
	if(p->next==NULL){
		return;
	}
	else{
		int check=0;
		stu *k=p;
		p=p->next;
		int key=p->number;
		ins(k,key,check);
		insertionRecursive(p);
	}
	
}
void ins(stu *k,int key,int check){
    if(k->number>key&&check==0){
    	k->next->number=k->number;
		if(k==first){
			check==1;
		}
		else{
			stu *d=first;
			inb(d,k);
		}
		ins(k,key,check);	
	}	 
	else{	
		if(check==1){
			first->number=key;
			return;
		} 
		else{
			k->next->number=key;  
			return;
		}   
	}
}
void inb(stu *d,stu *k){
	if(d->next==k){
		k=d;
		return;
	}
	else{
		d=d->next;
		inb(d,k);
	}
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
void linear_search(){
	cout<<"\n Enter value you want to search ";
	int s;
	cin>>s;
	int c=0;
	stu *p=first;
	while(p!=NULL){
		if(p->number==s){
			cout<<"\n found "<<s;
			c=1;
			break;
		}
		p=p->next;
	}
	if(c==0){
		cout<<"\n not found";
	}
}
void linear_recursive(int s,stu *p){
	if(p==NULL){
		cout<<"\n not found";
		return;
	}
	else if(p->number==s){
		cout<<"\n found "<<s;
		return;
	}
	else{
		p=p->next;
		linear_recursive(s,p);
	}
}

