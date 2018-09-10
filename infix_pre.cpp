#include <iostream>
#include <string.h>
#include<stdlib.h>
using namespace std;
class stackss{
    char a[50];
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
    char pop()
    {
        char e;
        if (!isempty()){
        e= a[top];
        top--;
        return e;}

    }
    char push(char g)
    {
        if (!isfull()){
        top++;
        a[top]=g;}
    }
    char topele()
    {
        return a[top];
    }
    void display()
    {
        for (int i=top;i>=0;i--)
        cout<<a[i];
    }
};
int icp[]={20,19,12,12,13,13,13,0};
int isp[]={0,19,12,12,13,13,13,0};
enum precedence{lparen,rparen,pluss,minuss,times,divide,mod,eos,operand};
precedence gettoken(char c)
{
    switch(c)
    {
        case '(': return lparen; break;
        case ')': return rparen;break;
        case '+':return pluss;break;
        case '-':return minuss;break;
        case '*':return times;break;
        case '/':return divide;break;
        case '%':return mod; break;
        default:return operand;
    }
}
void postfix(char *infix)
{

    precedence temp;
    int i=0;
    stackss s;
    stackss l;
    while (infix[i]!='\0')
    {

        temp=gettoken(infix[i]);
        if (temp==operand)
        l.push(infix[i]);
        else if (temp==rparen)
        {
            while (gettoken(s.topele())!=lparen)
            l.push(s.pop());
            char c=s.pop();
        }
        else
        {
            if (s.isempty()==1)
                s.push(infix[i]);
            else
                {
                    while(s.isempty()==0 && icp[temp]<=isp[gettoken(s.topele())])
                    l.push(s.pop());
                    s.push(infix[i]);
                }
        }
        i++;
    }
    while (!s.isempty())
    l.push(s.pop());
    l.display();
}
      int main()
      {
          cout<<"Enter string";
          char exp[50];
          cin.getline(exp,50);

          postfix(strrev(exp));
      }
