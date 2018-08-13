#include<iostream>
#include<stdlib.h>
using namespace std;
class mstack
{
    int top[10],bottom[10],maxsize;
    int a[100];//stack
public:
    mstack(int m,int n)
    {
        //m is maxsize
        //n is no of stacks
        maxsize=m;
        int i;
        for (i=0;i<n;i++)
            top[i]=bottom[i]=((maxsize/n)*i)-1;
    }
    void push(int,int);
    void pop(int);
    void display(int);
};//class mstack
void mstack::push(int i,int ele)
{
    if ((top[i]==bottom[i+1])|| (top[i]==maxsize-1))
        cout<<i<<"th stack is full";
    else
    {
        top[i]++;
        a[top[i]]=ele;
    }
}
void mstack::pop(int i)
{
    int ele;
    if (top[i]==bottom[i])
        cout<<i<<"th stack is empty";
    else
    {
        ele=a[top[i]];
        top[i]--;
        cout<<"Popped element:"<<ele;
    }
}
void mstack::display(int i)
{
    int j;
    if (top[i]==bottom[i])
        cout<<i<<"th stack is empty";
    else
    {
        cout<<i<<"th stack content";
        for (j=top[i];j>bottom[i];j--)
            cout<<a[j];
    }
}
int main()
{
    int i,option,ele,maxsize,ns;
    char ch;
    cout<<"Enter maxsize";
    cin>>maxsize;
    cout<<"Enter no of stacks";
    cin>>ns;
    mstack m(maxsize,ns);
    do{
        cout<<"Which stack?";
        cin>>i;
        cout<<"1.Push\n 2.Pop\n 3.Display \n 4.Exit";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter the element to be pushed";
            cin>>ele;
            m.push(i,ele);
            break;
        case 2:
            m.pop(i);
            break;
        case 3:
            m.display(i);
            break;
        case 4:
            exit(0);
        default:
            cout<<"Invalid option\n";

        }//switch
        cout<<"Do you want to continue?";
        cin>>ch;

    }while(ch=='Y'||ch=='y');
}//main
