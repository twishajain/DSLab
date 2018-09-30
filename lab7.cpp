#include<iostream>
using namespace std;
class SLL
{
    int data;
    SLL *link;
public:
    void ins_before();
    void ins_end();
    void display();
    void ins_after();
    void delSpecific();
    void reversing();
    void sortt();
    void delalternate();
    void inssorted();
};
SLL *first=NULL, *last=NULL;
void SLL::ins_end()
{
    SLL *temp=new SLL;
    cout<<"Enter node data:";
    cin>>temp->data;
    temp->link=NULL;
    if (first==NULL)
    {
        first=temp;
    }
    else
    {
        SLL *curr;
        for (curr=first;curr->link!=NULL;curr=curr->link);
        curr->link=temp;
    }
}
void SLL::delalternate()
{
    SLL *p,*n;

    if (first==NULL)
        cout<<"list empty";
    else if (first->link==NULL)
        {cout<<"only one element list remains same";
        }
    else
        {
            p=first;
            n=p->link;
            while (p!=NULL && n!=NULL)
            {
                p->link=n->link;
                delete n;
                p=p->link;
                if (p!=NULL)
                    n=p->link;
            }

        }


}
void SLL::display()
{
    SLL *i;
    for (i=first;i!=NULL;i=i->link)
        cout<<i->data;

}

void SLL::ins_before()
{
    SLL *temp=new SLL;
    cout<<"Enter node data of node before which you wish to ins:";
    int h;
    cin>>h;
    cout<<"Enter new node data:";
    cin>>temp->data;
    temp->link=NULL;
    if (first==NULL)
    {
        cout<<"list empty";
    }
    else if (h==first->data)
    {
        temp->link=first;
        first=temp;
    }
    else
    {
        SLL *curr,*prev;
        for (curr=first;curr->data!=h;curr=curr->link)
            prev=curr;
        temp->link=prev->link;
        prev->link=temp;
    }
}

void SLL::ins_after()
{
    SLL *temp=new SLL;
    cout<<"Enter node data of node after which you wish to ins:";
    int h;
    cin>>h;
    cout<<"Enter new node data:";
    cin>>temp->data;
    temp->link=NULL;
    if (first==NULL)
    {
        cout<<"list empty";
    }
    else
    {
        SLL *curr,*next;
        for (curr=first;curr->data!=h;curr=curr->link);
        temp->link=curr->link;
        curr->link=temp;
    }
}

void SLL::delSpecific()
{
    int val,flag=0;
    cout<<"Enter val to be deleted";
    cin>>val;
    if (first==NULL)
        cout<<"Empty list";
    else
    {
        if (first->data==val)
        {
            SLL *t=first;
            first=first->link;
            delete t;flag=1;
        }
        else
        {
            SLL *c,*prev;

            for (c=first;c!=NULL;c=c->link)
            {
                if(c->data==val)
                {
                    prev->link=c->link;
                    delete c;flag=1;break;
                }
                prev=c;
            }
        }
        if (flag==0)
        {
            cout<<"Element not in list";
        }
    }
}
void SLL::reversing()
{
    SLL *curr,*prev;
    curr=prev=NULL;
    while (first!=NULL)
    {
        prev=curr;
        curr=first;
        first=first->link;
        curr->link=prev;
    }
    first=curr;
}
void SLL::inssorted()
{
    SLL *prev,*curr;
    SLL *temp=new SLL;
    cout<<"Enter no to be inserted";
    cin>>temp->data;
    temp->link=NULL;
    if (first==NULL)
    {first=temp; return;}
    else if (temp->data<first->data)
    {
        temp->link=first;
        first=temp;
        return;
    }
    else
    {
        prev=first;curr=prev->link;
        while (curr)
        {
            if (temp->data>prev->data && temp->data<curr->data)
            {
                temp->link=curr;
                prev->link=temp;
                return;
            }
            prev=curr->link;
            curr=prev->link;
        }
        prev->link=temp;
        return;
    }
}


void SLL::sortt()
{
    SLL *i,*j;int temp;
    for (i=first;i->link!=NULL;i=i->link)
    {
        for (j=i->link;j!=NULL;j=j->link)
        {
            if (i->data>j->data)
            {
                temp=i->data;i->data=j->data;
                j->data=temp;
            }
        }
    }
}
int main()
{
    SLL k;
    int option;
    char ch;
    do{
    cout<<"1.Insert_end 2.Insert_before 3.Insert_after 4.Reverse 5.Delete 6.Sort 7.Display 8.DelAlternate 9.Inssorted";
    cin>>option;
    switch(option)
    {
        case 1: k.ins_end();break;
        case 2:k.ins_before();break;
        case 3:k.ins_after();break;
        case 4:k.reversing();break;
        case 5:k.delSpecific();break;
        case 6:k.sortt();break;
        case 7:k.display();break;
        case 8:k.delalternate();break;
        case 9:k.inssorted();break;
    }
    cout<<"Do you want to continue?";
    cin>>ch;

}while (ch=='y'|| ch=='Y');
}

