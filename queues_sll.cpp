#include<iostream>
using namespace std;
class SLL
{
    int data;
    SLL *link;
public:
    
    void ins_end();
    void display();
    void del_front();
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
void SLL::del_front()
{
    SLL*temp;
    temp=first;
    first=first->link;
    delete temp;
}
void SLL::display()
{
    SLL *i;
    for (i=first;i!=NULL;i=i->link)
        cout<<i->data;

}
int main()
{
    SLL k;
    int option;
    char ch;
    do{
    cout<<"1.Insert 2.Delete 3.Display";
    cin>>option;
    switch(option)
    {
        case 1: k.ins_end();break;
        case 2:k.del_front();break;
        case 3:k.display();break;
        
    }
    cout<<"Do you want to continue?";
    cin>>ch;

}while (ch=='y'|| ch=='Y');
}


