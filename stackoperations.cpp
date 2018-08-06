#include<iostream>
#include<process.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class stack
{
    int top,s[10],maxsize;
    public:
    stack()
    {
    maxsize=10;
    top=-1;
    }
    stack(int size)
    {

        maxsize=size;
        top=-1;
    }
    void push(int x)
    {
        if(top==maxsize-1)
            cout<<"Stack is full";
        else
           {top++;
            s[top]=x;}
    }
    int pop();
    void display();
    int topele();
};
int stack::pop()
{
    int ele=-1;
    if (top==-1)
    {
        cout<<"Stack is Empty";
    }
    else
    {

        ele=s[top];
        top--;
    }
    return ele;
}
void stack::display()
{
    int i;
    cout<<"Stack contents:";
    for(i=top;i>=0;i--)
        cout<<s[i];
}
int stack::topele()
{
    int ele=-1;
    if(top==-1)
        cout<<"Empty Stack";
    else
       ele=s[top];
    return ele;
}
int main()
{
    stack s1(10);
    int option,ele;
    char ch;
    do{
        cout<<"1.push\n2.pop\n3.display\n4.topele\n5.exit\n";
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter the ele:";
                cin>>ele;
                s1.push(ele);
                break;
            case 2:
                ele=s1.pop();
                if(ele!=-1)
                    cout<<"popped ele:"<<ele;
                break;
            case 3:
                s1.display();
                break;
            case 4:
                cout<<s1.topele();
                break;
            case 5:exit(0);
        }
        cout<<"Do you want to continue?";
        cin>>ch;
    }while(ch=='Y' || ch=='y');
    }

