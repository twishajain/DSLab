#include <iostream>
#include <string.h>
#include<stdlib.h>
using namespace std;
class stackss{
    int a[50];
    int top;
    int maxsize;
    public:
    stackss()
    {
        top=-1;
        maxsize=20;
    }
    bool isempty()
    {
        if (top==-1)
        {
            return true;
        }
        else 
        return false;
    }
    bool isfull()
    {
        if (top==maxsize-1)
        return true;
        else 
        return false;
    }
    int pop()
    {
        int e;
        if (!isempty()){
        e= a[top];
        top--;
        return e;}
        
    }
    void push(int g)
    {
        if (!isfull()){
        top++;
        a[top]=g;}
    }
    int topele()
    {
        return a[top];
    }
    void display()
    {
        for (int i=top;i>-1;i--)
        cout<<a[top];
    }
};
void postfix_eval()
{
    stackss s;
    int op1,op2,i,j,val;
    char symbol,postfix[20];
    cout<<"Enter string:";
    cin.getline(postfix,20);
    for (i=strlen(postfix)-1;i>=0;i--)
    {
        symbol=postfix[i];
        if (symbol>=48 && symbol<=57)
        {
            val=symbol-48;
            s.push(val);
        }
        else if (symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='%')
        {
            op1=s.pop();
            op2=s.pop();
            switch(symbol)
            {
                case '+': s.push(op1+op2);break;
                case '-':s.push(op1-op2);break;
                case '*':s.push(op1*op2);break;
                case '/':s.push(op1/op2);break;
                case '%':s.push(op1%op2);break;
            }
        }
        else
        {
            cout<<"Enter the value of:"<<symbol;
            cin>>val;
            s.push(val);
        }
    }
    cout<<s.topele();
}

            
        

      int main()
      {
          postfix_eval();
      }

