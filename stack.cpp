#include<iostream>

using namespace std;

class STACK
{
    private:
        int *num;
        int top;
        int size;
    public:
        STACK();    //defualt constructor
        void push();
        bool isEmpty();
        bool isFull();
        void displayItems();
        STACK(int s);
        void pop(){
            //to store and print which number
            //is deleted
            int temp;
            //check for empty
            if(isEmpty())
                cout<<"\n List is already emepty ";
                    else{
            temp=num[top];
            --top;
            cout<<"\n Poped value is:  "<<temp;
                    }
        }
};
STACK::STACK(){
    top=-1;
    size=5;
    num = new int[size];
}

STACK::STACK(int s){
    top=-1;
    size=s;
    num = new int[size];
}

bool STACK::isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}

bool STACK::isFull(){
    if(top==(size-1))
        return true;
    else
        return false;
}

void STACK::push(){
    //check stack is full or not
    if(isFull()){
        cout<<"\n Stack is already full";
    }else{
        int ele;
        cout<<"\n Enter element: ";
        cin>>ele;
    ++top;
    num[top]=ele;
}
}

void STACK::displayItems(){
    int i; //for loop
    cout<<"STACK is: ";
    for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
    cout<<endl;
}

int main(){
    //declare object
    STACK stk(5);   //Here we pass the size of stack
    STACK s;    //default constructor call
    int choice, n,temp;

    do
    {
        cout<<endl;

        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items (Print STACK)."<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 0: break;

            case 1:

               stk.push();
            break;

            case 2:
               stk.pop();

            break;

            case 3:
                stk.displayItems();
                break;

            default:
                cout<<"An Invalid choice."<<endl;
        }
    }while(choice!=0);


    return 0;

}

