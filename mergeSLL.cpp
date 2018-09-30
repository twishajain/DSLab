#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
using namespace std;
class Single
{
    int data;
    Single *link;
public:
    Single * insertdata(Single *,int);
    void display(Single *);
    void sortdata(Single *);
    void sortdata1(Single *);
    void Merge(Single *, Single *);
    Single *Merge1(Single *, Single *);

};

Single *first1=NULL;
Single *first2=NULL;
Single *first3=NULL;

Single * Single::insertdata(Single * p,int data1)
{
    Single * temp= new Single;
    temp->data=data1;


    if(p==NULL)
    {
        p=temp;
        p->link=NULL;
    }
    else
    {
        Single *curr;
        for(curr=p; curr->link!=NULL; curr=curr->link);
        curr->link=temp;
        temp->link=NULL;
    }

    return p;
}

void Single:: display(Single * p)
{
    Single *curr;
    for(curr = p; curr!=NULL; curr=curr->link)
    {
        cout<<curr->data<<" ";
    }

}

void Single:: sortdata(Single *p)
{
    Single *i= new Single;
    Single *j= new Single;
    for(j=p; j->link!=NULL; j=j->link)
    {
        for(i=j; i->link!=NULL; i=i->link)
            if(j->data>i->data)
            {
                int temp;
                temp=j->data;
                j->data=i->data;
                i->data=temp;
            }
    }
}
void Single:: sortdata1(Single*p)
{
    Single *i= new Single;
    Single *j= new Single;
    int  count1=0;

    for(j=p; j!=NULL; j=j->link)
    {
        for(i=p; i->link!=NULL; i=i->link)
        {
            Single *k=new Single;
            k=i;
            k=k->link;
            if(i->data>k->data)
            {
                int temp;
                temp=k->data;
                k->data=i->data;
                i->data=temp;
            }
        }
    }
}

void Single::Merge(Single * p,Single *q)
{
    Single * curr1= new Single;
    Single * curr2= new Single;
    Single * curr= new Single;
    curr1=p;
    curr2=q;
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data<curr2->data)
        {
            first3=insertdata(first3,curr1->data);
            curr1=curr1->link;
        }
        else if(curr1->data>curr2->data)
        {
            first3=insertdata(first3,curr2->data);
            curr2=curr2->link;
        }
        else
        {
            first3=insertdata(first3,curr2->data);
            curr2=curr2->link;
            curr1=curr1->link;
        }
    }

    for(curr=curr2; curr!=NULL; curr=curr->link)
    {
        first3=insertdata(first3,curr->data);
    }
    for(curr=curr1; curr!=NULL; curr=curr->link)
    {
        first3=insertdata(first3,curr->data);
    }
    display(first3);
}

Single* Single::Merge1(Single * p,Single *q)
{
    Single * curr1= new Single;
    Single * curr2= new Single;
    Single * curr= new Single;
    curr1=p;
    curr2=q;
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data<curr2->data)
        {
            first3=insertdata(first3,curr1->data);
            curr1=curr1->link;
        }
        else if(curr1->data>curr2->data)
        {
            first3=insertdata(first3,curr2->data);
            curr2=curr2->link;
        }
        else
        {
            first3=insertdata(first3,curr2->data);
            curr2=curr2->link;
            curr1=curr1->link;
        }
    }

    for(curr=curr2; curr!=NULL; curr=curr->link)
    {
        first3=insertdata(first3,curr->data);
    }
    for(curr=curr1; curr!=NULL; curr=curr->link)
    {
        first3=insertdata(first3,curr->data);
    }
    display(first3);
}

int main()
{
    Single obj;
    int ch,temp;
    for(;;)
    {
        cout<<"\n1.Add for first list\n2.Display for first list\n3.Add for second list\n4.Display for second list\n5.Merge Method 1\n6.Merge Method 2\n 7.Exit";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nenter the element\n";
            cin>>temp;
            first1=obj.insertdata(first1,temp);
            break;
        case 2:
            obj.display(first1);
            break;
        case 3:
            cout<<"\nenter the element\n";
            cin>>temp;
            first2=obj.insertdata(first2,temp);
            break;
        case 4:

            obj.display(first2);
            break;
        case 5:
            obj.sortdata1(first1);
            obj.sortdata1(first2);
            obj.Merge(first1,first2);
            break;
        case 6:
            obj.sortdata1(first1);
            obj.sortdata1(first2);
            first1=obj.Merge1(first1,first2);
            break;
        case 7:
            exit(0);
        }


    }
}
