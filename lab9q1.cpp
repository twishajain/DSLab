#include<iostream>
using namespace std;

class CDLL
{
    int data;
    CDLL *link;
    CDLL *prev;
public:
    void insEnd();
    void delEnd();
    void display();
};
CDLL *cf=NULL;
void CDLL::insEnd()
{
    CDLL *temp=new CDLL;
    cout<<"Enter data";
    cin>>temp->data;
    if (cf==NULL)
    {
        cf=temp;
        cf->link=cf;
        cf->prev=cf;
    }
    else
    {
        CDLL *c;
        for (c=cf;c->link!=cf;c=c->link);
        temp->link=cf;
        cf->prev=temp;
        c->link=temp;
        temp->prev=c;
    }
}
void CDLL::delEnd()
{
    int x;
    cout<<"Enter element to be deleted";
    cin>>x;
    if (cf==NULL)
    {
        cout<<"CDLL is empty";return;
    }
    else if (cf->data==x&&cf->link!=cf)
    {
        CDLL *temp=cf;
        cf->prev->link=cf->link;
        cf->link->prev=cf->prev;
        cf=cf->link;
        delete temp;return;
    }
else if (cf->data==x)
{delete cf;cf=NULL;return;}

    else
    {
        CDLL *c;
        for (c=cf->link;c!=cf;c=c->link)
        {
            if (c->data==x)
            {

                c->prev->link=c->link;
                c->link->prev=c->prev;
                delete c;return;
            }
        }
    }
cout<<"Ele not found";

}
void CDLL::display()
{
if (cf==NULL) {cout<<"Empty list";return;}
    CDLL *i;
    for (i=cf;i->link!=cf;i=i->link)
        cout<<i->data;
    cout<<i->data;
}
int main()
{
    CDLL k;
    int option;
    char ch;
    do{
    cout<<"1.InsertEnd 2.Delete 3.Display";
    cin>>option;
    switch(option)
    {
        case 1: k.insEnd();break;
        case 2:k.delEnd();break;
        case 3:k.display();break;

    }
    cout<<"Do you want to continue?";
    cin>>ch;

}while (ch=='y'|| ch=='Y');
}

