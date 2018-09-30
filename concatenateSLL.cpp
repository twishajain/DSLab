#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Twosingle
{
    int data;
    Twosingle * next;
    Twosingle * prev;

public:
        Twosingle* push(Twosingle *);
        void display(Twosingle *);
        void concatenate(Twosingle *,Twosingle *);
};
Twosingle * first1= NULL;
Twosingle * first2= NULL;

Twosingle* Twosingle::push(Twosingle *p)
{ Twosingle * temp= new Twosingle;
        cin>>temp->data;

    if(p==NULL)
    {


        p=temp;

         p->next=NULL;
        p->prev=NULL;



    }
    else
    {

        Twosingle * curr = new Twosingle;
        for(curr=p;curr->next!=NULL;curr=curr->next);
        curr->next=temp;
        temp->prev=curr;
        temp->next=NULL;
        //cout<<curr->data;
    }

return p;
}
void Twosingle :: display(Twosingle *p)
{
   Twosingle * curr;
    for(curr=p;curr!=NULL;curr=curr->next)
    {
       cout<<curr->data<<"\t";
    }
    cout<<"\n";
}
void Twosingle::concatenate(Twosingle*p,Twosingle*q)
{
    Twosingle * curr = new Twosingle;
    for(curr=p;curr->next!=NULL;curr=curr->next);
    curr->next=q;
    q->prev=curr;
}
int main()
{
    Twosingle f;
int ch;
     for(;;)
     {cout<<"Enter\n1.Add to first list\n2.Display first list\n3.Add to second list\n4.Display second list\n5.concatenate\n6.exit\n";
       cin>>ch;
        switch(ch)
        {
            case 1:
                    first1=f.push(first1);
                    break;
            case 2:

                    f.display(first1);
                    break;
            case 3:
                    first2=f.push(first2);
                    break;
            case 4:

                    f.display(first2);
                    break;
            case 5:
                    f.concatenate(first1,first2);
                    f.display(first1);
                    break;
            case 6:
                    exit(0);
        }}}
