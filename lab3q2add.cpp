#include<iostream>
using namespace std;
class stacks{
    int top,maxsize;
    char s[100];
public:
    stacks()
    {
        top=-1;
        maxsize=100;
    }
    stacks(int a)
    {
        top=-1;
        maxsize=a;
    }
    void push(char);
    char pop();
};
void stacks::push(char i)
{
    if (top==maxsize-1)
        cout<<"Stack full";
    else
    {top++;
    s[top]=i;

    }
}
char stacks::pop()
{
    char ele='a';
    if (top==-1)
    cout<<"Stack empty";
    else
    {
        ele=s[top];
 
        top--;
    }
    return ele;
}
int main()
{
    stacks s1(20);
    int flag=0;
    char c[100];
    cin>>c;
    int i=0;
    while(c[i]!='\0')
    {
        switch(c[i])
        {
            case '(': s1.push('C');
                        break;
            case '{':  s1.push('{');
                        break;   
            case '[': s1.push('[');
                        break;  
            case ']': if(s1.pop()!='[')   
                        {
                            
                            flag=1;
                         
                            
                        }
                        break;
            case '}': if(s1.pop()!='{')   
                        {
                            flag=1;
                       
                            
                        }
                        break;
            case ')': if(s1.pop()!='(')   
                        {
                            flag=1;
                         
                        
                        }
                        break;
        }
        i++;
    }
    if(flag==1)
        cout<<"Matching parenthesis";
    else
        cout<<"Not matching";
}


