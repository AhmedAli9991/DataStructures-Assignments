//Made by Ahmed Ali (SP19-BCS-096)
#include <iostream> 
using namespace std; 
void insertion_iterative();
void insertion_recursive();
void search_iterative();
void search_recursive();
void deletion();
struct BST{
	int number;
	BST *left=NULL;
	BST *right=NULL;
};
void postorder(BST *p);
void inorder(BST *pointer);
void preorder(BST *p);
void inre(BST *x,BST *y,BST* z);
void sre(int i,BST *x);
BST *Root=NULL;
int main() {
	int opt;
	do{
		cout<<"\n Enter 1 for insertion by iteration  ";
		cout<<"\n Enter 2 for insertion by recursion ";
		cout<<"\n Enter 3 to search by iteration  ";
		cout<<"\n Enter 4 to search by recursion ";
		cout<<"\n Enter 5 for inorder traversal ";
		cout<<"\n Enter 6 for preorder traversal ";
		cout<<"\n Enter 7 for postorder traversal ";		
		cout<<"\n Enter 8 to delete";
		cout<<"\n Enter 0 to exit";
		cout<<"\n Enter your option: ";
		cin>>opt;
	switch(opt)
	{
		case 0:
		break;
		case 1: insertion_iterative();
		break;
		case 2: insertion_recursive();
		break;
		case 3: search_iterative();
		break;
		case 4: search_recursive();
		break;
		case 5: inorder(Root);
		break;
		case 6 :preorder(Root);
		break;
		case 7: postorder(Root);
		break;
		case 8: deletion();
		break;
		default:
			cout<<"\n Wrong option";
		}	
	}while(opt!=0);

	return 0;
}

void insertion_iterative(){
	BST *curr;
	curr=new BST;
	cout<<"\n insert value: ";
	cin>>curr->number;
	if(Root==NULL){
		Root=curr;
	}
	else{
		BST *p=Root;
		BST *k=NULL;
		while(p!=NULL){
			k=p;
			if(curr->number>p->number){
				p=p->right;
			}
			else{
				p=p->left;
			}
		}
		if(curr->number>k->number){
			k->right=curr;
		}
		else{
			k->left=curr;
		}
	}
}
void insertion_recursive(){
	BST *curr;
	curr=new BST;
	cout<<"\n insert value: ";
	cin>>curr->number;
	if(Root==NULL){
		Root=curr;
	}
	else{
		BST *p=Root;
		BST *k=NULL;
		inre(p,k,curr);
	}
}
void inre(BST *x,BST *y,BST *z){
	if(x==NULL){
		if(z->number>y->number){
			y->right=z;
		}
		else{
			y->left=z;
		}		
		return;
	}
	else{
		y=x;
		if(z->number>x->number){
			x=x->right;
		}
		else{
			x=x->left;
		}
		inre(x,y,z);
	}	
}
void search_iterative(){
	cout<<"\n Enter value you want to search in BST: ";
	int id;
	cin>>id;
	BST*p=Root;
	int check=0;
	while(p!=NULL){
		if(id==p->number){
			cout<<"\n found "<<id;
			check=1;
			break;
		}
		else{
			if(id>p->number){
				p=p->right;
			}
			else{
				p=p->left;
			}
		}
	}
	if(check==0){
		cout<<"\n "<<id<<" not found";
	}
}
void search_recursive(){
	cout<<"\n Enter value you want to search in BST: ";
	int id;
	cin>>id;
	BST*p=Root;
	sre(id,p);
}
void sre(int i,BST *x){
	if(i==x->number){
		cout<<"\n found "<<i;
		return;
	}
	else{
		if(i>x->number){
			x=x->right;
		}
		else{
			x=x->left;	
		}
		if(x==NULL){
			cout<<"\n "<<i<<" not found";
			return;
		}
        else{
			sre(i,x);
		}
	}
}
void inorder(BST *pointer){
    if (pointer!=NULL){
  		inorder(pointer->left); 
  		cout << pointer->number << " "; 
 		inorder(pointer->right); 
 	}
 	else{
 		return;
	 }
}
void preorder(BST* p) 
{ 
    if (p!=NULL) {
  		cout << p->number << " "; 
  		preorder(p->left);  
  		preorder(p->right);
	}
  	else{
  		return;
	}
}  
void postorder(BST *p){
   if (p!=NULL) {
    	postorder(p->left); 
   	 	postorder(p->right); 
	    cout << p->number << " "; 	
	}
	else{
		return;
	}
}
void deletion(){
	cout<<"\n Enter value which you want to delete ";
	int id;
	cin>>id;
	BST* p=Root;
	BST* k=NULL;
	int check=0;
	while(p!=NULL){
		if(id==p->number){
			check=1;
			break;
		}
		else{
			k=p;
			if(id>p->number){
				p=p->right;
			}
			else{
				p=p->left;
			}
		}
	}
	if(check==0){
		cout<<"\n "<<id<<" not found";
	}
	else if(check==1&&k==NULL){
		if(p->left==NULL&&p->right==NULL){
			Root=NULL;
			delete p;
		}
		else if(p->left==NULL||p->right==NULL){
			if(p->left==NULL){
				Root=p->right;
				delete p;
			}
			else if(p->right==NULL){
				Root=p->left;
				delete p;
			}
		}
		else{
			BST *d=Root;
			BST *dp=d;
			d=d->right;
			while(d->left!=NULL){
				dp=d;
				d=d->left;
			}
			if(dp==p){
				d->left=p->left;
				Root=d;
				delete p;
			}
			else{
				d->left=p->left;
				dp->left=NULL;
				Root=d;
				delete p;
			}	
		}
	}
	else {
		int lr=0;
		if(k->left==p){
			lr=1;
		}
		if(p->left==NULL&&p->right==NULL){
			if(lr==0){
				k->right=NULL;
				delete p;
			}
			else if(lr==1){
				k->left=NULL;
				delete p;
			}				
		}
		else if(p->left==NULL||p->right==NULL){
			if(p->left==NULL){
				if(lr==0){
					k->right=p->right;
					delete p;
				}
				else if(lr==1){
					k->left=p->right;
					delete p;
				}
			}
			if(p->right==NULL){
				if(lr==0){
					k->right=p->left;
					delete p;
				}
				else if(lr==1){
					k->left=p->left;
					delete p;
				}
			}			
		}
		else{
			BST *d=p;
			BST *dp=NULL;
			while(d->left!=NULL){
				dp=d;
				d=d->left;
			}
			if(lr==0){
				k->right=d;
				if(dp!=p){
					dp->left=NULL;
				}
				delete p;
			}
			else if(lr==1){
				k->left=d;
				if(dp!=p){
					dp->left=NULL;
				}
				delete p;
			}
		}
	}
}
