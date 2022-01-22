//Ahmed Ali SP19-BCS-096 section:B
#include <iostream> 
using namespace std; 
void selectionSort(int array[],int n);  
void SelectionReccursion(int array[],int n);
void sel(int array[],int j);
void bubbleSort(int array[],int n);
void bubbleRecursive(int array[],int n);
void bub(int array[],int j);
void insertionSort(int array[],int n);
void insertionRecursive(int array[],int n);
void ins(int array[],int j,int key);
void mergeSort(int array[], int left, int right);
void merge(int array[], int left, int mid, int right);
void array();
void linear_search();
void linear_recursive(int s,int i);
void binary_search();
void binary_recursive(int ss,int left,int right);
void display();
int *arr;
int l;
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
        cout<<"\n 8 - merge sort.";
        cout<<"\n 9 - linear seach with iterations.";
        cout<<"\n 10 - linear seach with recurrsion."; 
        cout<<"\n 11 - binary seach with iterations.";
        cout<<"\n 12 - binary seach with recurrsion.";
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
				SelectionReccursion(arr,0);
				display();	   
				break;
			case 4 :
				bubbleSort(arr,l);
				break;
			case 5 :
				bubbleRecursive(arr,0);
				display();
				break;
			case 6 :
				insertionSort(arr,l);
				break;
			case 7:
			 	insertionRecursive(arr,1);
				display();
				break;
			case 8:
				mergeSort(arr,0,l-1);
				display();
				break;
			case 9:
				linear_search();
				break;
			case 10:
				cout<<"\n Enter value you want to search";
				int s;
				cin>>s;
				linear_recursive(s,0);
				break;
			case 11:
				bubbleRecursive(arr,0);
				binary_search();
				break;
			case 12:
				cout<<"\n Enter value you want to search ";
				int ss;
				cin>>ss;
				bubbleRecursive(arr,0);
				binary_recursive(ss,0,l-1);
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
    for (int i=0; i<n-1; i++){  
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
int mini;
void SelectionReccursion(int array[],int n){

		mini=n;
		int j=n+1;
		sel(array,j);
		if(mini!=n){
        	int temp = array[mini];
        	array[mini]=array[n];
        	array[n]=temp;			
		}
		n++;
		SelectionReccursion(array,n);
	
}
void sel(int array[],int j){

\
		mini=j;
	j++;
	sel(array,j);
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
int check=1;
void bubbleRecursive(int array[],int n){
	if(n==l-1||check==0){
		return;
	}
	else{
		int j=0;
		int check=0;
		bub(array,j);
		n++;
		bubbleRecursive(array,n);
	}
}
void bub(int array[],int j){
	if(j==l-1){
		return ;
	}
	else if(array[j]>array[j+1]){
		int temp=array[j];
		array[j]=array[j+1];
		array[j+1]=temp;
		check=1;
	}
	j++;
	bub(array,j);
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
void insertionRecursive(int array[],int n){
	if(n==l){
		return;
	}
	else{
		int key=array[n];
		int j=n-1;
		ins(array,j,key);
		n++;
		insertionRecursive(array,n);
	}
}
void ins(int array[],int j,int key){
	if(j>=0&&array[j]>key){
		array[j+1]=array[j];
		j--;
		ins(array,j,key);
	}
	else{
		array[j+1]=key;
	}
}

void mergeSort(int array[], int left, int right) { 
    if (right <= left){
	 return;
	}
    int mid = (left+right)/2;
    mergeSort(array, left, mid);
    mergeSort(array, mid+1, right);
    merge(array, left, mid, right);
}
void merge(int array[], int left, int mid, int right){ 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 
  
    int lower[n1], upper[n2]; 
  
  	for (int i=0;i<n1;i++) 
        lower[i] = array[left + i]; 
    for (int j=0;j<n2;j++) 
        upper[j] = array[mid + 1+ j]; 
  	int j = 0; 
	int i = 0; 
    int k = left; 
    while (i < n1 && j < n2){ 
        if (lower[i] <= upper[j]){ 
            array[k] = lower[i]; 
            i++; 
        } 
        else{ 
            array[k] = upper[j]; 
            j++; 
        } 
        k++; 
    }   
    while (i < n1){ 
        array[k] = lower[i]; 
        i++; 
        k++; 
    } 
    while (j < n2){ 
        array[k] = upper[j]; 
        j++; 
        k++; 
    } 
} 
void linear_search(){
	cout<<"\n Enter value you want to search ";
	int s;
	cin>>s;
	int c=0;
	for(int i=0;i<l;i++){
		if(arr[i]==s){
			cout<<"\n found "<<s;
			c=1;
			break;
		}
	}
	if(c==0){
		cout<<"\n not found";
	}
}
void linear_recursive(int s,int i){
	if(i==l){
		cout<<"\n not found";
		return;
	}
	else if(arr[i]==s){
		cout<<"\n found "<<s;
		return;
	}
	else{
		i++;
		linear_recursive(s,i);
	}
}
void binary_search(){
	int left=0;
	int right=l-1;
	cout<<"\n Enter value you want to search ";
	int s;
	cin>>s;
	while(left<=right){
		int a=(right+left)/2;
		if(s==arr[a]){
			cout<<"\n found"<<s;
			break;
		}
		else if(s>arr[a]){
			left=a+1;
		}
		else{
			right=a-1;
		}
	}
	if(left>right){
		cout<<"\n not found";
	}

}
void binary_recursive(int ss,int left,int right){
	int a=(right+left)/2;
	if(left>right){
		cout<<"\n not found";
		return;
	}
	else if(ss==arr[a]){
		cout<<"\n found "<<ss;
		return;
	}
	else if(ss>arr[a]){
		left=a+1;
		binary_recursive(ss,left,right);
	}
	else {
		right=a-1;
		binary_recursive(ss,left,right);
	}
}
