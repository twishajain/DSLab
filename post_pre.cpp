#include <iostream>
#include<string.h>
using namespace std;
class stack
{
    char s[20][20];
    int top;
public:
    stack()
    {
        top=-1;}

    char* pop();
    void push(char []);
};
void stack::push(char e[])
{
    top++;
    strcpy(s[top],e);}
char* stack::pop()
    {
        if (top==-1)
            return "X";
        return (s[top--]);
    }
    void post_pre()
        {
            stack obj;
            char sym,post[20],oper[20],op1[20],op2[20];
            int i;
            cout<<"Enter postfix";
            cin>>post;
            for (i=0;post[i]!='\0';i++)
            {
                char t1[20],t2[20],t3[20];
                t1[0]=post[i];t1[1]='\0';
                if (t1[0]=='+'||t1[0]=='-'||t1[0]=='*'||t1[0]=='/')
                {
                    strcpy(op1,obj.pop());
                    strcpy(op2,obj.pop());
                    strcpy(t2,t1);
                    strcat(t2,op2);
                    strcat(t2,op1);
                    obj.push(t2);
                }
                else
                    obj.push(t1);
            }
            strcpy(oper,obj.pop());
            cout<<oper;
        }
        int main()
        {
            post_pre();

        }

