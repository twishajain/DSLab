#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
class stack
{
    char s[100],top,maxsize;
    public:
          stack()
        {
            maxsize=100;top=-1;
        }
        stack(int a)
        {
            maxsize=a;top=-1;
        }
    void push(char a)
    {
        if (top==maxsize-1)
            cout<<"Stack is full";
        else
        {
            top++;
            s[top]=a;
        }
    }
    char pop()
    {
        char ele=-1;
        if (top==-1)
            ele=-1;
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
    char str[100];
    cin.getline(str,100);
    int flag=1;
    stack s1(100);
    for (int i=0;str[i]!='\0';i++)
        s1.push(str[i]);
    for(int i=0;str[i]!='\0';i++)
        if(s1.pop()!=str[i])
        {
            flag=0;
            break;
        }
    if ((flag)&&(s1.pop()==-1))
        cout<<"Pallindrome";
    else
        cout<<"Not pallindrome";


}
