#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter no of elements";
    int i,pass,key,gap,a[50],n;
    cin>>n;
    cout<<"Enter elements:";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(pass=1;pass<n;pass++)
    {
        key=a[pass];
        gap=pass;
        while(gap>0 && a[gap-1]>key)
        {
            a[gap]=a[gap-1];
            gap--;
        }
        a[gap]=key;
    }
    cout<<"Sorted"<<"\t";
    for(i=0;i<n;i++)
    {
        cout<<a[i];
        cout<<"\t";
    }
}

