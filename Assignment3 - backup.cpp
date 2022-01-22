#include <iostream> 
using namespace std; 
void selectionSort(int array[],int n);  
void SelectionReccursion(int ind);
void bubbleSort(int array[],int n);
void bubbleRecursive(int array[],int ind);
void insertionSort(int array[],int n);
void insertionRecursive();
void mergeSort(int array[],int n);
void mergeRecursive();
void array();
void display();
int *arr;
int l;
int index=0;
int Bindex;
int in;
int mini=index;
int main()  
{  	
    int choice;
	do
    {

        cout<<"\n 1 - intialize an array(must be done before other functions are utilized).";
        cout<<"\n 2 - selection sort with iterations.";
        cout<<"\n 3 - selection sort with recurrsion.";
        cout<<"\n 4 - bubble sort with iterations.";
        cout<<"\n 5 - bubble sort with recurrsion."; 
        cout<<"\n 6 - insertion sort with iterations.";
        cout<<"\n 7 - insertion sort with recurrsion.";
        cout<<"\n 8 - merge sort with iterations.";
        cout<<"\n 9 - merge sort with recurrsion."; 
        cout<<"\n 0 - Exit.";
        cout<<"\n Enter your choice: ";
        cin>>choice;
	
        switch(choice){
            case 0:
				break;
			case 1:
				array();
				break;
			case 2:
				selectionSort(arr,l);
				break;
			case 3 :
				SelectionReccursion(index);
				display();	   
				break;
			case 4 :
				bubbleSort(arr,l);
				break;
			case 5 :
				bubbleRecursive(arr,index);
				display();
				break;
			case 6 :
				insertionSort(arr,l);
				break;
		}	
	}while(choice!=0);
	return 0;  
}  
void array()
{
	cout<<"\n Enter size of array: ";
	int m;
	cin>>l;
	arr=new int[l];
	
	in=Bindex;
	for(int i=0;i<l;i++){
		cout<<"\n Enter element in array: ";
		int e;
		cin>>e;
		arr[i]=e;
	}
	display();
}
void display(){
	cout<<"\n";
	for(int i=0;i<l;i++){
		cout<<arr[i]<<" ";
	}
}
void selectionSort(int array[],int n)  
{  
    for (int i=0; i<n-1; i++)  
    {  
        int min = i;  
        for (int j=i+1; j < n; j++){
        	if (arr[j] < arr[min])  
            	min=j;  
        }
        if(min!=i){
        	int temp = array[min];
        	array[min]=array[i];
        	array[i]=temp;
		}
  }
  display();  
}
void SelectionReccursion(int ind){
	int i=ind;
	if(ind==l-1)
		return;
	else if(in!=index){
		if(arr[i]<arr[mini])
			int mini=i;	
		in++;
		SelectionReccursion(in);		
	}
	else{
		if(arr[i]<arr[mini])
			int mini=i;	
		in++;
		SelectionReccursion(in);
		if(mini!=i){
			int temp = arr[mini];
        	arr[mini]=arr[i];
        	arr[i]=temp;
		}
		index++;
		in=index;
		SelectionReccursion(index);	
			
	}
}
void bubbleSort(int array[],int n){
	for(int i=0;i<n-1;i++){
		int check=0;
		for(int j=0;j<n-1-i;j++){
			if(array[j]>array[j+1]){
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
				check=1;	
			}
		}
		if(check==0)
			break;
	}
	display();
}
void bubbleRecursive(int array[],int ind){
	if(ind==l-1){
		index++;
		return;
	}
	else{
		if(array[ind]>array[ind+1]){
				int temp=array[ind];
				array[ind]=array[ind+1];
				array[ind+1]=temp;
				index=0;
		}
		int i=ind+1;
		if(i<l){
			bubbleRecursive(array,i);
			}
		if(index!=l-1){
			bubbleRecursive(array,index);
		}	
	}
}
void insertionSort(int array[],int n){
	int key;
    for (int i=1;i<n;i++) {  
        key=array[i];
		int j=i-1;  
 	    while(j>=0&&array[j]>key){  
            array[j+1]=array[j];  
            j--;  
        }  
        array[j+1]=key;  
    }
	display();  
}
