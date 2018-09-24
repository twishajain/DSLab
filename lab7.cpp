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
int main()
{
    SLL k;
    k.ins_end();
    k.ins_end();
    k.ins_end();
    k.display();
    k.ins_before();
    k.display();
    k.ins_after();
    k.display();
    k.delSpecific();
    k.display();
}
