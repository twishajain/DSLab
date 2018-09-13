#include<iostream>
#include<string.h>
using namespace std;

class stack
{
    int top;
    char s[20][20];
    public:
    stack()
    {
        top=-1;
        }
        void push(char*);
        char* pop();
    };
    void stack::push(char* e)
    {
        top++;
        strcpy(s[top],e);
    }
    char* stack::pop()
    {
        if (top==-1)
        return '\0';
        return (s[top--]);
    }
    void post_in()
    {
        stack obj;
        char sym,post[20],oper[20],op1[20],op2[20];
        int i;
        cout<<"Enter postfix expression:";
        cin>>post;
        for (i=0;post[i]!='\0';i++)
        {
            char t1[20],t2[20],t3[20];
            t1[0]=post[i];
            t1[1]='\0';
            if (!isalpha(t1[0]))
            {
                strcpy(op2,obj.pop());
                strcpy(op1,obj.pop());
                strcpy(t2,"(");
                strcat(t2,op1);
                strcat(t2,t1);
                strcat(t2,op2);
                strcat(t2,")");
                obj.push(t2);
            }
            else
            obj.push(t1);
        }
        cout<<"Infix:"<<obj.pop();
    }

int main()
{
    post_in();
}
