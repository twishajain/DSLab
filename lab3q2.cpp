#include<iostream>
#include<string.h>
using namespace std;
class stacks
{
    int s[100],top,maxvalue;
public:
    stacks()
    {
        top=-1;
        maxvalue=100;
    }
    void push(int a)
    {
        if (top==maxvalue-1)
            cout<<"Stack full";
        else
        {
            top++;
            s[top]=a;
        }
    }
    int pop()
    {
        int ele=-1;
        if (top==-1)
            cout<<"Stack is empty";
        else
        {
          ele=s[top];
          top--;
        }
        return ele;
    }

};
int main()
{
    int n,b,rem;
    cout<<"Enter number";
    cin>>n;
    int res=0;
    int mul=1;
    cout<<"Enter base:";
    cin>>b;
    stacks s1;
    while(n>0)
    {
        rem=n%b;
        s1.push(rem);
        n=n/b;
    }
    char f[20];
    while (s1.pop()!=-1)
        f.append(s1.pop());
    cout<<f;
}
