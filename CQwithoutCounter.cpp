#include<iostream>
#include<stdlib.h>
using namespace std;
class CQempty
{
    int f,r,Q[100],maxsize;
    public:
    CQempty()
    {
        f=r=0;
        maxsize=10;
    }
    CQempty(int size)
    {
        f=r=0;
        maxsize=size;
    }
    void CQadd(int);
    void CQdel();
    void CQdisplay();
};
void CQempty::CQadd(int ele)
{
    if (f==(r+1)%maxsize)
        cout<<"CQ is full";
    else
    {
        r=(r+1)%maxsize;
        Q[r]=ele;
    }
}
void CQempty::CQdel()
{
    if (f==r)
        cout<<"CQ is empty";
    else
    {
        f=(f+1)%maxsize;
        cout<<"Deleted element:"<<Q[f];
    }
}
void CQempty::CQdisplay()
{
    int i;
    if (f==r)
        cout<<"CQ empty";
    else{
    for (i=(f+1)%maxsize;i!=(r+1)%maxsize;i=(i+1)%maxsize)
    {
        cout<<Q[i];
    }}
}
int main()
{
    CQempty q1(10);
     int option,ele;
     char ch;
     do{
        cout<<"1.Insertion/n2.Deletion/n3.Display/n4.Exit";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter the element:";
            cin>>ele;
            q1.CQadd(ele);
            break;
        case 2:
            q1.CQdel();
            break;
        case 3:
            q1.CQdisplay();
            break;
        case 4:
            exit(0);
        default:
            cout<<"Invalid entry";
        }
        cout<<"Do you want to continue?";
        cin>>ch;

     }while(ch=='y'|| ch=='Y');
}
