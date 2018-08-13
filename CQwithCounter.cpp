#include<iostream>
#include<stdlib.h>
using namespace std;
class CQ
{
    int f,r,counter,Q[100],maxsize;
public:
    CQ(int size)
    {
        f=r=-1;
        counter=0;
        maxsize=size;
    }
    void CQins(int);
    void CQdel();
    void display();
};
void CQ::CQins(int ele)
{
    if (counter==maxsize)
        cout<<"CQ is full";
    else
    {
        r=(r+1)%maxsize;
        Q[r]=ele;
        counter++;
    }
}
void CQ::CQdel()
{
    if(counter==0)
        cout<<"CQ is empty";
    else
    {
        f=(f+1)%maxsize;
        cout<<"Deleted ele:"<<Q[f];
        counter--;
    }
}
void CQ::display()
{
    if (f==r)
        cout<<"Queue is empty";
    else {
    int i=f,c=counter;
    cout<<"Elements are:";
    while (c>0)
        {
            i=(i+1)%maxsize;
            cout<<Q[i];
            c--;
        }}

}
int main()
{
     CQ q1(10);
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
            q1.CQins(ele);
            break;
        case 2:
            q1.CQdel();
            break;
        case 3:
            q1.display();
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
